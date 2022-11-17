#include "get_next_line.h"

char *get_next_line(int fd)
{
    static t_list *stored = NULL;
    char *line;
    int readcount;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (NULL);
    readcount = 1;
    line = NULL;
    // 1. read from fd and store in line
    read_and_store(fd, &stored, &readcount);
    // if there is no line, return NULL
    if (stored == NULL)
        return (NULL);
    // 2. extract from reserve and store in line
    extract_line(stored, &line);
    // 3. clean store
    clean_stored(&stored);
    // 4. determine if we are at the end of the file
    // if so we free the stored && free the line && return NULL
    if (line[0] == '\0' && readcount == 0)
    {
        free_stored(stored);
        stored = NULL;
        free(line);
        return (NULL);
    }
    // 5. return line
    return (line);
}

void free_stored(t_list *stash)
{
    t_list *current;
    t_list *next;

    current = stash;
    while (current)
    {
        free(current->content);
        next = current->next;
        free(current);
        current = next;
    }
}
