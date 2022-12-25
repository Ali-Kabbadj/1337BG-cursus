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

### Functions from `strings.h` library

| Function                                    | Description                         | Prototype               |
| ------------------------------------------- |:-----------------------------------:|-------------------------| 
| [`ft_bzero`](libft/srcs/mem/ft_bzero.c)	    | Write zeroes to a byte string       |                         | 
| [`ft_memset`](libft/srcs/mem/ft_memset.c)	  | Write a byte to a byte string       |                         | 
| [`ft_memchr`](libft/srcs/mem/ft_memchr.c)	  | Locate byte in byte string          |                         | 
| [`ft_memcmp`](libft/srcs/mem/ft_memcmp.c)	  | Compare byte string                 |                         | 
| [`ft_memmove`](libft/srcs/mem/ft_memmove.c) | Copy byte string                    |                         | 
| [`ft_memcpy`](libft/srcs/mem/ft_memcpy.c)	  | Copy memory area                    |                         | 
| [`ft_memccpy`](libft/srcs/mem/ft_memccpy.c) | Copy string until character found   |                         | 

### Functions from `string.h` library

| Function                                      | Description                                        | Prototype               |
| --------------------------------------------- |:--------------------------------------------------:|-------------------------| 
| [`ft_strlen`](libft/srcs/str/ft_strlen.c)			 	| find length of string                              |                         | 
| [`ft_strlen_2`](libft/srcs/str/ft_strlen_2.c) |	find length of 2D array (i.e. splitted string)     |                         | 
| [`ft_strchr`](libft/srcs/str/ft_strchr.c)				 | locate character in string (first occurrence)      |                         | 
| [`ft_strrchr`](libft/srcs/str/ft_strrchr.c)			| locate character in string (last occurence)        |                         | 
| [`ft_strstr`](libft/srcs/str/ft_strstr.c)     | locate a substring in a string                     |                         | 
| [`ft_strnstr`](libft/srcs/str/ft_strnstr.c)			| locate a substring in a string (size-bounded)      |                         | 
| [`ft_strcmp`](libft/srcs/str/ft_strcmp.c)     | compare strings                                    |                         | 
| [`ft_strncmp`](libft/srcs/str/ft_strncmp.c)   |	compare strings (size-bounded)                     |                         | 
| [`ft_strnrcmp`](libft/srcs/str/ft_strnrcmp.c)	|	reversely compare strings (size-bounded)           |                         | 
| [`ft_strcpy`](libft/srcs/str/ft_strcpy.c)     | copy strings                                       |                         | 
| [`ft_strncpy`](libft/srcs/str/ft_strncpy.c)   | copy strings (size-bounded)                        |                         | 
| [`ft_strdup`](libft/srcs/str/ft_strdup.c)			  | save a copy of a string (with malloc)              |                         | 
| [`ft_strndup`](libft/srcs/str/ft_strndup.c)   | save a copy of a string (with malloc, size-bounded)|                         | 
| [`ft_strcat`](libft/srcs/str/ft_strcat.c)     | concatenate strings (s2 into s1)                   |                         | 
| [`ft_strncat`](libft/srcs/str/ft_strncat.c)   | concatenate strings (s2 into s1, size-bounded)     |                         | 
| [`ft_strlcpy`](libft/srcs/str/ft_strlcpy.c)			| size-bounded string copying                        |                         | 
| [`ft_strlcat`](libft/srcs/str/ft_strlcat.c)			| size-bounded string concatenation                  |                         | 
