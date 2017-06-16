/*
** reac.c for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 14 10:13:09 2017 benoit pingris
** Last update Wed Jun 14 10:58:57 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include "sbml.h"
#include "macro.h"

char	*find_id(char *s, char *id)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((id = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return (NULL);
  while (strncmp(&s[i], "id=", 3) != 0)
    ++i;
  if (!s[i + 4])
    return (NULL);
  while (s[i + 4] && s[i + 4] != '"')
    {
      id[j] = s[i + 4];
      ++j;
      ++i;
    }
  id[j] = '\0';
  return (id);
}

char	*id_reac(t_arr *arr, char *id)
{
  int	i;

  i = 0;
  while (arr->file[i])
    {
      if (strstr(arr->file[i], "reaction"))
	{
	  if ((id = find_id(arr->file[i], id)) == NULL)
	    return (NULL);
	  return (id);
	}
      ++i;
    }
  return (NULL);
}

int	end_reac(t_arr *arr, int i)
{
  if (strstr(arr->file[i], "</listOfReactants"))
    return (SUCCESS);
  return (ERROR);
}

int	position_reac(t_arr *arr)
{
  int	i;

  i = 0;
  while (arr->file[i])
    {
      if (strstr(arr->file[i], "<listOfReactants"))
	return (i);
      ++i;
    }
  return (-FAILURE);
}

char	**reac_tab(t_arr *arr, char **tab)
{
  int	k;
  int	i;

  if ((i = position_reac(arr)) == -FAILURE)
    return (NULL);
  ++i;
  k = 0;
  while (end_reac(arr, i) == ERROR)
    if ((tab[k++] = strdup(arr->file[i++])) == NULL)
      return (NULL);
  tab[k] = NULL;
  return (tab);
}
