
# Part I

Categories: CheckList, Description, Documentation, Notes
Created: October 6, 2022 10:05 PM
Status: Open
Subject: Part%20I%20b6e7bef3921642ce80e894e8f2fb5d38/en.subject.pdf
Tags: Algorithms, C, Commun Core, Libft
Updated: December 25, 2022 9:11 AM

- [x]  memmove
    - Notes on ft_memmove
        - Prototype
            
            ```c
            void **ft_memmove*(void ****dest,*** const void ****src,*** size_t len)
            ```
            
        - Description
            
            memmove moves n bytes from src[ ] to dst[ ], it also handles the cases where the two arrays overlap.
            
        - Cases and important notes
            - There are 3 cases:
                - Case I: dest < src
                    
                    In this case the overlap is not relevant, since we’re always going to be ahead of dest in copying src to it , and no value will be lost .We start from the beginning of src and dest and we increment the index until n -1
                    
                    - Code snippet
                        
                        ```c
                        while (idx < n)
                        {
                        		newdest[idx] = newsrc[idx];
                        		idx++;
                        }
                        ```
                        
                    - Paper Note
                        
                        ![20221008_183621.jpg](Part%20I%20b6e7bef3921642ce80e894e8f2fb5d38/20221008_183621.jpg)
                        
                - Case II: src < dest
                    
                    In this case the overlp is relevent since src proceeds dst , if we start copying from the start of src , some values will be lost since src shares a chunk of dest ,
                    
                    to avoid this we start from n - 1 (index of number of bytes we want to copy),
                    
                    and we start decrimenting until we arraive at the start of the two arrays
                    
                    - Code snippit
                        
                        ```c
                        while (n > 0)
                        {
                        			newdest[n - 1] = newsrc[n - 1];
                        			n--;
                        }
                        ```
                        
                    - Paer Note
                        
                        ![20221008_183648.jpg](Part%20I%20b6e7bef3921642ce80e894e8f2fb5d38/20221008_183648.jpg)
                        
                - Case III: src == dest or n == 0
                    
                    in this case we need not do anything since the overlap is at the start 
                    
                    we return dest / in case of n == 0 , there is nothing to copy
                    
                    - Code snippit
                        
                        ```c
                        if (dest == src || !n)
                        		return (dest);
                        ```
                        
                    - Paper Note
                        
                        ![20221008_183707.jpg](Part%20I%20b6e7bef3921642ce80e894e8f2fb5d38/20221008_183707.jpg)
                        
        - My Implementation
            
            ```c
            static void     write_from_start(unsigned char *dest,
                                    unsigned char *source, size_t len)
            {
                    size_t  i;
            
                    i = 0;
                    while (i < len)
                    {
                            dest[i] = source[i];
                            i++;
                    }
            }
            
            static void     write_from_end(unsigned char *dest,
                                    unsigned char *source, size_t len)
            {
                    while (len > 0)
                    {
                            dest[len - 1] = source[len - 1];
                            len--;
                    }
            }
            
            void    *ft_memmove(void *dst, const void *src, size_t len)
            {
                    unsigned char   *source;
                    unsigned char   *dest;
            
                    source = (unsigned char *)src;
                    dest = (unsigned char *)dst;
                    if (dst == src)
                            return (dst);
                    if (dst < src)
                            write_from_start(dest, source, len);
                    else
                            write_from_end(dest, source, len);
                    return (dst);
            }
            ```
            
- [x]  memcpy
    - Notes on ft_memcpy
        - Prototype
            
            ```c
            void *ft_memcpy(void *dest, const void *src , size_t n);
            ```
            
        - Description
            
            The memcpy copies n bytes from memory area src to memory area dest.  It does not handle overlap of src and dest , if the two arrays roverlap in memory ,i should  use memmove();
            
            - Cases
                - if src == dest or n == 0
                    - we return dest unchanged.
                - else we copy n bytes from src to dst
        - My Implementation
            
            ```c
            void    *ft_memcpy(void *dst, const void *src, size_t n)
            {
                    size_t  i;
            
                    i = 0;
                    if (dst == src || !n)
                            return (dst);
                    while (i < n)
                    {
                            *((unsigned char *)dst + i) = *((unsigned char *)src + i);
                            i++;
                    }
                    return (dst);
            }
            ```
            
