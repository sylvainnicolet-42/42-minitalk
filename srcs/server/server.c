/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:45:59 by synicole          #+#    #+#             */
/*   Updated: 2023/01/17 15:46:02 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void) argc;
	(void ) argv;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	return (0);
}
