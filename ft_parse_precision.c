/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:45:26 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:07:06 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_pricision(const char *str, t_print *box, va_list ap)
{
	if (str[box->i] == '.')
	{
		box->i++;
		box->prec = 0;
		if (str[box->i] == '*')
		{
			box->prec = va_arg(ap, int);
			if (box->prec < 0)
				box->prec = -1;
			box->i++;
		}
		while (str[box->i] >= '0' && str[box->i] <= '9')
			box->prec = box->prec * 10 + (str[box->i++] - '0');
	}
	return (box->i);
}
