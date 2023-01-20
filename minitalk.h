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
 * Constants
*/
# define WAIT_TIME 1

/**
 * Server
*/
void	ft_start_server(void);
void	ft_signal_handler(int signal);

/**
 * Utils
*/
void		ft_error(void);
int			ft_recursive_power(int nb, int power);

#endif