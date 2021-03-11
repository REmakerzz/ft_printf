/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boxinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 13:21:21 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:06:29 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_boxinit(t_print *box, int len)
{
	box->flagzero = (box->flagzero == 0 || (box->prec >= 0 || box->flagminus) ||
					(box->flagminus && box->prec >= 0) ? 0 : 1);
	box->prec = box->prec > len ? box->prec - len : 0;
	box->width = box->prec + len < box->width ? box->width - (box->prec + len) :
				box->width - len - box->prec;
}
