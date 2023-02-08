#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h> /*printf*/
#include <unistd.h> /*fork, execve*/
#include <string.h> /* strtok*/
#include <errno.h> /*errno and perror*/
#include <sys/types.h> /*type pid*/
#include <sys/wait.h> /*wait*/
#include <sys/stat.h> /*use of stat function*/
#include <signal.h> /*signal management*/
#include <fcntl.h> /* open files*/

/*MARCOS*/

#include "marcos.h" /*help and prompt*/

/*STRUCTURES*/

/**
 * struct info - structure for the program's data
 * @program_name: name of executable
 * @input_line: pointer to input for _getline
 * @command_name: pointer to first line typed
 * @exec_counter: counts executed commads
 * @file_descriptor: descriptor to input of commands
 * @tokens:pointer to array of token input
 * @env: copy of the environment
 * @alias_list: array of pointers with aliases
 */

typedef struct info
{
	char *program name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - structure for builtins
 * @builtin: name of builtin
 * @function: function of the builtin
 */

typedef struct builtins
{
	char * builtins
	int (*function)(data_of_program *data);
} builtins;

/* MAIN FUNCTIONS*/
