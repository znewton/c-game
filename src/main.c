#include <ncurses.h>
#include "main.h"
#include "command.h"
#include "play.h"

int main() {

  initscr();
  raw();
  keypad(stdscr, 1);
  noecho();

  game_mode_t mode = COMMAND;

  while (mode != EXIT) {
    switch(mode) {
      case COMMAND:
        mode = commandLine();
        break;
      case PLAY:
        mode = play();
        break;
      case EXIT:
        mode = EXIT;
        break;
    }
  }

  endwin();

  return 0;
}

