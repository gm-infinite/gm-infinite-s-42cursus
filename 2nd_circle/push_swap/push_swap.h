/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:35:44 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:51:05 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

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
int						ft_lstsize_ps(t_list_ps *lst);
void					ft_lstclear_ps(t_list_ps **lst);
t_list_ps				*ft_lstnew_ps(int v);
void					p_aorb(int ab, t_list_ps **a, t_list_ps **b);
void					ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
t_list_ps				*ft_lstlast_ps(t_list_ps *lst);
void					ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
void					r_aorb(int ab, t_list_ps **rotate);
void					threeelementsort(t_list_ps **a, int size, int flag);
int						issorted(t_list_ps **a, int asize);
void					rr_aorb(int ab, t_list_ps **rotate);
void					s_aorb(int ab, t_list_ps **swap);
void					ft_turk_alg(t_list_ps **a, t_list_ps **b);
int						ft_abs(int k);
int						value_calc(int a, int b);
int						getbvalue(t_list_ps *a, t_list_ps *b, int size,
							int rot);
void					ft_turk_alg_pb(t_list_ps **b, t_list_ps **a);
int						getavalue(t_list_ps *a, t_list_ps *b, int size,
							int rot);
char					**ft_normalize_argv(int argc, char **argv, int *k);
#endif