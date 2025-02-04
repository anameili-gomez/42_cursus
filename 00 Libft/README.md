# Libft

Custom C library. It aims to improve C skills and deepen the understaning of C memory alocation and lists. The Makefile has three rules: `all` will compile the basic functions, `bonus` will compile some list related functions, and `extra` will compile the basic functions as well as more complex functions part of other projects. They will all create a `libft.a` library.<br><br>

It contains imitations of the following libc functions: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `strlen`, `memset`, `bzero`, `memcpy`, `memmove`, `strlcpy`, `strlcat`, `toupper`, `tolower`, `strchr`, `strrchr`, `strncmp`, `memchr`, `memcmp`, `strnstr` and `atoi`.<br><br>

It also has more custom functions:
- `ft_substr`: returns a substring of the string recieved as a first parameter, the returned substring begins at the index recieved as a second parameter and has a maximum length of the third parameter
- `ft_strjoin`: allocs and joins two strings
- `ft_strtrim`: trims the string recieved as first parameter, removing from it the characters recieved as second parameter found at the beginning anf the ending.
- `ft_split`: alocates and returns an array of strings containing fragments in the recieved string between the recieved delimiter character
- `ft_itoa`: returns the recieved integer as a character array
- `ft_strmapi`: recieves a functions and applies it to every item in a string, passing the character and its corresponding index, returns the resulting string
- `ft_striteri`: modifies a string, applying the function recieved to each character
- `ft_putchar_fd`: writes the recieved character in the indicated file
- `ft_putstr_fd`: writes the recieved string in the indicated file
- `ft_putendl_fd`: writes the recieved string in the indicated file followed by a new line
- `ft_putnbr_fd`: writes the recieved integer in the indicated file<br><br>

In order to get more familiar with lists, some bonus functions were also implemented, using a simple struct, containing only a void pointer for its content and a pointer to the next node:
- `ft_lstnew`: creates a new node
- `ft_lstadd_front`: adds the recieved node to the beginning of the list
- `ft_lstsize`: returns the number of nodes in a list
- `ft_lstlast`: returns the last node of the recieved list
- `ft_lstadd_back`: adds the recieved node to the end of a list
- `ft_lstdelone`: frees the content of the node using the recieved function and deletes the node itself
- `ft_lstclear`: frees and deletes the whole list recieved
- `ft_lstiter`: applies the recieved function to the content of each node in the list recieved
- `ft_lstmap`: returns a new list resulting of applying the function passed to the content of each node in the list recieved<br><br>

With time, more funtions (worked on in different projects) were added to the library with the intention of using them in further projects. This is the case of `ft_printf` and `get_next_line`.