#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

int __attribute((unused)) EXIT_CODE;

char **input(char **patharray);
int numberOfElementsInArray(char *usrinput);
int moveIndex(char *usrinput);
char *strConcat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char **getArray(char *usrinput);
char **get_path(char **env);
char *getDir(char **path, char **command);
void freeDoublePointers(char **pointer);
void printDoubleArray(char **pointer);
int executeCommand(char *fullPath, char **commandLineArgs);
char *pathInput(char *usrInput, char **patharray);
int moveIndex(char *usrinput);
char *_strdup(char *str);
int _putchar(char c);
int _strcmp2(char *s1, char *s2);
int checkIfInputAllSpaces(char *usrinput);
int checkIfPath(char *usrinput);
void prompt(void);
char **handlesNullInput(char *usrinput);
int verifyPath(char *usrinput, char **patharray);
char *get_errors(char **av);
void get_c(int sig);

#endif
