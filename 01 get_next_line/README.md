# get_next_line

`get_next_line` is a C function that reads a file **line by line** each time it is called. It returns:

- The next line from the file.
- `NULL` if an error occurs or the end of the file is reached.

## How it works

- The function uses the `read` system call, reading a specified number of characters at a time until a newline (`\n`) is found.
- The number of characters read at once is controlled by BUFFER_SIZE.
 - You can define BUFFER_SIZE during compilation:
```
gcc -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
```
 - If not specified, it defaults to 42.

## Purpose & Features
- Introduces **static variables** for persistent data storage between function calls.
- Focuses on **memory management** to prevent leaks.
- Also included in the custom libft library for reuse in other projects.

## Bonus Version
- The bonus implementation supports reading **multiple files** simultaneously.
- Since `get_next_line` is a single function, the project does not include a Makefile but provides two sets of source files for standard and bonus functionality.
