/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylyk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:40:17 by dylyk             #+#    #+#             */
/*   Updated: 2020/12/27 20:07:24 by dylyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_typeparser_nbr(const char *str, t_print box, va_list ap)
{
	if (box.type == 'd' || str[box.i] == 'i')
	{
		if (!(ft_typeprint_d_i(va_arg(ap, int), box)))
			return (-1);
	}
	else if (box.type == 'x' || str[box.i] == 'X')
	{
		if (!(ft_typeprint_xx(va_arg(ap, unsigned int), box)))
			return (-1);
	}
	else if (box.type == 'u')
	{
		if (!(ft_typeprint_u(va_arg(ap, unsigned int), box)))
			return (-1);
	}
	else if (box.type == 'p')
	{
		if (!(ft_typeprint_p(va_arg(ap, unsigned long), box)))
			return (-1);
	}
	else
		return (box.i);
	return (++box.i);
}

static int	ft_typeparser(const char *str, t_print box, va_list ap)
{
	if (box.type == 'c')
		ft_typeprint_c(va_arg(ap, int), box);
	else if (box.type == 's')
		ft_typeprint_s(va_arg(ap, char *), box);
	else if (box.type == '%')
		ft_typeprint_c('%', box);
	else if (box.type == 'd' || box.type == 'i' || box.type == 'u' ||
	box.type == 'x' || box.type == 'X' || box.type == 'p')
	{
		if (!ft_typeparser_nbr(str, box, ap))
			return (-1);
	}
	else
		return (box.i);
	return (++box.i);
}

int			ft_parser(const char *str, va_list ap)
{
	t_print		box;

	box.i = 0;
	while (str[box.i] != '\0')
	{
		box.prec = -1;
		box.width = 0;
		box.flagminus = 0;
		box.flagzero = 0;
		box.type = '\0';
		box.null = "(null)";
		while (str[box.i] != '%' && str[box.i] != '\0')
			ft_putchar(str[box.i++], 1);
		if (str[box.i] == '%')
			box.i++;
		box.i = ft_parse_flags(str, &box, ap);
		while (str[box.i] >= '0' && str[box.i] <= '9')
			box.width = box.width * 10 + (str[box.i++] - '0');
		box.i = ft_parse_pricision(str, &box, ap);
		box.type = str[box.i];
		if (!(box.i = ft_typeparser(str, box, ap)))
			return (-1);
	}
	return (ft_putchar(' ', 0));
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	int			result;
	int			reset;

	reset = ft_putchar(' ', 0);
	va_start(ap, str);
	if ((result = ft_parser(str, ap)) == -1)
		return (-1);
	va_end(ap);
	return (result - reset);
}
