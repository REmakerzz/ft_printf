/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeprint_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:13:27 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:09:43 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			voidarg(t_print box)
{
	ft_putspace(box);
	return ;
}

static void			noflags(const char *str, int len, t_print box)
{
	if (box.width > 0)
		ft_putspace(box);
	if (box.prec != -1)
		ft_putzero(box);
	ft_putstr(str, len);
}

static void			flgzero(const char *str, int len, t_print box)
{
	while (box.width-- > 0)
		ft_putchar('0', 1);
	ft_putstr(str, len);
}

static void			flgminus(const char *str, int len, t_print box)
{
	if (box.prec > 0)
		ft_putzero(box);
	ft_putstr(str, len);
	if (box.width < 0)
		return ;
	ft_putspace(box);
}

int					ft_typeprint_u(unsigned int nbr, t_print box)
{
	int		len;
	char	*str;

	if (box.prec == 0 && nbr == 0)
	{
		voidarg(box);
		return (-1);
	}
	if (!(str = ft_itoa_base(nbr, 10, box)))
		return (0);
	len = ft_strlen(str);
	box.flagzero = (box.flagzero == 0 || (box.prec >= 0 || box.flagminus) ||
					(box.flagminus && box.prec >= 0) ? 0 : 1);
	box.prec = box.prec > len ? box.prec - len : 0;
	box.width = box.prec + len < box.width ? box.width - (box.prec + len) :
				box.width - len - box.prec;
	if (box.flagminus)
		flgminus(str, len, box);
	else if (box.flagzero == 1)
		flgzero(str, len, box);
	else if (box.flagminus == 0 && box.flagzero == 0)
		noflags(str, len, box);
	free(str);
	return (1);
}
