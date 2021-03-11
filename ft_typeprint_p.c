/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeprint_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:23:52 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:09:14 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_print_0x(void)
{
	ft_putchar('0', 1);
	ft_putchar('x', 1);
}

static void			noflags(const char *str, int len, t_print box)
{
	if (box.width >= 0)
	{
		ft_putspace(box);
		ft_print_0x();
	}
	if (box.width < 0 && box.prec == 0)
		ft_print_0x();
	if (box.prec > 0)
	{
		ft_print_0x();
		ft_putzero(box);
	}
	ft_putstr(str, len);
}

static void			flgzero(const char *str, int len, t_print box)
{
	ft_print_0x();
	while (box.width-- > 0)
		ft_putchar('0', 1);
	ft_putstr(str, len);
}

static void			flgminus(const char *str, int len, t_print box)
{
	ft_print_0x();
	if (box.prec != -1)
		ft_putzero(box);
	ft_putstr(str, len);
	if (box.width < 0)
		return ;
	ft_putspace(box);
}

int					ft_typeprint_p(unsigned long nbr, t_print box)
{
	int		len;
	char	*str;

	if (box.prec == 0 && nbr == 0)
	{
		ft_print_0x();
		return (-1);
	}
	if (!(str = ft_itoa_base(nbr, 16, box)))
		return (0);
	len = ft_strlen(str);
	box.flagzero = (box.flagzero == 0 || (box.prec >= 0 || box.flagminus) ||
					(box.flagminus && box.prec >= 0) ? 0 : 1);
	box.prec = box.prec > len ? box.prec - len : 0;
	box.width = box.prec + len < box.width ? box.width - (box.prec + len) - 2 :
				box.width - len - box.prec - 2;
	if (box.flagminus)
		flgminus(str, len, box);
	else if (box.flagzero == 1)
		flgzero(str, len, box);
	else if (box.flagminus == 0 && box.flagzero == 0)
		noflags(str, len, box);
	free(str);
	return (1);
}
