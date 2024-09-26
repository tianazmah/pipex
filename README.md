# **pipex** - A Pipe and Redirection Project

## Overview

**pipex** is a project from the 42 Network curriculum that simulates the functionality of the Unix `pipe` command, allowing multiple commands to be chained together. The goal is to create a program that takes input and output files, executes commands while managing input/output redirection and pipes between commands.

## Table of Contents

- [Overview](#overview)
- [Function Prototypes](#function-prototypes)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Compilation and Usage](#compilation-and-usage)
- [Testing](#testing)
- [License](#license)

## Function Prototypes

```c
void pipex(int argc, char **argv);
```
- **Parameters**:
  - `argc`: The number of command-line arguments.
  - `argv`: The array of command-line arguments, which are the commands to execute along with input/output files.
  
- **Return**:
  - This function does not return a value; it manages the execution of the commands and handles redirection.
## Project Structure

- **main.c**: The entry point of the program, handling input and output.
- **pipex.c**: The main logic for managing pipes and executing commands.
- **utils.c**: Utility functions for various tasks, such as error handling and command parsing.
- **pipex.h**: The header file containing function prototypes and necessary definitions.
- **Makefile**: Used for compiling the project.
## How It Works

The **pipex** program manages the execution of multiple commands through pipes:
- It creates a pipe for each command, connecting the output of one command to the input of the next.
- It handles input and output redirection based on provided file arguments.
- The program forks processes for each command, executing them in the appropriate order while maintaining the pipeline.

Key steps include:
- Reading the command-line arguments.
- Creating pipes using the `pipe` system call.
- Forking processes for each command and using `execve` to execute them.
- Handling any errors that occur during execution.
## Compilation and Usage

You can compile the project using the provided **Makefile**. To generate the object files and the final program, run the following commands:

```bash
# Compile the program
make

# Clean up object files
make clean

# Clean everything (object files and binary)
make fclean

# Recompile everything
make re
```

### Usage in Project``s

To use **pipex** in your own project, compile it and pass the input/output files and commands as command-line arguments.

```bash
./pipex infile "cmd1" "cmd2" outfile
```
The program will execute cmd1, passing its output to cmd2, and write the final output to `outfile.
