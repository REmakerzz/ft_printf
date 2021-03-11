/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:57:35 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 19:55:17 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_print
{
	int			width;
	int			i;
	int			prec;
	int			flagminus;
	int			flagzero;
	char		type;
	char		*null;
}				t_print;

int				ft_printf(const char *str, ...);
int				ft_putchar(char ch, int flag);
int				ft_strlen(const char *str);
int				ft_parse_flags(const char *str, t_print *box, va_list ap);
int				ft_parse_pricision(const char *str, t_print *box, va_list ap);
char			*ft_itoa_base(unsigned long nbr, int base, t_print box);
int				ft_typeprint_d_i(long nbr, t_print box);
void			ft_typeprint_c(char ch, t_print box);
void			ft_typeprint_s(const char *str, t_print box);
int				ft_typeprint_xx(unsigned int nbr, t_print box);
int				ft_typeprint_u(unsigned int nbr, t_print box);
int				ft_typeprint_p(unsigned long nbr, t_print box);
void			ft_putstr(const char *str, int len);
void			ft_putspace(t_print box);
void			ft_putzero(t_print box);
void			ft_boxinit(t_print *box, int len);

#endif
