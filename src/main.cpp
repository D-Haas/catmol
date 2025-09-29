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

int setup()
{
  setlocale(LC_ALL, "");

  initscr();

  if (noecho())
  {
    printf("Could not use noecho mode, something's wrong");
    return 1;
  }

  if (keypad(stdscr, TRUE))
  {
    printf("Keypad function couldn't be initialized");
    return 1;
  }

  if (!has_colors() || start_color())
  {
    printf("Error when starting colors module, does your terminal has support for it?");
    return 1;
  }
  setup_colors();

  raw();

  update_window_size(stdscr);
  clean_map();


  return 0;
}

typedef struct {
  size_t length;
  Structure *items;
  bool success;
} ImportResult;

ImportResult import_files(size_t len_args, char **args)
{
  ImportResult result;
  result.success = false;

  int total_length = 0;


  for (size_t i = 1; i < len_args; i++)
  {
    glob_t glob_result;
    int glob_return = glob(args[i], GLOB_TILDE, NULL, &glob_result);
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

  Structure *structures = (Structure*) calloc(total_length, sizeof(Structure));

  size_t global_counter = 0;
  for (size_t i = 1; i < len_args; i++)
  {
    glob_t glob_result;
    glob(args[i], GLOB_TILDE, NULL, &glob_result);
    for (size_t j = 0; j < glob_result.gl_pathc; j++)
    {
      string file_path = string(glob_result.gl_pathv[j]);
      Structure structure = Structure(file_path);
      structures[global_counter++] = structure;
    }
    globfree(&glob_result);
  }

  result.length  = total_length;
  result.items   = structures;
  result.success = true;


  return result;
}

WINDOW *top_tab, *bottom_tab;
void create_hud()
{

  top_tab = newwin(LINES-3, COLS, 0, 0);
  bottom_tab = newwin(3, COLS, LINES-3, 0);
  wborder(top_tab, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
  wborder(bottom_tab, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

  update_window_size(top_tab);

  wrefresh(top_tab);
  wrefresh(bottom_tab);
  refresh();
}

int main(i32 argc, char **argv)
{
  if (argc<2)
  {
    printf("Not enough arguments were given\n");
    return 1;
  }


  ImportResult import_result = import_files(argc, argv);
  if (! import_result.success)
    return 1;

  i32 structures_length = import_result.length;
  i32 actual_structure_id = 0;
  Structure *molecules = import_result.items;



  if (setup()) return 1;

  create_hud();

  for (int i = 0; i < structures_length; i++)
  {
    molecules[i].scale(top_tab);
  }

  int ch = '\0';
  do {
    werase(top_tab);
    wclear(bottom_tab);
    clean_map();

    switch (ch) {
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
      case 'H':
        if (--actual_structure_id < 0)
          actual_structure_id = structures_length-1;
        break;
      case 'L':
        if (++actual_structure_id >= structures_length)
          actual_structure_id = 0;
        break;
      case 'r':
        change_radius_mode();
        break;
      case 'b':
        change_bonding_mode();
        break;
    } 


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
    
    move(0, 3);
    printw("%s", molecules[actual_structure_id].name.c_str());
    mvwprintw(bottom_tab, 1, 1, "Radius mode: %c | Bonding mode: %c", radius_mode_ch, bonding_mode_ch);
    molecules[actual_structure_id].draw(top_tab);
    box(top_tab, 0, 0);
    box(bottom_tab, 0, 0);

    wrefresh(bottom_tab); wrefresh(top_tab);
    refresh();
  } while((ch = getch()) != 'q');
  endwin();

  return 0;
}
