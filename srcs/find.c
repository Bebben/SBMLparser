/*
** find.c for whaou in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 13 16:02:31 2017 benoit pingris
** Last update Wed Jun 14 11:29:11 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include "sbml.h"
#include "macro.h"
#include "useful.h"

char	*get_target(char *s)
{
  char	*cpy;
  int	i;
  int	j;

  j = 0;
  i = 1;
  if ((cpy = malloc(sizeof(char) * (strlen(s) + 20))) == NULL)
    return (NULL);
  while (s[i] && s[i] != ' ')
    cpy[j++] = s[i++];
  cpy[j] = '\0';
  return (cpy);
}

int	find_target(t_arr *arr, t_find *find)
{
  int	i;

  i = 0;
  while (arr->tag[i])
    {
      if (strstr(arr->tag[i], find->id) != NULL)
	{
	  if ((find->target = get_target(arr->tag[i])) == NULL)
	    return (ERROR);
	  return (SUCCESS);
	}
      ++i;
    }
  return (SUCCESS);
}

int	get_name(char *cpy, char *s)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (strncmp(&s[i], "name=", 5) != 0)
    ++i;
  if (!s[i + 6])
    return (ERROR);
  while (s[i + 6] && s[i + 6] != '"')
    {
      cpy[j] = s[i + 6];
      ++j;
      ++i;
    }
  cpy[j] = '\0';
  return (SUCCESS);
}

int	species_name(t_arr *arr, t_find *find)
{
  char	*cpy;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (arr->tag[i])
    {
      if (strstr(arr->tag[i], "name") && strstr(arr->tag[i], "<species "))
	{
	  if ((cpy = malloc(sizeof(char) * (strlen(arr->tag[i] + 1)))) == NULL)
	    return (ERROR);
	  if (get_name(cpy, arr->tag[i]) == SUCCESS)
	    {
	      if ((find->name[j] = strdup(cpy)) == NULL)
		return (ERROR);
	      find->name[++j] = NULL;
	    }
	  free(cpy);
	}
      ++i;
    }
  sort_tab(find->name);
  return (SUCCESS);
}

int	find_names(t_arr *arr, t_find *find)
{
  char	*cpy;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (arr->tag[i])
    {
      if (strstr(arr->tag[i], find->target) && strstr(arr->tag[i], "name") &&
	  strstr(arr->tag[i], "<species "))
	{
	  if ((cpy = malloc(sizeof(char) * (strlen(arr->tag[i] + 1)))) == NULL)
	    return (ERROR);
	  if (get_name(cpy, arr->tag[i]) == SUCCESS)
	    {
	      find->name[j] = strdup(cpy);
	      find->name[++j] = NULL;
	    }
	  free(cpy);
	}
      ++i;
    }
  sort_tab(find->name);
  return (SUCCESS);
}
