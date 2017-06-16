/*
** format.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 16:13:09 2017 benoit pingris
** Last update Tue Jun 13 11:26:43 2017 benoit pingris
*/

#include <stdlib.h>
#include "useful.h"
#include "macro.h"

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

int	my_malloc(int len, t_arr *array)
{
  int	i;

  if (len == -1)
    return (ERROR);
  if ((array->tag = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (ERROR);
  i = 0;
  while (i < len)
    {
      if ((array->tag[i] = malloc(sizeof(char) *
				  (my_strlen(array->file[i]) + 1))) == NULL)
	return (ERROR);
      ++i;
    }
  return (SUCCESS);
}

char	*del_spaces(char *s)
{
  int	i;

  i = 0;
  while (s[i] == ' ' || s[i] == '\t')
    ++i;
  s = &s[i];
  return (s);
}

int	check_char(char a)
{
  return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
}

void	epur_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      tab[i] = del_spaces(tab[i]);
      ++i;
    }
}
