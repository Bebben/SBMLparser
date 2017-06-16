/*
** list_reaction.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 14 10:46:29 2017 benoit pingris
** Last update Wed Jun 14 13:13:02 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include "useful.h"
#include "macro.h"
#include "sbml.h"

int	get_reac_pos(char **tab, char *target)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (strstr(tab[i], target))
	return (i);
      ++i;
    }
  return (-FAILURE);
}

int	size_reac(char **tab, int i, char *s)
{
  int	nb;

  nb = 1;
  while (tab[i])
    {
      if (strstr(tab[i], s))
	return (nb);
      ++i;
      ++nb;
    }
  return (-FAILURE);
}

char	*get_line(char *s, char *find)
{
  int	i;
  int	j;
  int	tmp;
  char	*cpy;

  j = 0;
  i = 0;
  tmp = strlen(find) + 1;
  if ((cpy = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return (NULL);
  while (strncmp(&s[i], find, strlen(find)) != 0)
    ++i;
  if (!s[i + tmp])
    return (NULL);
  while (s[i + tmp] && s[i + tmp] != '"')
    {
      cpy[j] = s[i + tmp];
      ++j;
      ++tmp;
    }
  cpy[j] = '\0';
  return (cpy);
}

char	**get_comp(char **tab, int i, char *s1, char *s2)
{
  char	**comp;
  int	nb;
  int	h;

  h = 0;
  if ((comp = malloc(sizeof(char *) * (tab_len(tab) + 1))) == NULL ||
      (i = get_reac_pos(tab, s1)) == -FAILURE ||
      (nb = size_reac(tab, i, s2)) == -FAILURE)
    return (NULL);
  nb -= 2;
  ++i;
  while (nb > 0)
    {
      if ((comp[h] = get_line(tab[i], "species=")) == NULL)
	return (NULL);
      ++i;
      --nb;
      ++h;
    }
  comp[h] = NULL;
  sort_tab(comp);
  return (comp);
}

int	search_reaction(t_arr *arr, char **av)
{
  int	i;
  char	**composants;

  if (av[4] && strcmp(av[4], "-e") == 0)
    return (equation(arr));
  if ((i = get_reac_pos(arr->file, "reaction")) == -FAILURE)
    return (ERROR);
  if ((composants = (get_comp(arr->file, i, L_REAC, END_REAC))) == NULL)
    return (ERROR);
  else
    print_reaction(REAC, composants, av[3]);
  free_tab(composants);
  if ((composants = (get_comp(arr->file, i, L_PROD, END_PROD))) == NULL)
    return (ERROR);
  else
    print_reaction(PRODUCT, composants, av[3]);
  free_tab(composants);
  return (SUCCESS);
}
