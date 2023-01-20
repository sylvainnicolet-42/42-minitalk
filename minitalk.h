/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:41:00 by synicole          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:02 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/**
 * Libraries
*/
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

/**
 * Print
*/
void	ft_print_success(char *str);
void	ft_print_error(char *str);

#endif