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
 * Convert char to binary and send them through signals.
 *
 * 1. Check bit is 0 or 1.
 * 		SIGUSR1 (30): Defines bit 0.
 * 		SIGUSR2 (31): Defines bit 1.
 * 2. For each case, send a signal with the kill() function.
 * 3. Check if the kill() function was successful.
 * 4. Suspend the execution with the pause() function
 * 	  until a return signal is received.
 *
 * -----------------------------------------------------------------------------
 *
 * Help:
 * An octet or a byte consists of eight bits of information.
 * MSB = most significant bit.
 * Operator "<<": Shift all the bits of a number to the left
 * 				  by a certain number of positions.
 * Operator "&": Returns a result which is 1 if both bits are 1.
 *
 * -----------------------------------------------------------------------------
 *
 * Example:
 * Character "a" in ASCII = 97 and in binary = 0110 0001.
 *
 * Iteration 1:
 * 1. (1 << 7) Takes the value 1 (0001) and shifts 7 positions to the left to
 * 	  obtain (10000000), which is equal to 128 in decimal.
 * 2. (97 & 128)
 * 	  0110 0001
 *    1000 0000
 *    ---------
 *    0000 0000 = 0 -> Return 0 Because 64 == 0.
 *
 * Iteration 2:
 * 1. (1 << 6) Takes the value 1 (0001) and shifts 6 positions to the left to
 * 	  obtain (01000000), which is equal to 64 in decimal.
 * 2. (97 & 64)
 *    0110 0001
 *    0100 0000
 *    ---------
 *    0100 0000 = 64 -> Return 1 Because 64 != 0.
 *
 * -----------------------------------------------------------------------------
 *
 * @param char c
 * @param int pid
 *
 * @return void
*/
static void	char_to_binary(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_print_error("Can't reach the process...");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_print_error("Can't reach the process...");
		}
		i--;
		pause();
	}
}

/**
 * Send message.
 * Transform each char from string to binary.
 *
 * @param char *str
 * @param int pid
 *
 * @return void
*/
static void	ft_send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_binary(str[i], pid);
		i++;
	}
	char_to_binary('\0', pid);
}

/**
 * TODO Why only SIGUSR1?
 * Handle a signal.
 *
 * @param int signal
 * @param siginfo_t *info
 * @param void *context
 *
 * @return void
*/
static void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	int			client_pid;

	(void) context;
	if (signal == SIGUSR1)
	{
		client_pid = info->si_pid;
		ft_printf("Response from [%d]\n", client_pid);
		ft_print_success("Server signal successfully received ✅ !");
	}
}

/**
 * Listen signals SIGUSR1 & SIGUSR2.
 *
 * @param void
 *
 * @return void
*/
static void	ft_start_server(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

/**
 * 1. Check if there is 3 arguments.
 * 2. Convert PID to int.
 * 3. Start server to receive signal from server
 * 4. Send message to the desired process
 * 5. Wait a reply from server (max 10 seconds)
 *
 * @param int argc
 * @param char **argv
 *
 * @return int
*/
int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc == 3)
	{
		ft_start_server();
		server_pid = ft_atoi(argv[1]);
		ft_send_message(argv[2], server_pid);
		if (!sleep(10))
			ft_print_error("Server signal was not received ❌ !");
	}
	else
		ft_print_error("Usage : ./client [pid] [message]");
	return (EXIT_FAILURE);
}
