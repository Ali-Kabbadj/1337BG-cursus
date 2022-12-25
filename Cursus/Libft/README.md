# LIBFT
This is the first project in the 42 (1773 benguerir) school cuscus.It contain a lot of general purpose functions from the standard C Library.

## Tables of content

### Functions from `ctype.h` library :

| Function                               | Description                                          | Prototype    |
| -------------------------------------- |:----------------------------------------------------:|--------------|
| [`ft_isascii`](srcs/ft_isascii.c)      | ASCII character test                                 |              |
| [`ft_isalnum`](srcs/is/ft_isalnum.c)   | Alphanumeric character test                          |              |
| [`ft_isalpha`](srcs/is/ft_isalpha.c)   | Alphabetic character test                            |              |
| [`ft_islower`](srcs/is/ft_islower.c)   | Lower-case character test                            |              |
| [`ft_isupper`](srcs/is/ft_isupper.c)   | Upper-case character test                            |              |
| [`ft_isdigit`](srcs/is/ft_isdigit.c)	  | Decimal-digit character test                         |              |
| [`ft_isprint`](srcs/is/ft_isprint.c)	  | Printing character test (space character inclusive)  |              |
| [`ft_tolower`](srcs/to/ft_tolower.c)   | Upper case to lower case letter conversion           |              |
| [`ft_toupper`](srcs/to/ft_toupper.c)   | Lower case to upper case letter conversion           |              |
 
### Functions from `stdlib.h` library :

| Function                                  | Description                     | Prototype               |
| ----------------------------------------- |:-------------------------------:|-------------------------| 
| [`ft_atoi`](libft/srcs/to/ft_atoi.c)		    | Convert ASCII string to integer |                         | 
| [`ft_calloc`](libft/srcs/mem/ft_calloc.c)	| Cemory allocation               |                         |  

### Functions from `string.h` library

| Left columns                                | Right columns                       | Prototype               | 
| ------------------------------------------- |:-----------------------------------:|                         | 
| [`ft_bzero`](libft/srcs/mem/ft_bzero.c)	  | Write zeroes to a byte string       |                         | 
| [`ft_memset`](libft/srcs/mem/ft_memset.c)	  | Write a byte to a byte string       |                         | 
| [`ft_memchr`](libft/srcs/mem/ft_memchr.c)	  | Locate byte in byte string          |                         | 
| [`ft_memcmp`](libft/srcs/mem/ft_memcmp.c)	  | Compare byte string                 |                         | 
| [`ft_memmove`](libft/srcs/mem/ft_memmove.c) | Copy byte string                    |                         | 
| [`ft_memcpy`](libft/srcs/mem/ft_memcpy.c)	  | Copy memory area                    |                         | 
| [`ft_memccpy`](libft/srcs/mem/ft_memccpy.c) | Copy string until character found   |                         | 
