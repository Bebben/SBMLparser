/*
** free.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 16:08:21 2017 benoit pingris
** Last update Tue Jun 13 13:24:36 2017 benoit pingris
*/

#include <stdlib.h>
#include "useful.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}

void	free_struc(t_arr *arr)
{
  free(arr->file);
  free(arr->tag);
  free_tab(arr->final);
}
