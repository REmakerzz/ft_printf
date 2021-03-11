/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:26:19 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:06:09 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_flags(const char *str, t_print *box, va_list ap)
{
	while (str[box->i] == '-' || str[box->i] == '0' || str[box->i] == '*')
	{
		if (str[box->i] == '-')
		{
			box->flagminus = 1;
			box->i++;
		}
		else if (str[box->i] == '0')
		{
			box->flagzero = 1;
			box->i++;
		}
		else if (str[box->i] == '*')
		{
			box->width = va_arg(ap, int);
			if (box->width < 0)
			{
				box->flagminus = 1;
				box->width = box->width * (-1);
			}
			box->i++;
		}
	}
	return (box->i);
}
