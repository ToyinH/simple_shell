#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <dirent.h>

void prompt_user(char **av, char **envt);
int main(int ac, char **av, char **envt);
char *handl_getline();
char **handl_strtok(char *string, char *delimiter);
int print_env(void);
int custom_strcmp(const char *s1, const char *s2);
int path_check(char *string);
char *file_check(char *string);
void fork_exec(char **argv, char **env, char **av);

#endif
