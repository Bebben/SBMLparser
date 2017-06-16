/*
** get_next_line.c for stumper5 in /home/benoit.pingris/CPE_2016_stumper5/srcs/get_next_line
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu May 18 14:26:35 2017 benoit pingris
** Last update Thu May 18 15:41:35 2017 benoit pingris
*/

#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

char	*free_ret(char *s)
{
  free(s);
  return (NULL);
}

char	*my_realloc(char *s)
{
  int	i;
  char	*new;

  i = 0;
  while (s[i] != '\0')
    ++i;
  if ((new = malloc(sizeof(char) * (i + READ_SIZE + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s[i] != '\0')
    {
      new[i] = s[i];
      ++i;
    }
  new[i] = '\0';
  free(s);
  return (new);
}

char	get_next_char(int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	len;
  static int	i;
  char		c;

  if (len == 0)
    {
      if ((len = read(fd, buff, READ_SIZE)) == 0)
	return ('\0');
      i = 0;
    }
  c = buff[i];
  ++i;
  --len;
  return (c);
}

char	*get_next_line(int fd)
{
  int	i;
  char	*line;
  char	c;

  i = 0;
  if ((line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  c = get_next_char(fd);
  while (c != '\n' && c != '\0')
    {
      line[i++] = c;
      c = get_next_char(fd);
      if (i % READ_SIZE == 0)
	{
	  line[i] = '\0';
	  if ((line = my_realloc(line)) == NULL)
	    return (NULL);
	}
    }
  line[i] = '\0';
  if (c == '\0' && line[0] == '\0')
    return (free_ret(line));
  return (line);
}
