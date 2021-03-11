/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeprint_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:02:07 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:08:48 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_typeprint_c(char ch, t_print box)
{
	if (box.width != 0)
	{
		if (box.flagminus == 1)
		{
			box.width -= 1;
			ft_putchar(ch, 1);
			while (box.width--)
				ft_putchar(' ', 1);
		}
		else
		{
			box.width -= 1;
			while (box.width--)
				ft_putchar(' ', 1);
			ft_putchar(ch, 1);
		}
	}
	else
		ft_putchar(ch, 1);
}
