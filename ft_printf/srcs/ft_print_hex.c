/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:10:10 by synicole          #+#    #+#             */
/*   Updated: 2022/10/24 17:10:12 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_get_hex_length(unsigned int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int n, const char format)
{
	if (!n)
		ft_putchar_fd('0', 1);
	else
	{
		if (n >= 16)
		{
			ft_put_hex(n / 16, format);
			ft_put_hex(n % 16, format);
		}
		else
		{
			if (n < 10)
				ft_putchar_fd((n + '0'), 1);
			else
			{
				if (format == 'x')
					ft_putchar_fd((n - 10 + 'a'), 1);
				if (format == 'X')
					ft_putchar_fd((n - 10 + 'A'), 1);
			}
		}
	}
}

int	ft_print_hex(unsigned int n, const char format)
{
	ft_put_hex(n, format);
	return (ft_get_hex_length(n));
}
