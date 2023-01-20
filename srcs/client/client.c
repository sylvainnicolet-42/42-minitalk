/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:45:45 by synicole          #+#    #+#             */
/*   Updated: 2023/01/17 15:45:49 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

/**
 * static int ft_found_errors_in_main(int argc, char **argv)
 * This function is used to check for errors in main arguments.
 * Errors include:
 * 1) Wrong number of args
 * 2) Non numerical process id passed as argument
*/
static int	ft_found_errors_in_main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
	}
	return (0);
}

/**
 * void	ft_send_next_char_bit_by_bit(char c, int pid)
 * This function will take a char c as an argument and send its binary values
 * one bit at a time to the process identified by pid argument (our server).
 * We will use SIGUSR2 (=31) to send "1" and SIGUSR1 (=30) to send "0".
 * The line "if (c & 0x01)" compares the current bit to 1
 * The line "c = c >> 1" moves on to the next bit in c.
*/
void	ft_send_next_char_bit_by_bit(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

/**
 * Function used to send the length of the string bit by bit
*/
void	ft_send_strlen_bit_by_bit(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(WAIT_TIME);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;
	int		len;
	int		i;

	if (ft_found_errors_in_main(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	str_to_send = argv[2];
	len = (int) ft_strlen(str_to_send);
	i = -1;
	ft_send_strlen_bit_by_bit(len, pid);
	while (str_to_send[++i])
		ft_send_next_char_bit_by_bit(str_to_send[i], pid);
	ft_send_next_char_bit_by_bit(str_to_send[i], pid);
}
