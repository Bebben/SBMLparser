/*
** showtab.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 11:57:02 2017 benoit pingris
** Last update Tue Jun 13 11:40:19 2017 benoit pingris
*/

#include <string.h>
#include <unistd.h>

void	showtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      write(1, tab[i], strlen(tab[i]));
      write(1, "\n", 1);
      ++i;
    }
}
