#include "main.h"

#ifndef COMMAND_H
#define COMMAND_H

game_mode_t commandLine();
game_mode_t runCommand(char * cmd);
int getCommand(char * cmd);
int printCommandLine(char * cmd);
int clearCommandLine(void);

int greet(void);

#endif
