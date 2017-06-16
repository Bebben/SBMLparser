/*
** search.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 13 19:05:32 2017 benoit pingris
** Last update Wed Jun 14 14:49:47 2017 benoit pingris
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sbml.h"
#include "macro.h"
#include "useful.h"

int	check_stoec(char *s)
{
  int	i;
  int	nb;

  i = 0;
  if (strstr(s, "stoichiometry=\"") == NULL)
    return (ERROR);
  while (&s[i] && strncmp(&s[i], "stoichiometry=\"", 15) != 0)
    ++i;
  if (!(s[i + 15]))
    return (-FAILURE);
  nb = atoi(&s[i + 15]);
  return (nb);
}

int	count_reac(char **tab, char *s)
{
  int	i;
  int	nb;

  i = 0;
  nb = -FAILURE;
  while (tab[i])
    {
      if (strstr(tab[i], s))
	return (nb = check_stoec(tab[i]));
      ++i;
    }
  return (nb);
}

int	search_products(t_arr *arr, t_find *find, char **av)
{
  int	nb;
  char	*id;
  char	**tab;

  id = NULL;
  if ((id = id_reac(arr, id)) == NULL ||
      (tab = malloc(sizeof(char *) * (tab_len(arr->file) + 1))) == NULL)
    return (ERROR);
  if ((tab = reac_tab(arr, tab)) == NULL)
    return (ERROR);
  nb = count_reac(tab, av[3]);
  if (nb != -FAILURE)
    {
      my_printf(LIST_REAC, av[3]);
      my_printf("----->%s (%d)\n", id, nb);
    }
  else
    search_default(arr, find);
  return (SUCCESS);
}

int	search_default(t_arr *arr, t_find *find)
{
  species_name(arr, find);
  write(1, "List of species\n", 16);
  showid(find->name);
  return (SUCCESS);
}
