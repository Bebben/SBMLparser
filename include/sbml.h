/*
** sbml.h for sbml in /home/benoit.pingris/delivery/ADM_SBMLparser_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 12:03:19 2017 benoit pingris
** Last update Wed Jun 14 17:08:07 2017 benoit pingris
*/

#ifndef SBML_H_
# define SBML_H_

# include "struct.h"

char	**get_tab(char **);
char	**reac_tab(t_arr *, char **);

char	*id_reac(t_arr *, char *);
char	*get_line(char *, char *);

int	parser(t_arr *);
int	get_id(t_arr *);
int	get_tag(t_arr *);
int	specific_tag(t_arr *);
int	find_i(char **, t_arr *, t_find *);
int	print_tag(t_arr *, int);
int	find_target(t_arr *, t_find *);
int	find_names(t_arr *, t_find *);

int	search_species(t_arr *, t_find *, char **);
int	search_reaction(t_arr *, char **);
int	search_products(t_arr *, t_find *, char **);
int	search_default(t_arr *, t_find *);

int	species_name(t_arr *, t_find *);
int	print_reaction(char *, char **, char *);
int	check_stoec(char *);

int	is_reversible(char **);
int	show_equation(char **, char **, int, int);
int	equation(t_arr *);
int	get_reac_pos(char **, char *);
int	size_reac(char **, int, char *);

char	**get_comp(char **, int, char *, char *);

#endif /* !SBML_H_ */
