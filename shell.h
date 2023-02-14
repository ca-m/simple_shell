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

/*close shell*/
int builtin_exit(data_of_program *data);

/*change current directory*/
int builtin_cd(data_of_program *data);

/*set work directory*/
int set_work_directory(data_of_program *data, char *new_dir);

/*show help info*/
int builtin_help(data_of_program *data);

/*set, unset, show alias*/
int builtin_alias(data_of_program *data);


/* builtins_env.c */

/*shows environment where shell runs*/
int builtin_env(data_of_program *data);

/*creates/override variable of environment*/
int builtin_set_env(data_of_program *data);

/*delete variable of enviroment*/
int builtin_unset_env(data_of_program *data);


/* HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT */


/* env_management.c */

/*gets value of environment variable*/
char *env_get_key(char *name, data_of_program *data);

/*overwrite value of environment variable*/
int env_set_key(char *key, char *value, data_of_program *data);

/*remove key from environment*/
int env_remove_key(char *key, data_of_program *data);

/*print current environment*/
void print_environ(data_of_program *data);


/* HELPERS FOR PRINTING */


/* helpers_print.c */

/*prints string in standar output*/
int _print(char *string);

/*prints string in standar error*/
int _printe(char *string);

/*prints string in standar error*/
int _print_error(int errorcode, data_of_program *data);


/* HELPERS FOR STRINGS MANAGEMENT */


/* helpers_string.c */

/*counts number of characters of string*/
int str_length(char *string);

/*duplicates string*/
char *str_duplicate(char *string);

/*compares two strings*/
int str_compare(char *string1, char *string2, int number);

/*concatenates two strings*/
char *str_concat(char *string1, char *string2,);

/*reverse string*/
void str_reverse(char *string);


/* helpers_numbers.c */
