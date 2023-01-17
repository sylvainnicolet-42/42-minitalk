/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:02 by synicole          #+#    #+#             */
/*   Updated: 2022/10/25 16:04:04 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_getlength(unsigned int n)
{
	int	length;

	length = 1;
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*ft_putnbr(unsigned int n, char *ptr, int i)
{
	if (n >= 10)
		ft_putnbr(n / 10, ptr, i - 1);
	ptr[i] = n % 10 + '0';
	return (ptr);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		length;

	length = ft_getlength(n);
	ptr = ft_calloc(sizeof(char), length + 1);
	if (!ptr)
		return (0);
	return (ft_putnbr(n, ptr, length - 1));
}

int	ft_print_unbr(unsigned int n)
{
	char	*nbr;
	int		len;

	nbr = ft_uitoa(n);
	if (!nbr)
		return (0);
	len = ft_print_str(nbr);
	free(nbr);
	return (len);
}
