# Libft

*This project has been created as part of the 42 curriculum by romgutie.*

## Description

Libft is a custom C library that reimplements standard libc functions along with additional utility functions. This project is the first step in the 42 curriculum.

The goal is to create a reusable library that will serve as a foundation for future projects. The project is divided into two main parts:
- **Part 1**: Reimplementation of libc functions (string manipulation, memory, conversions)
- **Part 2**: Additional utility functions (split, substr, itoa, etc.)

## Instructions

### Compilation

To compile the library, use the provided Makefile:

```bash
make
```

This will generate the `libft.a` file at the root of the project.

### Available commands

- `make` or `make all`: Compiles the library
- `make clean`: Removes object files (.o)
- `make fclean`: Removes object files and the library
- `make re`: Recompiles the entire project

### Usage

To use the library in your projects:

1. Include the header in your source files:
```c
#include "libft.h"
```

2. Compile your project with the library:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

## Functions Implemented

### Part 1 - Libc Functions

**Character checks:**
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

**String manipulation:**
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`
- `ft_strncmp`, `ft_strnstr`, `ft_strdup`

**Memory manipulation:**
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_memchr`, `ft_memcmp`, `ft_calloc`

**Conversions:**
- `ft_toupper`, `ft_tolower`, `ft_atoi`

### Part 2 - Additional Functions

- `ft_substr`: Extracts a substring
- `ft_strjoin`: Concatenates two strings
- `ft_strtrim`: Removes characters from beginning and end
- `ft_split`: Splits a string by a delimiter
- `ft_itoa`: Converts an integer to a string
- `ft_strmapi`: Applies a function to each character
- `ft_striteri`: Iterates over a string with a function
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: File descriptor output functions

## Resources

### Documentation and References

- YouTube tutorials  
- Linux man pages: `man [function]` for detailed documentation on standard functions  
- [Koor](https://koor.fr/C/Index.wp) — French-language documentation

### Use of AI

AI was not used to generate any code. It was only used to clarify certain concepts when necessary.

Development relied on:
- Careful reading of man pages to understand how each function works  
- Systematic testing to verify correctness

## Technical Notes

- All files are compiled with the flags `-Wall -Wextra -Werror`  
- No global variables are used  
- Helper functions are declared as `static` to restrict their scope  
- The project strictly follows the 42 Norm  
