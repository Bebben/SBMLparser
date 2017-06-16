/*
** parser.c for whaou in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 10:52:32 2017 benoit pingris
** Last update Wed Jun 14 11:17:45 2017 benoit pingris
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "gnl.h"
#include "useful.h"
#include "macro.h"

int	get_size(char *file)
{
  int	fd;
  int	nb;
  char	*s;

  nb = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-FAILURE);
  while ((s = get_next_line(fd)))
    {
      free(s);
      ++nb;
    }
  if (close(fd) == -FAILURE)
    return (-FAILURE);
  return (nb);
}

char	**get_sbml(char *file)
{
  char	*s;
  char	**tab;
  int	fd;
  int	len;
  int	i;

  i = 0;
  if ((len = get_size(file)) == -FAILURE)
    return (err_null(FILE_ERR));
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (err_null(MEMORY_ERR));
  if ((fd = open(file, O_RDONLY)) == -1)
    return (err_null(FILE_ERR));
  while ((s = get_next_line(fd)))
    {
      if ((tab[i++] = strdup(s)) == NULL)
	return (NULL);
      free(s);
    }
  tab[i] = NULL;
  if (close(fd) == -FAILURE)
    return (NULL);
  return (tab);
}

char	**get_tab(char **av)
{
  char	**tab;

  if ((tab = get_sbml(av[1])) == NULL)
    return (NULL);
  return (tab);
}
