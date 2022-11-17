#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
char *get_next_line(int fd);
void read_and_store(int fd, t_list **stored, int *readcount);
int found_newline(t_list *stored);
void add_to_store(t_list **stored, char *buffer, int readcount);
void extract_line(t_list *stored, char **line);
void make_line(char **line, t_list *stored);
void clean_stored(t_list **stored);
void free_stored(t_list *stored);
t_list *ft_lstlast(t_list *lst);
size_t ft_strlen(const char *s);
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstdelone(t_list *lst, void (*del)(void *));
#endif
