/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflibft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:20:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/11/01 12:59:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		width;
	int		dot_size;
	int		zero_or_space;
	int		after_or_before;
	int		space_plus;
	int		alternative;
	int		type_to_print;
	int		print_length;
}			t_flags;

typedef struct s_trueprint
{
	int		space_before_value;
	char	sign;
	int		zerox;
	int		zero_before_value;
	int		space_after_value;
}			t_trueprint;

typedef struct s_vavalue
{
	int				value_int;
	unsigned int	value_unint;
	void			*value_pointer;
	char			*value_string;
}					t_vavalue;

int		ft_printf(const char *s, ...);

void	ft_flagreset(t_flags *flag);
int		ft_flagsset(const char *s, t_flags *flag);
int		ft_mstrchr(const char *s, char c);
void	ft_trueprintreset(t_trueprint *tp);
void	ft_trueprintset(t_flags *flags, va_list *args, \
t_trueprint *tp, t_vavalue *material);
void	ft_vavaluereset(t_vavalue *vv);
void	ft_vavalueset(t_vavalue *vavalue, va_list *args, t_flags *flags);

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

int		ft_charsize(char value);
int		ft_stringsize(char *value);
int		ft_deciintsize(int value, t_flags *flags);
int		ft_hexasize(unsigned int value, t_flags *flags);
int		ft_pointersize(void *value);
int		ft_unsintsize(unsigned int value, t_flags *flags);

void	ft_vputstr(char *s, t_flags *flags);
void	ft_vputchar(char c, t_flags *flags);
void	ft_puthexa(unsigned int n, t_flags *flags);
void	ft_puthexau(unsigned int n, t_flags *flags);
void	ft_putunsnbr(unsigned int n, t_flags *flags);
void	ft_putnbr(long n, t_flags *flags);
void	ft_percentprinter(char c, t_flags *flags);
void	ft_lenputstr(char *s, t_flags *flags, int len);
void	ft_putpointer(void *nb, t_flags *flags);
#endif