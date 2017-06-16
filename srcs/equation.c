/*
** equation.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 14 13:11:51 2017 benoit pingris
** Last update Wed Jun 14 17:13:33 2017 benoit pingris
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "macro.h"
#include "useful.h"
#include "sbml.h"

int	is_reversible(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (strstr(tab[i], "reversible="))
	{
	  if (strstr(tab[i], "false"))
	    return (0);
	  else
	    return (1);
	}
      ++i;
    }
  return (-FAILURE);
}

int	show_equation(char **prod, char **reac, int rev, int i)
{
  int	nb;

  while (prod[i + 1])
    {
      if ((nb = check_stoec(prod[i])) == -FAILURE)
	return (ERROR);
      my_printf("%s + ", prod[i]);
      ++i;
    }
  my_printf("%s", prod[i]);
  i = 0;
  if (rev == 0)
    my_printf(" -> ");
  else
    my_printf(" <-> ");
  while (reac[i + 1])
    {
      if ((nb = check_stoec(reac[i])) == -FAILURE)
	return (ERROR);
      my_printf("%s + ", reac[i]);
      ++i;
    }
  my_printf("%s\n", reac[i]);
  return (SUCCESS);
}

char	*new_name(char *s, int i)
{
  char	*cpy;

  if ((cpy = malloc(sizeof(char) * (strlen(s) + 10))) == NULL)
    return (NULL);
  sprintf(cpy, "%d %s", i, s);
  free(s);
  return (cpy);
}

char	**nb_name(char **tab, int i, char *s1, char *s2)
{
  char	**comp;
  int	nb;
  int	h;
  int	stoech;

  h = 0;
  if ((comp = malloc(sizeof(char *) * (tab_len(tab) + 1))) == NULL ||
      (i = get_reac_pos(tab, s1)) == -FAILURE ||
      (nb = size_reac(tab, i, s2)) == -FAILURE)
    return (NULL);
  nb -= 2;
  ++i;
  while (nb > 0)
    {
      if ((stoech = check_stoec(tab[i])) == -FAILURE ||
	  (comp[h] = get_line(tab[i], "species=")) == NULL ||
	  (comp[h] = new_name(comp[h], stoech)) == NULL)
	return (NULL);
      ++i;
      --nb;
      ++h;
    }
  comp[h] = NULL;
  return (comp);
}

int	equation(t_arr *arr)
{
  char	**prod;
  char	**reac;
  int	i;
  int	rev;

  if ((i = get_reac_pos(arr->file, "reaction")) == -FAILURE ||
      (prod = nb_name(arr->file, i, L_REAC, END_REAC)) == NULL ||
      (reac = nb_name(arr->file, i, L_PROD, END_PROD)) == NULL)
    return (ERROR);
  sort_tab(prod);
  sort_tab(reac);
  if ((rev = is_reversible(arr->file)) == -FAILURE)
    return (ERROR);
  show_equation(prod, reac, rev, 0);
  return (0);
}

