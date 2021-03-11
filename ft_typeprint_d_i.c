/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeprint_d_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:43:45 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:09:00 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			voidarg(t_print box)
{
	ft_putspace(box);
	return ;
}

static void			noflags(const char *str, int len, t_print box, int mns)
{
	if (mns == 1)
		box.width--;
	if (box.width > 0)
		ft_putspace(box);
	if (mns == 1)
		ft_putchar('-', 1);
	if (box.prec > 0)
		ft_putzero(box);
	ft_putstr(str, len);
}

static void			flgzero(const char *str, int len, t_print box, int mns)
{
	if (mns == 1)
	{
		ft_putchar('-', 1);
		box.width--;
	}
	while (box.width-- > 0)
		ft_putchar('0', 1);
	ft_putstr(str, len);
}

static void			flgminus(const char *str, int len, t_print box, int mns)
{
	if (mns == 1)
	{
		ft_putchar('-', 1);
		box.width -= 1;
	}
	if (box.prec != -1)
		ft_putzero(box);
	ft_putstr(str, len);
	if (box.width < 0)
		return ;
	ft_putspace(box);
}

int					ft_typeprint_d_i(long nbr, t_print box)
{
	int		len;
	char	*str;
	int		mns;

	if (box.prec == 0 && nbr == 0)
	{
		voidarg(box);
		return (-1);
	}
	mns = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? (nbr * -1) : nbr;
	if (!(str = ft_itoa_base(nbr, 10, box)))
		return (0);
	len = ft_strlen(str);
	ft_boxinit(&box, len);
	if (box.flagminus)
		flgminus(str, len, box, mns);
	else if (box.flagzero == 1)
		flgzero(str, len, box, mns);
	else if (box.flagminus == 0 && box.flagzero == 0)
		noflags(str, len, box, mns);
	free(str);
	return (1);
}