- [x]  memset
    - Notes on ft_memset
        - Prototype
            
            ```c
            memset(void *b, int c, size_t len);
            ```
            
        - Description
            
            memset writes len number of bytes of value c (conveted to unsigned char)
            
        - My Implementation
            
            ```c
            void    *ft_memset(void *b, int c, int len)
            {
                    int     i;
            
                    i = 0;
                    while (i < len)
                    {
                            *((unsigned char *)b + i) = (unsigned char)c;
                            i++;
                    }
                    return (b);
            }
            ```
            
- [x]  isalpha
    - Notes on ft_islapha
        - Prototype
            
            ```c
            int     ft_isalpha(int c);
            ```
            
        - Description
            
            checks if c is an alphabet .
            
        - My Implementation
            
            in my implementation i checked if its either upper or lower.
            
            ```c
            int     ft_isalpha(int c)
            {
                    if (ft_islower(c) || ft_isupper(c))
                            return (1);
                    return (0);
            }
            ```
            
- [x]  is_lower
    - Notes on ft_islower
        - Prototype
            
            ```c
            int     ft_islower(int c);
            ```
            
        - Description
            
            checks if c is lowercase.
            
        - My Implementation
            
            ```c
            int     ft_islower(int c)
            {
                    if (c >= 'a' && c <= 'z')
                            return (c);
                    return (0);
            }
            ```
            
- [x]  is_upper
    - Notes on ft_isupper
        - Prototype
            
            ```c
            int     ft_isupper(int c);
            ```
            
        - Description
            
            checks if c is uppercase.
            
        - My Implementation
            
            ```c
            int     ft_isupper(int c)
            {
                    if (c >= 'A' && c <= 'Z')
                            return (c);
                    return (0);
            }
            ```
            
- [x]  isdigit
    - Notes on ft_islower
        - Prototype
            
            ```c
            int     ft_isupper(int c);
            ```
            
        - Description
            
            checks if c is uppercase.
            
        - My Implementation
            
            ```c
            int     ft_isupper(int c)
            {
                    if (c >= 'A' && c <= 'Z')
                            return (c);
                    return (0);
            }
            ```
            
- [x]  isalnum
    - Notes on ft_isalnum
        - Prototype
            
            ```c
            int     ft_isalnum(int c);
            ```
            
        - Description
            
            checks if c is either an alphabet or a number
            
        - My Implementation
            
            ```c
            int     ft_isalnum(int c)
            {
                    if (ft_isalpha(c) || ft_isdigit(c))
                            return (1);
                    return (0);
            }
            ```
            
- [x]  isascii
    - Notes on ft_isascii
        - Prototype
            
            ```c
            int     ft_isascii(int c)
            ```
            
        - Description
            
            checks if c is an ascii character
            
        - My Implementation
            
            ```c
            int     ft_isascii(int c)
            {
                    if (c >= 0 && c <= 127)
                            return (1);
                    return (0);
            }
            ```
            
- [x]  isprint
    - Notes on ft_isprint
        - Prototype
            
            ```c
            int     ft_isprint(int c);
            ```
            
        - Description
            
            checks if c is in range of printable ascii characters  32 ≤ c ≤ 126.
            
        - My Implementation
            
            ```c
            int     ft_isprint(int c)
            {
                    if (c >= 32 && c <= 126)
                            return (c);
                    return (0);
            }
            ```
            
- [x]  strlen
    - Notes on ft_strlen
        - Prototype
            
            ```c
            size_t  ft_strlen(const char *s);
            ```
            
        - Description
            
            Counts string length.
            
        - My Implementation
            
            ```c
            size_t  ft_strlen(const char *s)
            {
                    int     i;
            
                    i = 0;
                    while (s[i])
                            i++;
                    return (i);
            }
            ```
            
- [x]  bzero
    - Notes on ft_bzero
        - Prototype
            
            ```c
            void    ft_bzero(void *s, size_t n)
            ```
            
        - Description
            
            Sets n bytes of string to NULL.
            
        - My Implementation
            
            ```c
            void    ft_bzero(void *s, size_t n)
            {
                    if (n > 0)
                            ft_memset(s, '\0', n);
            }
            ```
            
