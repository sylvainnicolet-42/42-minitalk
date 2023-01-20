/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                      :      +:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:02:05 by synicole          #+#    #+#             */
/*   Updated: 2023/01/20 16:02:07 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

/**
 * Print text in green.
 */
void	ft_print_success(char *str)
{
	ft_printf("\033[0;32m");
	ft_printf("%s\n", str);
	exit(EXIT_SUCCESS);
}

/**
 * Print text in red.
 */
void	ft_print_error(char *str)
{
	ft_printf("\033[0;31m");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
