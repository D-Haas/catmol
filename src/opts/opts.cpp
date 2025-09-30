#include "./opts.h"
#include <cstdio>
#include <cstring>

Opt check_opts(i32 argc, char **argv)
{
  for (i32 i = 0; i < argc; i++)
  {
    if (!strcmp("--version", argv[i]) || !strcmp("-v", argv[i]))
      return VERSION;
    else if (!strcmp("--help", argv[i]) || !strcmp("-h", argv[i]))
      return HELP;
  }
  return NONE;
}

void print_version()
{
  printf("CatMol 1.0.0\n");
}

void print_help()
{
  printf(
    "\n"
    "Welcome to CatMol\n"
    "catmol [FILES or PATTERN]\n"
    "\n"
    "ARGUMENTS:\n"
    "  [FILES or PATTERN]      The molecular structure files to visualize\n"
    "                          (XYZ only for now)\n"
    "OPTIONS:\n"
    "  -v, --version           Print version information\n"
    "  -h, --help              Print this help message\n"
    "\n"
  );
}
