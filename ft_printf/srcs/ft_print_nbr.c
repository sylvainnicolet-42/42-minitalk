/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:32:36 by synicole          #+#    #+#             */
/*   Updated: 2022/10/22 21:32:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(n);
	if (!nbr)
		return (0);
	len = ft_print_str(nbr);
	free(nbr);
	return (len);
}
