/*
** struct.h for sbml in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 10:46:38 2017 benoit pingris
** Last update Tue Jun 13 15:28:48 2017 benoit pingris
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_arr
{
  char		**file;
  char		**tag;
  char		**final;
  char		**id;
}		t_arr;

typedef struct	s_find
{
  char		*id;
  char		*target;
  char		**name;
}		t_find;

#endif /* !STRUCT_H_ */
