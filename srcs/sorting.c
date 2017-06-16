/*
** sorting.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 16:18:36 2017 benoit pingris
** Last update Mon Jun 12 19:27:23 2017 benoit pingris
*/

#include "useful.h"

int	sort_tab(char **tab)
{
  char	*s;
  int	times;
  int	i;

  times = tab_len(tab) * tab_len(tab);
  while (times != 0)
    {
      i = 0;
      while (tab[i])
	{
	  if (tab[i + 1] && my_strcmp(tab[i], tab[i + 1]) > 0)
	    {
	      s = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = s;
	    }
	  ++i;
	}
      --times;
    }
  return (0);
}
