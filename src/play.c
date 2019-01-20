#include <unistd.h>
#include <ncurses.h>
#include "main.h"
#include "play.h"

game_mode_t play(game_state_t * state) {

  while(!state->paused) {
    state->previous_input = state->input;
    state->input = getch();
    if (state->input == 27) {
      return COMMAND;
    }
    update(state);
    draw(state);
  }

  return EXIT;
}

int initGameState(game_state_t * state) {
  state->paused = 0;
  state->frame = 0;

  return 0;
}

int update(game_state_t * state) {
  state->frame++;

  return 0;
}

int draw(game_state_t * state) {
  clear();
  mvprintw(0,0,"%d:\n%c\n",state->frame, state->input);
  refresh();

  return 0;
}

