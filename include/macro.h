/*
** macro.h for sbml in /home/benoit.pingris/delivery/SBMLparser/include
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 12 09:54:48 2017 benoit pingris
** Last update Wed Jun 14 12:38:30 2017 benoit pingris
*/

#ifndef MACRO_H_
# define MACRO_H_

# define STOP 1

# define L_PROD "listOfProducts"
# define END_PROD "/listOfProducts"
# define L_REAC "listOfReactants"
# define END_REAC "/listOfReactants"

# define PRODUCT "products"
# define REAC "reactants"
# define LIST_SPECIES "List of species in compartment %s\n"
# define LIST_REAC "List of reactions consuming species %s (quantities)\n"

# define FILE_ERR "Problem while opening the file.\n"
# define MEMORY_ERR "Problem while allocating memory.\n"
# define CLOSE_ERR "Problem while closing the file.\n"
# define HELP_FILE "help"

# define SAME 0
# define SUCCESS 0
# define FAILURE 1
# define ERROR 84

#endif /* !MACRO_H_ */
