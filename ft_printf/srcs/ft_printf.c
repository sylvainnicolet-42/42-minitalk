/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:20:32 by synicole          #+#    #+#             */
/*   Updated: 2022/10/20 20:20:33 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count_print;

	va_start(args, s);
	count_print = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count_print += ft_formats(&args, s[i]);
		}
		else
			count_print += ft_print_char(s[i]);
		i++;
	}
	va_end(args);
	return (count_print);
}
