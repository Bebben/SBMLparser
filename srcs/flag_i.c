/*
** flag_i.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 13 09:46:47 2017 benoit pingris
** Last update Wed Jun 14 12:47:45 2017 benoit pingris
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sbml.h"
#include "macro.h"
#include "useful.h"

int	set_struct(t_find *find, t_arr *arr)
{
  find->id = NULL;
  find->target = NULL;
  if ((find->name = malloc(sizeof(char *) * (tab_len(arr->tag) + 1))) == NULL)
    return (ERROR);
  find->name[0] = NULL;
  return (SUCCESS);
}

int	find_i(char **av, t_arr *arr, t_find *find)
{
  int	ret;

  ret = 0;
  if (strcmp(av[2], "-i") != SUCCESS || set_struct(find, arr) == ERROR)
    return (ERROR);
  if (av[3])
    if ((find->id = malloc(sizeof(char) * (strlen(av[3]) + 20))) == NULL ||
	sprintf(find->id, "id=\"%s\"", av[3]) < 0 ||
	find_target(arr, find) == ERROR)
      return (ERROR);
  if (!av[3] || find->target == NULL)
    return (search_default(arr, find));
  if (sprintf(find->target, "%s=\"%s\"", find->target, av[3]) < 0)
    return (ERROR);
  if (strstr(find->target, "compartment"))
    ret = search_species(arr, find, av);
  else if (strstr(find->target, "reaction"))
    ret = search_reaction(arr, av);
  else if (strstr(find->target, "species"))
    ret = search_products(arr, find, av);
  if (ret == ERROR)
    search_default(arr, find);
  free(find->id);
  free(find->target);
  return (ret);
}
