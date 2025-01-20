/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:35:44 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:47:48 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct s_list_ps
{
	int					id;
	int					org_value;
	struct s_list_ps	*next;
}						t_list_ps;

void					isinputcorrect(int argc, char **argv,
							char **normal_argv, int argc2);
void					error_output(char **argv);
t_list_ps				*stackaset(int argc, char **argv);
char					**ft_normalize_argv(int argc, char **argv, int *k);
int						ft_lstsize_ps(t_list_ps *lst);
void					ft_lstclear_ps(t_list_ps **lst);
t_list_ps				*ft_lstnew_ps(int v);
void					p_aorb(t_list_ps **a, t_list_ps **b);
void					ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
t_list_ps				*ft_lstlast_ps(t_list_ps *lst);
void					ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
void					r_aorb(t_list_ps **rotate);
void					threeelementsort(t_list_ps **a, int size, int flag);
int						issorted(t_list_ps *a);
void					rr_aorb(t_list_ps **rotate);
void					s_aorb(t_list_ps **swap);
char					*get_next_line(int fd);
void					rr(t_list_ps **a, t_list_ps **b);
void					rrr(t_list_ps **a, t_list_ps **b);
void					ss(t_list_ps **a, t_list_ps **b);
#endif