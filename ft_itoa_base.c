/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:25:33 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:05:54 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		checknumber(unsigned long nbr, int *len, int base)
{
	unsigned long	temp_num;

	*len = 0;
	temp_num = nbr;
	if (nbr == 0)
		*len += 1;
	while (temp_num > 0)
	{
		temp_num /= base;
		*len += 1;
	}
}

char			*ft_itoa_base(unsigned long nbr, int base, t_print box)
{
	int				len;
	char			*str;

	checknumber(nbr, &len, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
		{
			if (box.type == 'x' || box.type == 'p')
				str[len - 1] += 'a' - 10;
			else if (box.type == 'X')
				str[len - 1] += 'A' - 10;
		}
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}
