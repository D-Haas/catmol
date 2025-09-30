#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <glob.h>
#include "./window/window.h"
#include "./xyz/xyz.h"
#include "./customization/customization.h"
#include "./opts/opts.h"

int setup()
{
  // Set locale to show special characters
  setlocale(LC_ALL, "");

  // Init screen for ncurses
  initscr();

  // Turn on noecho mode
  if (noecho())
  {
    printf("Could not use noecho mode, something's wrong");
    return 1;
  }

  // Enable keypad (function keys)
  if (keypad(stdscr, TRUE))
  {
    printf("Keypad function couldn't be initialized");
    return 1;
  }

  // Check if terminal has colors
  if (!has_colors() || start_color())
  {
    printf("Error when starting colors module, does your terminal has support for it?");
    return 1;
  }
  if (COLORS<256)
  {
    printf("Your terminal is not compatible with the \"xterm-256color\" option");
    return 1;
  }
  setup_colors();

  raw();


  return 0;
}

typedef struct {
  size_t length;
  Structure *items;
  bool success;
} ImportResult;

ImportResult import_files(size_t len_args, char **args)
{
  /*
   * Return an array of structures from all
   * arguments given in the command line
  */
  ImportResult result;
  result.success = false;

  int total_length = 0;


  for (size_t i = 1; i < len_args; i++)
  {
    // Get results from glob search
    glob_t glob_result;
    int glob_return = glob(args[i], GLOB_TILDE, NULL, &glob_result);
    
    // Catch possible errors that might happen
    if (glob_return == GLOB_NOSPACE)
    {
      globfree(&glob_result);
      printf("Error during result parsing, ran out of memory\n");
      return result;
    }
    else if (glob_return == GLOB_ABORTED)
    {
      globfree(&glob_result);
      printf("Error during result parsing, read error\n");
      return result;
    }
    else if (glob_return == GLOB_NOMATCH)
    {
      globfree(&glob_result);
      printf("Error during result parsing, no matches\n");
      return result;
    }
    total_length+= glob_result.gl_pathc;
  }

  // Assign structures array
  Structure *structures = (Structure*) calloc(total_length, sizeof(Structure));

  // Fill array with structures for each file
  size_t global_counter = 0;
  // For each argument given in the terminal
  for (size_t i = 1; i < len_args; i++)
  {
    glob_t glob_result;
    glob(args[i], GLOB_TILDE, NULL, &glob_result);
    // For each file that fits the pattern for this argument
    for (size_t j = 0; j < glob_result.gl_pathc; j++)
    {
      // Create structure and put it in the structures array
      string file_path = string(glob_result.gl_pathv[j]);
      Structure structure = Structure(file_path);
      structures[global_counter++] = structure;
    }
    // Free glob search result
    globfree(&glob_result);
  }

  // Put items on array
  result.length  = total_length;
  result.items   = structures;
  result.success = true;


  // Return import result
  return result;
}

WINDOW *top_tab, *bottom_tab;
void create_hud()
{

  // Assign window pointers
  top_tab = newwin(LINES-3, COLS, 0, 0);
  bottom_tab = newwin(3, COLS, LINES-3, 0);

  // Set border styles
  wborder(top_tab, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
  wborder(bottom_tab, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

  // Set window variables for molecule drawing
  update_window_size(top_tab);

  // Reset screen z-axis values
  clean_map();

  // Refresh, cause why not
  wrefresh(top_tab);
  wrefresh(bottom_tab);
  refresh();
}


int main(i32 argc, char **argv)
{
  // Return if not enough arguments were given
  if (argc<2)
  {
    printf("Not enough arguments were given\n");
    return 1;
  }

  // Checks if special option is listed
  Opt opt = check_opts(argc, argv);
  switch (opt)
  {
    case VERSION:
    print_version();
    return 0;

    case HELP:
    print_help();
    return 0;

    case NONE:
    // Nothing happens
    break;
  }

  // Import structures from arguments
  ImportResult import_result = import_files(argc, argv);
  if (!import_result.success)
    return 1;

  // Assign result variables
  i32 structures_length = import_result.length;
  i32 actual_structure_id = 0;
  Structure *molecules = import_result.items;



  // Do setup and catch some startup errors
  if (setup()) return 1;

  // Create the window layout for top and bottom tabs
  create_hud();

  // Scale molecules to current tab size
  for (int i = 0; i < structures_length; i++)
  {
    molecules[i].scale(top_tab);
  }

  int ch = '\0';
  do {
    werase(top_tab);
    wclear(bottom_tab);
    clean_map();

    // Process inputs
    switch (ch) {
      /////////////////////
      // ROTATION INPUTS //
      /////////////////////
      case 'h':
        molecules[actual_structure_id].rotate_y(-M_PI/8);
        break;
      case 'l':
        molecules[actual_structure_id].rotate_y( M_PI/8);
        break;
      case 'j':
        molecules[actual_structure_id].rotate_x(-M_PI/8);
        break;
      case 'k':
        molecules[actual_structure_id].rotate_x( M_PI/8);
        break;
      ///////////////////////
      // TAB CHANGING KEYS //
      ///////////////////////
      case 'H':
        if (--actual_structure_id < 0)
          actual_structure_id = structures_length-1;
        break;
      case 'L':
        if (++actual_structure_id >= structures_length)
          actual_structure_id = 0;
        break;
      ////////////////////////
      // MODE CHANGING KEYS //
      ////////////////////////
      case 'r':
        change_radius_mode();
        break;
      case 'b':
        change_bonding_mode();
        break;
    } 


    // Set radius mode to be shown
    char radius_mode_ch;
    switch (radius_mode)
    {
      case REDUCED:
        radius_mode_ch = 'R';
        break;
      case SIMPLIFIED:
        radius_mode_ch = 'S';
        break;
      case ACCURATE:
      default:
        radius_mode_ch = 'A';
        break;
    }

    // Set bonding mode to be shown
    char bonding_mode_ch;
    switch (bonding_mode)
    {
      case FILL:
        bonding_mode_ch = 'F';
        break;
      case DOTTED:
      default:
        bonding_mode_ch = 'D';
        break;
    }
    
    // Print radius and bonding modes on bottom tab
    mvwprintw(
      bottom_tab,
      1, 
      1,
      "Radius mode: %c | Bonding mode: %c",
      radius_mode_ch, bonding_mode_ch
    );

    // Draws molecule on toptab
    molecules[actual_structure_id].draw(top_tab);

    // Draw borders
    box(top_tab, 0, 0);
    box(bottom_tab, 0, 0);

    // Print xyz filename of current molecule
    mvwprintw(
      top_tab,
      0, 3,
      "%s",
      molecules[actual_structure_id].name.c_str()
    );

    // Refresh screens
    wrefresh(bottom_tab); wrefresh(top_tab);
    refresh();
  // Exit if 'q' is pressed
  } while((ch = getch()) != 'q');

  // Close window
  endwin();

  // Remove allocated memory
  free(molecules);

  return 0;
}
