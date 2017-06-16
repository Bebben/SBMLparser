/*
** my_strlen.c for sbml in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 10:04:51 2017 benoit pingris
** Last update Mon Jun 12 10:05:03 2017 benoit pingris
*/

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    ++i;
  return (i);
}
