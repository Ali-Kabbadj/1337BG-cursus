# LIBFT
This is the first project in the 42 (1773 benguerir) school cuscus.
It contain a lot of general purpose functions from the standard C Library.

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

### Functions from `strings.h` library :

| Function                                    | Description                         | Prototype               |
| ------------------------------------------- |:-----------------------------------:|-------------------------| 
| [`ft_bzero`](libft/srcs/mem/ft_bzero.c)	    | Write zeroes to a byte string       |                         | 
| [`ft_memset`](libft/srcs/mem/ft_memset.c)	  | Write a byte to a byte string       |                         | 
| [`ft_memchr`](libft/srcs/mem/ft_memchr.c)	  | Locate byte in byte string          |                         | 
| [`ft_memcmp`](libft/srcs/mem/ft_memcmp.c)	  | Compare byte string                 |                         | 
| [`ft_memmove`](libft/srcs/mem/ft_memmove.c) | Copy byte string                    |                         | 
| [`ft_memcpy`](libft/srcs/mem/ft_memcpy.c)	  | Copy memory area                    |                         | 
| [`ft_memccpy`](libft/srcs/mem/ft_memccpy.c) | Copy string until character found   |                         | 

### Functions from `string.h` library :

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


### Functions from `math.h` library :

| Function                                      | Description                                        | Prototype               |
| --------------------------------------------- |:--------------------------------------------------:|-------------------------| 
| [`ft_sqrt`](libft/srcs/math/ft_sqrt.c) *      |	Square root function                               |                         |
| [`ft_pow`](libft/srcs/math/ft_pow.c) *        |	Power function                                     |                         |

### Non-standard functions

| Function                                            | Description                                                                    | Prototype               |
| --------------------------------------------------- |:------------------------------------------------------------------------------:|-------------------------| 
| [`ft_swap`](libft/srcs/mem/ft_swap.c) *             |	Swap value of two integers                                                     |                         |
| [`ft_putchar`](libft/srcs/put/ft_putchar.c) *       | Output a character to stdout.                                                  |                         |
| [`ft_putchar_fd`](libft/srcs/put/ft_putchar_fd.c)   |	Output a character to given file.                                              |                         |
| [`ft_putstr`](libft/srcs/put/ft_putstr.c) *         |	Output string to stdout.                                                       |                         |
| [`ft_putstr_fd`](libft/srcs/put/ft_putstr_fd.c)     |	Output string to given file.                                                   |                         |
| [`ft_putendl`](libft/srcs/put/ft_putendl.c) *       |	Output string to stdout with newline.                                          |                         |
| [`ft_putendl_fd`](libft/srcs/put/ft_putendl_fd.c)   |	Output string to given file with newline.                                      |                         |
| [`ft_putnbr`](libft/srcs/put/ft_putnbr.c) *         |	Output integer to stdout.                                                      |                         |
| [`ft_putnbr_fd`](libft/srcs/put/ft_putnbr_fd.c)     |	Output integer to given file.                                                  |                         |
| [`ft_itoa`](libft/srcs/to/ft_itoa.c)	               |	Convert integer to ASCII string.                                               |                         |
| [`ft_substr`](libft/srcs/str/ft_substr.c)           |	Extract substring from string.                                                 |                         |
| [`ft_strtrim`](libft/srcs/str/ft_strtrim.c)		   	   | Trim beginning and end of string with the specified characters.                |                         |
| [`ft_strjoin`](libft/srcs/str/ft_strjoin.c)		   	   | Concatenate two strings into a new string (with malloc).                       |                         |
| [`ft_split`](libft/srcs/str/ft_split.c)			          |	Split string, with specified character as delimiter, into an array of strings. |                         |
| [`ft_strmapi`](libft/srcs/str/ft_strmapi.c)			      | Create new string from modifying string with specified function.               |                         |

### Linked list functions

| Function                                            | Description                                                                    | Prototype               |
| ----------------------------------------------------- |:----------------------------------------------------------------------------:|-------------------------| 
| [`ft_lstnew`](libft/srcs/lst/ft_lstnew.c)				         | Create new list.                                                             |                         |  
| [`ft_lstsize`](libft/srcs/lst/ft_lstsize.c)			  	     | Count elements of a list                                                     |                         |
| [`ft_lstlast`](libft/srcs/lst/ft_lstlast.c)				       | Find last element of list                                                    |                         |
| [`ft_lstadd_back`](libft/srcs/lst/ft_lstadd_back.c)		 | Add new element at end of list                                               |                         |
| [`ft_lstadd_front`](libft/srcs/lst/ft_lstadd_front.c)	| Add new element at beginning of list                                         |                         |
| [`ft_lstdelone`](libft/srcs/lst/ft_lstdelone.c)				   | Delete element from list                                                     |                         |
| [`ft_lstclear`](libft/srcs/lst/ft_lstclear.c)				     | Delete sequence of elements of list from a starting point                    |                         |
| [`ft_lstiter`](libft/srcs/lst/ft_lstiter.c)						     | Apply function to content of all list's elements                             |                         |
| [`ft_lstmap`](libft/srcs/lst/ft_lstmap.c)					        | Apply function to content of all list's elements into new list               |                         |
