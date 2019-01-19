#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "command.h"

char * getCommand() {
  int ch, row;
  row = getmaxy(stdscr);
  
  char * str;
  str = (char *) malloc(100);
  str[0] = '\0';

  unsigned char i = 0;
  attron(A_BOLD);
  mvprintw(row - 1, 0, ">");
  attroff(A_BOLD);
  while ((ch = getch()) != '\n') {
    if (ch == KEY_BACKSPACE) {
      str[i - 1] = '\0';
      i--;
    } else {
      str[i] = (char)ch;
      str[i + 1] = '\0';
      i++;
    }
    move(row - 1, 1);
    clrtoeol();
    mvprintw(row - 1, 2, "%s", str);
    refresh();
  }

  move(row - 1, 0);
  clrtoeol();

  return str;
}

