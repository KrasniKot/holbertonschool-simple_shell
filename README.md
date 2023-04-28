<br/>
<p align="center">
  <a href="https://github.com/KrasniKot/holbertonschool-simple_shell">
      <img src="https://raw.githubusercontent.com/computefoundation/gnu-linux-shell-scripting/images/logo.png" alt="Logo" width="150" height="80">
        </a>

<h3 align="center">Simple Shell</h3>

<p align="center">
Creating our customed command-line interpreter for Holberton School, Uruguay.
<br/>
<br/>
<a href="https://github.com/KrasniKot/holbertonschool-simple_shell"><strong>Explore the docs »</strong></a>
<br/>
<br/>
</p>
</p>

![Contributors](https://img.shields.io/github/contributors/KrasniKot/holbertonschool-simple_shell?color=dark-green)

## Table Of Contents

* [About the Project](#about-the-project)
* [Getting Started](#getting-started)
	* [Prerequisites](#prerequisites)
	* [Installation, compilig and usage](#installation-compiling-and-usage)
* [Usage](#usage)
* [Authors](#authors)

## About The Project

	![Screen Shot](ACA VA EL FLOWCHART DEL MAIN)

	The objective of this project is to create a custom version of the bash (Bourne Again Shell). Its purpose is to provide a command-line user interface for Unix-like operating systems, in other words is a program that executes other programs in response to text commands that the user enters.
	It can be used in both ```interactive``` and ```non-interactive``` modes, meaning it recognizes commands not only when the user "opens" its program but also when it's called by pipelines.
	In our version, we can execute all ```executable commands``` found in the ```PATH``` environmental variable, and we handle the ```env``` and ```exit``` built-ins.
	Anyway, this is a small and restricted version compared to the original bash, and it still has plenty of work to be done.

## Getting Started

	Here is a practical guide for installing and compiling our customed Simple Shell

### Prerequisites

	The repository containing this projects has these files:

	```shell.h```: holds prototypes of functions spread across all files, and C libraries needed for them.
	```man_1_simple_shell```: custom manpage for custom Simple Shell.
	```main.c```: holds the entrance for the program itself.
	```_getenv.c```: search the environment variable specified.
	```execute.c```: creates a process to execute the command specified by the user and executes it. It previously checks if the route to the command is specified or not.
	```findcmd.c```: finds the route to the given command if the user didn't specify it.
	```token.c```: tokenizes (splits) the command into an array of tokens.

### Installation, compiling and usage

	1. Clone the repo, by executing:
	```sh
	git clone https://github.com/KrasniKot/holbertonschool-simple_shell.git
	```

	2. Enter the repo, using:
	```sh
	cd holbertonschool-simple_shell
	```

	3. Compile it with:
	```sh
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
	```

	4. Now you have to decide whether you want to be in an interactive or non-interactive way:

	4.1. If you want to enter the Simple Shell program, execute as follows:
	```sh
	./hsh
	```
	Your output should be:
	```sh
	$
	```
	and now you can enter any command you'd like.

	4.2. For the non-interactive way, type:
	```sh
	echo "your_command" | ./hsh
	```

## Usage

	Example of usage, in both interactive and non-interactive way, of the custom Simple Shell using the ```ls -l``` command.

	Interactive mode:
	```sh
	your_terminal@~$ ./hsh

	$ ls -l
	-rw-------  1 owner  group  630 Apr 28  15.04  firstfile.c
	-rwx-wx--x  1 owner  group  234 Apr 28  17.25  secondfile.c
	$
	```
	To exit the Shell, simply type:
	```sh
	$ exit
	your_terminal@~$
	```

	Non-interactive mode:
	```sh
	your_terminal@~$ echo "ls -l" | ./hsh
	-rw-------  1 owner  group  630 Apr 28  15.04  firstfile.c
	-rwx-wx--x  1 owner  group  234 Apr 28  17.25  secondfile.c
	your_terminal@~$
	```
	Another good example is to check if there are any leaks of memory (allocated memory by the program, but not properly free'd).
	As an example, to check if there are leaks when using the ```ls``` command in the non-interactive mode, you should use the ```valgrind``` program as follows:
	```sh
	your_terminal@~$ echo "ls" | valgrind ./hsh
	==3915== Memcheck, a memory error detector
	==3915== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
	==3915== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
	==3915== Command: ./hsh
	==3915==
	execute.c  findcmd.c  _getenv.c  hsh  main.c  README.md  shell.h  token.c
	==3915==
	==3915== HEAP SUMMARY:
	==3915==     in use at exit: 0 bytes in 0 blocks
	==3915==   total heap usage: 34 allocs, 34 frees, 5,001 bytes allocated
	==3915==
	==3915== All heap blocks were freed -- no leaks are possible
	==3915==
	==3915== For lists of detected and suppressed errors, rerun with: -s
	==3915== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
	your_terminal@~$
	```
	There we can ensure that all the memory allocated is properly free'd.



## Authors

	* **Emanuel Trias** - *Holberton Student* - [Emanuel Trias](https://github.com/KrasniKot) - *Author*
	* **Luisina Llugdar** - *Holberton Student* - [Luisina Llugdar](https://github.com/LuisinaLlugdar) - *Author*

