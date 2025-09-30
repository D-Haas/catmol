#pragma once

#include "../constants.h"

enum Opt {
  NONE,
  VERSION,
  HELP,
};

Opt check_opts(i32 argc, char **argv);

void print_help();
void print_version();
