/*
** revstr.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 18:53:46 2017 benoit pingris
** Last update Mon Jun 12 18:56:24 2017 benoit pingris
*/

#include <string.h>

char	*revstr(char *s)
{
  int	i;
  int	j;
  char	tmp;

  i = 0;
  j = strlen(s) - 1;
  while (i < j)
    {
      tmp = s[i];
      s[i++] = s[j];
      s[j--] = tmp;
    }
  return (s);
}
