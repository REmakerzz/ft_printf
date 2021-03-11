/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeprint_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:29:02 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:09:28 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_typeprint_s(const char *str, t_print box)
{
	int		len;

	if (str == NULL)
		str = box.null;
	len = ft_strlen(str);
	if (box.prec != -1 && box.prec < len)
		len = box.prec;
	if (box.width > len)
	{
		box.width = box.width - len;
		if (box.flagminus == 1)
		{
			ft_putstr(str, len);
			ft_putspace(box);
		}
		else
		{
			ft_putspace(box);
			ft_putstr(str, len);
		}
	}
	else
		ft_putstr(str, len);
}
