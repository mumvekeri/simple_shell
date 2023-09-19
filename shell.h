#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/stat.h>

#define MAX_INPUT_LENGTH 100
/* Global Variables */
extern char **environ;
void print_env(void);
void truncate_at_comment(char *input);
char **tokenize(char *input);
int execute_full_command(char **args, char **argv, char *command_path);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, size_t n);
size_t _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);

int execute_builtin_commands(char **args, char *name, char *buf);
void executeShellPrompt(int interactiveMode);
void processInput(char *inputLine, char **av);
int main(int ac, char **av);
void fixComments(char *inputLine);
char **tokenizeInput(char *inputLine);
void handleNonExecutable(char **arguments, char **av, char *inputLine);
void executeExecutable(char **arguments, char **av);
int handle_invalid_command(char **args, char *progname, int count);
void prompt_if_interactive(int mode);
char *find_command_path(char *directories, char *command);
char *get_env_path(void);
int execute_full_command(char **args, char **argv, char *command_path);
int execute_command(char **args, char **argv);
int handle_builtin_commands(char **args, char *progname, char *buffer);
void print_environment(char **env);
void execute_builtin_env(char **env);
int process_builtin_commands(char **args, char *buffer);
void _start(void);
char **split_paths(char *paths);
char *get_full_path(char *paths, char *cmd);
int handle_builtins(char **args, char *progname, char *buffer);
/* functions to print errors */
void free_string_array(int size, char *strings[]);
void print_error(char *prog_name, int cmd_count, char *cmd);
void print_string(char *str);
int print_char(char character);

#endif /* SHELL_H */

