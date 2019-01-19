#include <ncurses.h>
#include "main.h"

int main() {
  initscr();
  printw("Hello, World!");
  refresh();
  getch();
  endwin();

  return 0;
}

