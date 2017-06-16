/*
** requirement.c for requirement in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 09:44:09 2017 benoit pingris
** Last update Wed Jun 14 10:03:06 2017 benoit pingris
*/

#include <stdlib.h>

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    ++i;
  return (i);
}

char	**my_malloc(char *s)
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

char	**my_strtowordtab_synthesis(char *s)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((tab = my_malloc(s)) == NULL)
    return (NULL);
  while (s[i])
    {
      k = 0;
      while (s[i] && !(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' &&
		       s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'))
	++i;
      while (s[i] && s[i] >= '0' && s[i] <= '9' ||
	     s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
	tab[j][k++] = s[i++];
      tab[j++][k] = '\0';
    }
  if (my_strlen(tab[--j]) == 0)
    tab[j] = NULL;
  else
    tab[++j] = NULL;
  return (tab);
}
