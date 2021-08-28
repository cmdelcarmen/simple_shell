#include "sh_header.h"

void get_c(int sig);
/**
 * main - our simple shell, reads command from the command line
 * and searches for the appropiate file_name to execute
 * @ac: number of argumetns
 * @av: commands entered
 * @env: enviroment variables
 * Return: 0 if succesful
 */
int main(int ac, char **av, char **env)
{
	char **command, **path_arr, *file_name, *file_folder;

	(void)ac;
	(void)av;
	signal(SIGINT, get_c);
	path_arr = get_path(env);

	while (1)
	{
		command = input(path_arr);
		if (command == NULL)
		{
			freeDoublePointers(path_arr);
			exit(0);
		}

		if (_strcmp(command[0], "env") == 0)
		{
			printDoubleArray(env);
			freeDoublePointers(command);
			continue;
		}
		if (_strcmp(command[0], "exit") == 0)
		{
			freeDoublePointers(path_arr);
			freeDoublePointers(command);
			exit(0);
		}
		if (access(command[0], F_OK) == 0)
		{
			execve(command[0], command, NULL);
			freeDoublePointers(command);
			continue;
		}

		file_folder = getDir(path_arr, command);
		if (file_folder == NULL)
		{
			freeDoublePointers(command);
			continue;
		}
		file_name = strConcat(file_folder, command[0]);

		if (executeCommand(file_name, command) == -1)
		{
			free(file_name);
			freeDoublePointers(command);
			exit(0);
		}
		free(file_name);
		freeDoublePointers(command);
	}
	return (0);
}
