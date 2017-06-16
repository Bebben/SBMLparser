/*
** parser.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 13:17:48 2017 benoit pingris
** Last update Wed Jun 14 11:30:01 2017 benoit pingris
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "useful.h"
#include "macro.h"
#include "sbml.h"

int	get_tag(t_arr *arr)
{
  int	i;
  int	h;

  h = 0;
  i = 0;
  epur_tab(arr->file);
  while (arr->file[i])
    {
      if (arr->file[i][0] == '<' && check_char(arr->file[i][1]) == 1)
	{
	  arr->tag[h] = arr->file[i];
	  ++h;
	}
      ++i;
    }
  arr->tag[h] = NULL;
  return (SUCCESS);
}

char	*get_begin(char *s)
{
  char	*cpy;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((cpy = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return (NULL);
  while (s[i] && s[i] != ' ')
    {
      cpy[j] = s[i];
      ++j;
      ++i;
    }
  cpy[j] = '\0';
  return (cpy);
}

int	is_in_tab(char *s, char **tab)
{
  int	i;
  char	*b_tag;

  i = 0;
  if ((b_tag = get_begin(s)) == NULL)
    return (ERROR);
  while (tab[i])
    {
      if (strncmp(tab[i], b_tag, strlen(b_tag)) == 0)
	{
	  free(b_tag);
	  return (ERROR);
	}
      ++i;
    }
  free(b_tag);
  return (SUCCESS);
}

int	specific_tag(t_arr *arr)
{
  int	i;
  int	h;

  h = 0;
  i = 0;
  if ((arr->final = malloc(sizeof(char *) * (tab_len(arr->tag) + 1))) == NULL)
    return (ERROR);
  arr->final[0] = NULL;
  while (arr->tag[i])
    {
      if (is_in_tab(arr->tag[i], arr->final) == SUCCESS)
	{
	  arr->final[h] = strdup(arr->tag[i]);
	  arr->final[++h] = NULL;
	}
      ++i;
    }
  arr->final[h] = NULL;
  return (SUCCESS);
}

int	print_tag(t_arr *arr, int i)
{
  int	h;

  if (tab_len(arr->id) == 0)
    return (STOP);
  h = 1;
  while (arr->final[i][h] && arr->final[i][h] != ' ')
    {
      my_putchar(arr->final[i][h]);
      ++h;
    }
  write(1, "\n", 1);
  showid(arr->id);
  return (SUCCESS);
}
