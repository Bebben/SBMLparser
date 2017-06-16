/*
** useful.h for sbml in /home/benoit.pingris/delivery/SBMLparser
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 10:05:24 2017 benoit pingris
** Last update Tue Jun 13 21:56:54 2017 benoit pingris
*/

#ifndef USEFUL_H_
# define USEFUL_H_

# include "sbml.h"

int	check_char(char);
int	disp_help(int);
int	tab_len(char **);
int	my_malloc(int, t_arr *);
int	my_strcmp(char *, char *);
int	my_strlen(char *);
int	my_putstr(char *, int, int);
int	sort_tab(char **);

char	**err_null(char *);
char	**str_tab(char *);

char	*del_spaces(char *);
char	*revstr(char *);

void	my_putchar(char);
void	showtab(char **);
void	free_struc(t_arr *);
void	free_tab();
void	epur_tab(char **);
void	showid(char **);

int	my_printf(char *, ...);

#endif /* !USEFUL_H_ */
