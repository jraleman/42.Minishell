# 42 Minishell

## About

• You must program a mini UNIX command interpreter.
• This interpreter must display a prompt (a simple "$> " for example) and wait till
you type a command line, validated by pressing enter.
• The prompt is shown again only once the command has been completely executed.
• The command lines are simple, no pipes, no redirections or any other advanced functions.
• The executable are those you can find in the paths indicated in the PATH variable.
• In cases where the executable cannot be found, it has to show an error message and
display the prompt again.
• You must manage the errors without using errno, by displaying a message adapted to the error output.
• You must deal correctly with the PATH and the environment (copy of system char **environ).
• You must implement a series of builtins: echo, cd, setenv, unsetenv, env, exit.
• You can choose as a reference whatever shell you prefer.
• You must manage expansions $ and  ̃

### Allowed Functions

- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir 
- getcwd, chdir
- stat, lstat, fstat
-  fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit

## Sources

- [Write a Shell in C - Brennan.io](https://brennan.io/2015/01/16/write-a-shell-in-c/)
