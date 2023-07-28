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
#include <signal.h>
#define BUFFER_SIZE 1024
extern char buffer1[BUFFER_SIZE];

void prompt_user(char **av, char **envt);
int main(int ac, char **av, char **envt);
char *handl_getline();
char **handl_strtok(char *string, char *delimiter);
int print_env(void);
int custom_strcmp(const char *s1, const char *s2);
int path_check(char *string);
char *file_check(char *string);
void fork_exec(char **argv, char **env, char **av);
ssize_t custom_read(int fd, void *buf, size_t count);
ssize_t custom_getline(char **lineptr, size_t *n);
void free_argv(char **argv);
void free_argv2(char **argv);
void premade_path(char **argv, char **av, char **env);
void unpath(char **argv, char **av, char **env);

char *_strcat(char *str1, char *str2);
char *_strcpy(char *str_to, char *str1);
int _strlen(char *str);
void _printf(char *str_in);
char *_realloc(char *pntr, size_t new_mem_size);
char *_memcpy(char *dest, char *src, size_t n);
void handle_sigint (int signum __attribute__((unused)));
typedef void (*sighandler_t)(int);
bool space_character(char *strn);
int len(char *s);
void custom_exit(char **argve);

#endif
