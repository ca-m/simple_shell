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


