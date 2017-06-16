/*
** my_putstr.c for sbml in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 10:03:58 2017 benoit pingris
** Last update Tue Jun 13 13:06:50 2017 benoit pingris
*/

#include <unistd.h>
#include "useful.h"

void	my_putchar(char a)
{
  write(1, &a, 1);
}

int	my_putstr(char *s, int stream, int ret)
{
  write(stream, s, my_strlen(s));
  return (ret);
}

char	**err_null(char *s)
{
  write(2, s, my_strlen(s));
  return (NULL);
}
