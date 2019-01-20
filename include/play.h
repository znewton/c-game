#include "main.h"

#ifndef PLAY_H
#define PLAY_H

typedef enum direction {
  stationary,
  up,
  down,
  left,
  right
} direction_t;

typedef struct game_obj {
  int x;
  int y;
  unsigned int width;
  unsigned int height;
  direction_t dir;
} game_obj_t;

typedef struct game_state {
  game_obj_t * p;
  game_obj_t ** terrain;
  game_obj_t ** enemies;
  game_obj_t * camera;
  int input;
  int previous_input;
  unsigned char paused : 1;
  long frame;
} game_state_t;

game_mode_t play(game_state_t * state);
int initGameState(game_state_t * state);
int update(game_state_t * state);
int draw(game_state_t * state);

#endif