- [x]  strlcpy
    - Notes on ft_strlcpy
        - Prototype
            
            ```c
            size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
            ```
            
        - Description
            
            Copies src to dest while respecting dst buffer size (dstsize) , returns len of the string it tied to create (srclen)
            
        - My Implementation
            
            ```c
            size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
            {
                    size_t  srclen;
                    size_t  i;
            
                    i = 0;
                    srclen = ft_strlen(src);
                    if (dstsize == 0)
                            return (srclen);
                    while (i < dstsize - 1 && src[i])
                    {
                            dst[i] = src[i];
                            i++;
                    }
                    dst[i] = '\0';
                    return (srclen);
            }
            ```
            
- [ ]  strlcat
- [x]  toupper
    - Notes on ft_toupper
        - Prototype
            
            ```c
            int     ft_toupper(int c);
            ```
            
        - Description
            
            Checks if c is lowercase alpha and conversts it to its uppercase equivalent.
            
        - My Implementation
            
            ```c
            int     ft_toupper(int c)
            {
                    if (c >= 'a' && c <= 'z')
                            c = c - 32;
                    return (c);
            }
            ```
            
- [x]  tolower
    - Notes on ft_toupper
        - Prototype
            
            ```c
            int     ft_tolower(int c);
            ```
            
        - Description
            
            Checks if c is uppercase alpha and conversts it to its lowercase equivalent.
            
        - My Implementation
            
            ```c
            int     ft_toupper(int c)
            {
                    if (c >= 'a' && c <= 'z')
                            c = c - 32;
                    return (c);
            }
            ```
            
- [x]  strchr
    - Notes on ft_strchr
        - Prototype
            
            ```c
            char    *ft_strchr(const char *s, int c)
            ```
            
        - Description
            
            looks for the first accurence of c (’\0’ included) in s and returns a pointer to its adresse .
            
        - My Implementation
            
            ```c
            char    *ft_strchr(const char *s, int c)
            {
                    int     i;
                    int     slen;
            
                    i = 0;
                    slen = ft_strlen((const char *)s);
                    if (c == '\0')
                            return ((char *)s + slen);
                    while (s[i])
                    {
                            if (s[i] == c)
                                    return ((char *)s + i);
                            i++;
                    }
                    return (0);
            }
            ```
            
- [x]  strrchr
    - Notes on ft_strrchr
        - Prototype
            
            ```c
            char    *ft_strrchr(const char *s, int c)
            ```
            
        - Description
            
            looks for the last accurence of c (’\0’ included) in s and returns a pointer to its adresse .
            
        - My Implementation
            
            ```c
            char    *ft_strrchr(const char *s, int c)
            {
                    int     slen;
            
                    slen = ft_strlen(s);
                    while (slen >= 0)
                    {
                            if (s[slen] == c)
                                    return ((char *)s + slen);
                            slen--;
                    }
                    return (0);
            }
            ```
            
- [x]  strncmp
    - Notes on ft_strncmp
        - Prototype
            
            ```c
            int     ft_strncmp(const char *s1, const char *s2, size_t n)
            ```
            
        - Description
            
            compares n bytes of s1 and s2 and returns the diffrence.
            
        - My Implementation
            
            ```c
            int     ft_strncmp(const char *s1, const char *s2, size_t n)
            {
                    size_t  i;
            
                    i = 0;
                    if (!n)
                            return (0);
                    while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
                            i++;
                    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
            }
            ```
            
- [x]  memchr
    - Notes on ft_memchr
        - Prototype
            
            ```c
            void    *ft_memchr(const void *s, int c, size_t n);
            ```
            
        - Description
            
            searches n bytes in s from c ,and returns a pointer to its adresse , if not exist returns NULL pointer
            
        - My Implementation
            
            ```c
            void    *ft_memchr(const void *s, int c, size_t n)
            {
                    size_t  i;
            
                    i = 0;
                    while (i < n)
                    {
                            if (*((unsigned char *)s + i) == (unsigned char)c)
                                    return (((void *)s + i));
                            i++;
                    }
                    return (NULL);
            }
            ```
            
- [x]  memcmp
    - Notes on ft_memcmp
        - Prototype
            
            ```c
            int     ft_memcmp(const void *s1, const void *s2, size_t n);
            ```
            
        - Description
            
            compares n bytes of s1 and s2 and returns the first diffrence
            
        - My Implementation
            
            ```c
            int     ft_memcmp(const void *s1, const void *s2, size_t n)
            {
                    unsigned char   *src1;
                    unsigned char   *src2;
                    size_t                  i;
            
                    src1 = (unsigned char *)s1;
                    src2 = (unsigned char *)s2;
                    i = 0;
                    if (!n)
                    {
                            return (0);
                    }
                    while (i < n - 1 && src1[i] == src2[i])
                            i++;
                    return (src1[i] - src2[i]);
            }
            ```
            
