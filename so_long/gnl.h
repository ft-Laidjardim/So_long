#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

//Principal function
char	*get_next_line(int fd);

//Util functions
int		ft_strlen(char *str);
void	ft_getrest(char *buffer);
char	*ft_strchr(char *buffer, char c);
char	*ft_strjoin_free(char *line, char *buffer);

#endif