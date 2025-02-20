# pipex

Replica of the shell pipes. It aims to introduce the use of the `execve` function, along with the creation of child processes through the `fork` function and the communication between processes through pipes. This program will execute with the following arguments:

```
./pipex infile cmd1 cmd2 outfile
```

This will look for the `infile` file, and take its content as input for the first command `cmd1`. It will execute this command, and its output will be the input for the second command `cmd2`. The output of the second command will be stored in the `outfile` file, which will be created if it doesn't exist, or truncated if it does.

## Bonus

The `bonus` rule will compile another pipex program, which not only is able to concatenate multiple comands, but also is able to hadle `<<` and `>>` when the first parameter is `here_doc`. It will execute with the following ways:

```
./pipex infile cmd1 ... cmdn outfile

./pipex here_doc limiter cmd1 ... cmdn outfile
```