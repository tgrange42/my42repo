/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 02:10:49 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/09 05:05:30 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# define TEST ft_putendl("test");

char				**get_tetrominos(char *file_name);
void				error(void);
int					verif_options(int nbarg);
int					get_nb_tetro(char *file_name);
char				*get_this_tetro(int which_tetro, int fd);
int					verif_one(char *one);
char				**verif_tetros(char *file_name);
int					verif_chars(char **tetros);
int					tetro_or_not_tetro(char **tetro);
int					tetro_test(char *t);
char				*get_the_good_one(int which);
char				*get_the_good_one2(int which);
int					tetro_test(char *t);
void				put_it(char **lol);
int					tetro_test2(char *t, int i);
int					is_there_a_tetriminos(char *file_name);
int					*get_pos(char *t);
void				lets_do_this(char **tetros);
int					roger_that(int **pos, int posi, char *table, int letter);
void				t_free(void **t);
char				*do_a_table(char *table, int size);
int					this_can_enter(char *table, int *pos, int i);
void				place_this_shit(char *table, int *pos, int i, int letter);
void				debug(char *table, char letter);	
int					get_line(int i, int pos);
char				*clean_table(char *table, char letter);
int					get_actual_pos(char *table, int letter);
void				lulz(char *s);
void				exit_fillit(char *table, int **pos);
void				free_this_shit(int *fdp);
#endif