- [x]  strnstr
    - Notes on ft_strnstr
        - Prototype
            
            ```c
            char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
            ```
            
        - Description
            
            Looks for the **needle** in n bytes of the **haystack** and returns the first index of its accurence (needle) , if not exist returns NULL pointer , if **needle == haystack** || !**needle** we return the **haystack**
            
        - My Implementation
            
            ```c
            char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
            {
                    size_t  i;
                    size_t  j;
            
                    i = 0;
                    j = 0;
                    if (!needle[0])
                            return ((char *)haystack);
                    if (haystack == needle)
                            return ((char *)haystack);
                    while (i < len && haystack[i])
                    {
                            j = 0;
                            while (needle[j] == haystack[i] && needle[j] && i < len)
                            {
                                    j++;
                                    i++;
                            }
                            if (needle[j] == '\0')
                                    return ((char *)haystack + i - j);
                            i++;
                    }
                    return (0);
            }
            ```
            
- [ ]  atoi
    - Notes on atoi
        - Prototype
            
            ```c
            int atoi(const char *str);
            ```
            
        - Description
            
            takes array of chars and conversts it to it’s int representation
            
            - Cases
                - **unprintable control codes (0 to 32 in ascii)**
                    
                    we skip over these characters
                    
                - current index is ‘+’ or minus
                    
                    if ‘+’ sign is positive 
                    
                    if ‘-’ sign is negative
                    
                - while current index is  0<curentelement<9
                    
                    we conver it to its int representaiton
                    
        - My implementation
            
            ```c
            int ft_atoi(const char *str)
            {
            	int i;
            	int sign;
            	int res;
            	
            	i = 0;
            	sign = 1;
            	res = 0;
            	while(str[i] && str[i] <= 32)
            		i++;
            	if(str[i] == '-'){
            		sign = -1;
            		i++;
            	}
            	else if(str[i] == '+'){
            		sign = 1;
            		i++;
            	}
            	while(str[i] && str[i] >= '0' && str[i] <= '9'){
            		res = res * 10 + (str[i] - '0');
            		i++;
            	}
            	return res * sign;
            }
            ```
            
- [x]  calloc
    - Notes on ft_calloc
        - Prototype
            
            ```c
            void    *ft_calloc(size_t count, size_t size);
            ```
            
        - Description
            
            Allocates **count * size bytes** of memory and returns a pointer the first adress of the allocation , if allocation fails we return NULL pointer.
            
        - My Implementation
            
            ```c
            void    *ft_calloc(size_t count, size_t size)
            {
                    void    *buffer;
            
                    buffer = malloc(count * size);
                    if (!buffer)
                            return (0);
                    ft_bzero(buffer, count * size);
                    return (buffer);
            }
            ```
            
- [x]  strdup
    - Notes on ft_strdup
        - Prototype
            
            ```c
            char    *ft_strdup(const char *s1);
            ```
            
        - Description
            
            Takes a pointer to a string , creates a new string allocates its mem and returns it , if allocation fails we return NULL pointer.
            
        - My Implementation
            
            ```c
            char    *ft_strdup(const char *s1)
            {
                    char    *res;
                    int             slen;
            
                    slen = ft_strlen(s1) + 1;
                    res = (char *)malloc(slen * sizeof(char));
                    if (!res)
                            return (0);
                    ft_memset(res, '\0', slen);
                    return ((char *)ft_memmove(res, s1, slen));
            }
            ```
            
- [x]  memccpy
    - Notes on ft_memccpy
        - Prototype
            
            ```c
            void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
            ```
            
        - Description
            
            T
            
        - My Implementation
            
            ```c
            char    *ft_strdup(const char *s1)
            {
                    char    *res;
                    int             slen;
            
                    slen = ft_strlen(s1) + 1;
                    res = (char *)malloc(slen * sizeof(char));
                    if (!res)
                            return (0);
                    ft_memset(res, '\0', slen);
                    return ((char *)ft_memmove(res, s1, slen));
            }
            ```
