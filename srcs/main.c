/*
** main.c for sbml in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 10:01:17 2017 benoit pingris
** Last update Wed Jun 14 12:58:45 2017 benoit pingris
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "useful.h"
#include "macro.h"
#include "gnl.h"
#include "sbml.h"

int	parser(t_arr *arr)
{
  if (specific_tag(arr) == ERROR)
    return (ERROR);
  sort_tab(arr->final);
  get_id(arr);
  free_struc(arr);
  return (SUCCESS);
}

int	disp_help(int ret)
{
  char	*s;
  int	fd;

  if ((fd = open(HELP_FILE, O_RDONLY)) == -1)
    return (my_putstr(FILE_ERR, 2, FAILURE));
  while ((s = get_next_line(fd)))
    {
      my_putstr(s, 1, SUCCESS);
      my_putstr("\n", 1, SUCCESS);
      free(s);
    }
  if (close(fd) == -1)
    return (my_putstr(CLOSE_ERR, 2, FAILURE));
  return (ret);
}

int	set_tab(t_arr *arr)
{
  if ((my_malloc(tab_len(arr->file), arr)) == ERROR)
    return (my_putstr(MEMORY_ERR, 2, ERROR));
  if (get_tag(arr) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int	main(int ac, char **av)
{
  t_arr		arr;
  t_find	find;

  if (ac == 1)
    return (disp_help(ERROR));
  if (my_strcmp(av[1], "-h") == SAME)
    return (disp_help(SUCCESS));
  if ((arr.file = get_tab(av)) == NULL || set_tab(&arr) == ERROR)
    return (ERROR);
  if (ac == 2)
    return (parser(&arr));
  else if (ac == 3 || ac == 4 || ac == 5)
    return (find_i(av, &arr, &find));
  return (disp_help(ERROR));
}
