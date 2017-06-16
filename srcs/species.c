/*
** species.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 14 10:29:18 2017 benoit pingris
** Last update Wed Jun 14 12:38:52 2017 benoit pingris
*/

#include "useful.h"
#include "macro.h"

void	list_species(char *s, t_find *find)
{
  my_printf(LIST_SPECIES, s);
  showid(find->name);
}

int	search_species(t_arr *arr, t_find *find, char **av)
{
  if (find_names(arr, find) == ERROR)
    return (ERROR);
  list_species(av[3], find);
  return (SUCCESS);
}

int	print_reaction(char *s, char **tab, char *name)
{
  my_printf("List of %s of reaction %s\n", s, name);
  sort_tab(tab);
  showid(tab);
  return (ERROR);
}
