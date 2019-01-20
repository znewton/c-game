#include <ncurses.h>
#include <stdlib.h>
#include "main.h"
#include "command.h"
#include "play.h"

int main() {

  initscr();
  raw();
  keypad(stdscr, 1);
  noecho();

  game_mode_t mode = COMMAND;
  game_state_t * gameState = (struct game_state *)malloc(sizeof(struct game_state));
  initGameState(gameState);

  while (mode != EXIT) {
    switch(mode) {
      case COMMAND:
        timeout(-1);
        mode = commandLine();
        break;
      case PLAY:
        timeout(16);
        mode = play(gameState);
        break;
      case EXIT:
        mode = EXIT;
        break;
    }
  }

  endwin();
  free(gameState);

  return 0;
}

