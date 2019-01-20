#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "main.h"

game_mode_t commandLine() {
  char * cmd = (char *) malloc(100);
  getCommand(cmd);
  clearCommandLine();
  return runCommand(cmd);
}

int getCommand(char * cmd) {
  int ch;
  cmd[0] = '\0';

  unsigned char i = 0;
  printCommandLine(cmd);
  while ((ch = getch()) != '\n') {
    if (ch == KEY_BACKSPACE) {
      cmd[i - 1] = '\0';
      i--;
    } else {
      cmd[i] = (char)ch;
      cmd[i + 1] = '\0';
      i++;
    }
    printCommandLine(cmd);
  }

  return 0;
}

game_mode_t runCommand(char * cmd) {
  if (!strcmp(cmd, "hello")) {
    greet();
  } else if (!strcmp(cmd, "play")) {
    return PLAY;
  } else if (!strcmp(cmd, "quit")) {
    return EXIT;
  }
  free(cmd);
  return COMMAND;
}

int printCommandLine(char * cmd) {
  int row = getmaxy(stdscr);
  
  attron(A_BOLD);
  mvprintw(row - 1, 0, ">");
  attroff(A_BOLD);
  move(row - 1, 1);
  clrtoeol();
  mvprintw(row - 1, 2, "%s", cmd);
  refresh();

  return 0;
}

int clearCommandLine() {
  int row = getmaxy(stdscr);

  move(row - 1, 0);
  clrtoeol();

  return 0;
}

/**
 * Actions
 */
int greet() {
  clear();
  mvprintw(0, 0, "Hello!");
  refresh();
  return 0;
}
