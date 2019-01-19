#include <ncurses.h>
#include <string.h>
#include "main.h"
#include "command.h"

int main() {

  initscr();
  raw();
  keypad(stdscr, 1);
  noecho();

  char * cmd;

  while (strcmp((cmd = getCommand()), "quit")) {
    if (!strcmp(cmd, "hello")) {
      greet();
    } else {
      clear();
      printw("Invalid command: Try \"hello\"");
      refresh();
    }
  }

  endwin();

  return 0;
}

int greet() {
  clear();
  printw("Hello!");
  refresh();
  return 0;
}
