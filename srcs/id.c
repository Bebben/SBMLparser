/*
** id.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 19:28:39 2017 benoit pingris
** Last update Wed Jun 14 11:41:52 2017 benoit pingris
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "useful.h"
#include "macro.h"
#include "sbml.h"

int	count_equals(char *s)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (s[i])
    {
      if (s[i] == '=')
	++nb;
      ++i;
    }
  return (nb);
}

char	*get_equal(char *s, int restart)
{
  char		*cpy;
  static int	i;
  int	        h;

  h = 0;
  if (restart == 0)
    {
      i = strlen(s) - 1;
      return (NULL);
    }
  if ((cpy = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return (NULL);
  while (i >= 0 && s[i] != '=')
    --i;
  --i;
  while (i >= 0 && s[i] != ' ')
    cpy[h++] = s[i--];
  cpy[h] = '\0';
  cpy = revstr(cpy);
  return (cpy);
}

void	showid(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_printf("----->%s\n", tab[i]);
      ++i;
    }
}

int	print_id(t_arr *arr, int i)
{
  int	nb;
  int	h;

  h = 0;
  nb = count_equals(arr->final[i]);
  if ((arr->id = malloc(sizeof(char *) * (nb + 2))) == NULL)
    return (ERROR);
  get_equal(arr->final[i], 0);
  while (h < nb)
    {
      arr->id[h] = get_equal(arr->final[i], 1);
      ++h;
    }
  arr->id[h] = NULL;
  sort_tab(arr->id);
  return (SUCCESS);
}

int	get_id(t_arr *arr)
{
  int	i;

  i = 0;
  while (arr->final[i])
    {
      if (print_id(arr, i) == ERROR)
	return (ERROR);
      print_tag(arr, i);
      free_tab(arr->id);
      ++i;
    }
  return (SUCCESS);
}
