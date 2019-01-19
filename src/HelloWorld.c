#include <ncurses.h>
#include "HelloWorld.h"

int main() {
  initscr();
  greet();
  refresh();
  getch();
  endwin();

  return 0;
}

int greet() {
  printw("Hello, World!");
  return 0;
}
