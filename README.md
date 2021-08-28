Written by Caroline Del Carmen and Rolando Roques
as part of our **Simple Shell** Holberton School Project.

Project Description/Restrictions:  
  
List of allowed functions and system calls  

    access (man 2 access)  
	chdir (man 2 chdir)  
	close (man 2 close)  
	closedir (man 3 closedir)  
	execve (man 2 execve)  
	exit (man 3 exit)  
	_exit (man 2 _exit)  
	fflush (man 3 fflush)  
	fork (man 2 fork)  
	free (man 3 free)  
	getcwd (man 3 getcwd)  
	getline (man 3 getline)  
	getpid (man 2 getpid)  
	isatty (man 3 isatty)  
	kill (man 2 kill)  
	malloc (man 3 malloc)  
	open (man 2 open)  
	opendir (man 3 opendir)  
	perror (man 3 perror)  
	read (man 2 read)  
	readdir (man 3 readdir)  
	signal (man 2 signal)  
	stat (__xstat) (man 2 stat)  
	lstat (__lxstat) (man 2 lstat)  
	fstat (__fxstat) (man 2 fstat)  
	strtok (man 3 strtok)  
	wait (man 2 wait)  
	waitpid (man 2 waitpid)  
	wait3 (man 2 wait3)  
	wait4 (man 2 wait4)  
	write (man 2 write)  

	Our project is to write a simple UNIX command interpreter. Our shell can only use functions from the allowed list below.
	Further down we list examples of how our Shell output should look like, and what it can handle.


**Compiled with**  

gcc -Wall -Werror -Wextra -pedantic *.c *.h -o myshell  
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./myshell  

I. File List
------------
- sh_header.h  
  - Header file. Contains libraries & prototypes.  
- sh_main.c  
  - Contains main function. It finds the enviroment PATH and calls other functions until user enters "exit".  
- sh_path.c  
  - Contains our get_path function that splits the PATH into a 2D array.
- sh_input.c  
  - Contains functions that handle the user input and convert it into a 2D array.  
- sh_ string_concat.c  
  - Contains functions that concatenate strings.  
- sh_get_path.c  
  - Contains function that checks the PATH for the specified executuble.  
- sh_execve.c
  - Contains function that creates a new process and executes the command.  
- sh_double_pointers.c
  - Contains funtion that frees/prints double pointers. 
- sh_helper_functions.c 
  - Contains functions that help us run the code.

II. Design
----------
The program is designed to mimic the abilities of a simple shell. It is capable of handling
simple commands with arguments. For example "ls -l". It can also handle the PATH as an argument, for example 
"/bin/ls". It works also in nonteractive mode, for example "echo "/bin/ls" | ./myshell". Below are some examples:

Example:  
**$ ls**  
main.c	path.c	execute.c	stringConcat.c  

**$ /bin/ls**  
main.c	path.c	execute.c	stringConcat.c  

**$ ls | ./myshell**  
main.c	path.c	execute.c	stringConcat.c  

**$ pwd**  
/home/vagrant/shell/simple_shell  

**/bin/pwd**  
/home/vagrant/shell/simple_shell   
