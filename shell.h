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


/* shell.c */

/*initialize structure with info of program*/
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/*makes infinite loop that shows prompt*/
void sisifo(char *prompt, data_of_program *data);

/*print prompt in new line*/
void handle_ctrl_c(int opr UNUSED);


/* getline.c */

/*read one line of stndar input*/
int _getline(data_of_program *data);

/*split each line for logical operators if exists*/
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/* expansions.c */

/*expand variables*/
void expand_variables(data_of_program *data);

/*expand aliases*/
void expand_aliases(data_of_program *data);

/*append string to end of buffer*/
int buffer_add(char *buffer, char *str_to_add);


/* str_tok.c */

/*separate string in tokens using a designed delimiter*/
void tokenize(data_of_program *data);

/*creates pointer to a part of a string*/
char *_strtok(char *line, char *delim);


/* execute.c */

/*execute command with entire path*/
int execute(data_of_program *data);


/* builtins_list.c */

/*if match a builtin, execute*/
int builtins_list(data_of_program *data);


/* find_in_path.c */

/*creates array of path directories*/
char **tokenize_path(data_of_program *data);

/*search for program in path*/
int find_program(data_of_program *data);


/* HELPERS FOR MEMORY MANAGEMENT */


/* helpers_free.c */

/*frees memory for directories*/
void free_array_of_pointers(char **directories);

/*free fields needed in each loop*/
void free_recurrent_data(data_of_program *data);

/*free all fields of data*/
void free_all_data(data_of_program *data);


/* BUILTINS */


/* builtins_more.c */
