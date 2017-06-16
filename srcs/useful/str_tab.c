/*
** requirement.c for requirement in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 09:44:09 2017 benoit pingris
** Last update Mon Jun 12 17:44:03 2017 benoit pingris
*/

#include <stdlib.h>
#include "useful.h"

char	**malloc_all(char *s)
{
  char **tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (my_strlen(s) + 1))) == NULL)
    return (NULL);
  while (i < my_strlen(s))
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(s) + 1))) == NULL)
	return (NULL);
      ++i;
    }
  return (tab);
}

char	**str_tab(char *s)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((tab = malloc_all(s)) == NULL)
    return (NULL);
  while (s[i])
    {
      k = 0;
      while (s[i] == ' ')
	++i;
      while (s[i] && s[i] != ' ')
	tab[j][k++] = s[i++];
      tab[j++][k] = '\0';
    }
  if (my_strlen(tab[--j]) == 0)
    tab[j] = NULL;
  else
    tab[++j] = NULL;
  return (tab);
}
