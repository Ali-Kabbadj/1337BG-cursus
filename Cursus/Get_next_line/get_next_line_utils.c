#include "get_next_line.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *lastnode;

    if (lst)
    {
        lastnode = lst;
        while (lastnode->next)
            lastnode = lastnode->next;
        return (lastnode);
    }
    return (0);
}

void read_and_store(int fd, t_list **stored, int *readcount)
{
    char *buffer;

    // while newline is not found && and there is something to read
    while (!found_newline(*stored) && *readcount != 0)
    {
        // allocate buffer with BUFFER_SIZE ,(+1) for '\0'
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (buffer == NULL)
            return;
        // read from fd and store in buffer
        // store number of bytes read in readcount
        *readcount = (int)read(fd, buffer, BUFFER_SIZE);
        if ((*stored == NULL && *readcount == 0) || *readcount < 0)
        {
            free(buffer);
            return;
        }
        // add '\0' to the end of buffer
        buffer[*readcount] = '\0';
        // add buffer to stored
        add_to_store(stored, buffer, *readcount);
        // free buffer for next read
        free(buffer);
    }
}

int found_newline(t_list *stored)
{
    t_list *last;
    char *str;
    int i;

    if (stored == NULL)
        return (0);
    last = ft_lstlast(stored);
    str = (char *)last->content;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

void add_to_store(t_list **stored, char *buffer, int readcount)
{
    int i;
    t_list *last;
    t_list *newnode;

    newnode = malloc(sizeof(t_list));
    if (newnode == NULL)
        return;
    newnode->next = NULL;
    newnode->content = malloc(sizeof(char) * (readcount + 1));
    if (newnode->content == NULL)
        return;
    i = 0;
    while (buffer[i] && i < readcount)
    {
        ((char *)newnode->content)[i] = buffer[i];
        i++;
    }
    ((char *)newnode->content)[i] = '\0';
    if (*stored == NULL)
    {
        *stored = newnode;
        return;
    }
    last = ft_lstlast(*stored);
    last->next = newnode;
}

void extract_line(t_list *stored, char **line)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (stored == NULL)
        return;
    make_line(line, stored);
    if (*line == NULL)
        return;
    while (stored)
    {
        i = 0;
        while (((char *)stored->content)[i] != '\0')
        {
            if (((char *)stored->content)[i] == '\n')
            {
                (*line)[j++] = ((char *)stored->content)[i];
                break;
            }
            (*line)[j++] = ((char *)stored->content)[i++];
        }
        stored = stored->next;
    }
    (*line)[j] = '\0';
}

void make_line(char **line, t_list *stored)
{
    int i;
    int len;

    len = 0;
    while (stored)
    {
        i = 0;
        while (((char *)stored->content)[i] != '\0')
        {
            if (((char *)stored->content)[i] == '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        stored = stored->next;
    }
    *line = malloc(sizeof(char) * (len + 1));
    if (*line == NULL)
        return;
}

void clean_stored(t_list **stored)
{
    t_list *last;
    t_list *cleared;
    int i;
    int j;

    cleared = malloc(sizeof(t_list));
    if (stored == NULL || cleared == NULL)
        return;
    cleared->next = NULL;
    last = ft_lstlast(*stored);
    i = 0;
    j = 0;
    while (((char *)last->content)[i] != '\0' && ((char *)last->content)[i] != '\n')
        i++;
    if (((char *)last->content)[i] == '\n')
        i++;
    cleared->content = malloc(sizeof(char) * (ft_strlen(last->content) - i + 1));
    if (cleared->content == NULL)
        return;
    while (((char *)last->content)[i] != '\0')
    {
        ((char *)cleared->content)[j++] = ((char *)last->content)[i++];
    }
    ((char *)cleared->content)[j] = '\0';
    ft_lstclear(stored, free);
    *stored = cleared;
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *next;
    t_list *previous;

    if (lst && *lst && del)
    {
        previous = *lst;
        while (previous)
        {
            next = previous->next;
            ft_lstdelone(previous, del);
            previous = next;
        }
        *lst = NULL;
    }
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst && (*del))
    {
        (*del)(lst->content);
        free(lst);
    }
}