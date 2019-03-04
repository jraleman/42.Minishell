# 42.Minishell

## About

### Instructions

- You must program a *mini UNIX command interpreter*.
- This interpreter must display a prompt (a simple `$> ` for example)
  and wait till you type a command line, validated by pressing enter.
- The prompt is shown again only once the command has been completely executed.
- The command lines are simple, no pipes, no redirections
  or any other advanced functions.
- The executable are those you can find in the paths indicated
  in the PATH variable.
- In cases where the executable cannot be found,
  it has to show an error message and display the prompt again.
- You must manage the errors without using `errno`,
  by displaying a message adapted to the error output.
- You must deal correctly with the PATH
  and the environment (copy of system char `**environ`).
- You must implement a series of builtins:
  - `exit`
  - `echo`
  - `cd`
  - `env`
    - `setenv`
    - `unsetenv`
- You can choose as a reference whatever shell you prefer.
- You must manage expansions `$` and `~`

#### Allowed Functions

- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir
- getcwd, chdir
- stat, lstat, fstat
- fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit

## Project Structure

### Source files

```
src/
├── builtins
│   ├── builtins.c
│   ├── cmd
│   │   ├── baguette.c
│   │   ├── cd.c
│   │   ├── echo.c
│   │   ├── env.c
│   │   ├── exit.c
│   │   ├── help.c
│   │   ├── konami.c
│   │   └── setenv.c
│   └── get_total.c
├── main.c
├── main.o
├── minishell.c
└── utils
    └── ft_error.c

3 directories, 14 files
```

### Header files

```
includes/
├── builtins.h
├── minishell.h
└── utils.h

0 directories, 3 filess
```

## Sources

- [Write a Shell in C - Brennan.io](https://brennan.io/2015/01/16/write-a-shell-in-c/)
