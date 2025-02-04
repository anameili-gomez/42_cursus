# ft_printf

Replica of the C function printf. Its a very usefull tool, and was added to the `libft` custom library in order to use it in other 42 projects. It aims to introduce the variadic functions, as they are needed to properly recieve and cast the possible variables to print. The `all` rule will compile a `libftprintf.a` library.<br><br>

It manages the following varable types:
- `%c` Prints a single character
- `%s` Prints a string
- `%p` Prints a pointer in hexadecimal format
- `%d` Prints a decimal (base 10) number
- `%i` Prints an integer in base 10
- `%u` Prints an unsigned decimal (base 10) number
- `%x` Prints a hexadecimal (base 16) number in lowercase
- `%X` Prints a hexadecimal (base 16) number in uppercase
- `%%` Prints the percent symbol