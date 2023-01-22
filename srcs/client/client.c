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
				ft_print_error("Can't reach the server...");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_print_error("Can't reach the server...");
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
 * Handle only SIGUSR2 signal.
 * A SIGUSR2 signal is sent from the server at the end.
 *
 * @param int signal
 * @param siginfo_t *info
 * @param void *context
 *
 * @return void
*/
static void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signal == SIGUSR2)
	{
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
 * 2. Start server to receive signal from server
 * 3. Convert PID to int.
 * 4. Send message to the desired process
 * 5. Wait a reply from server (max 5 seconds)
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
		if (!sleep(5))
			ft_print_error("Server signal timeout ❌ !");
	}
	else
		ft_print_error("Usage : ./client [pid] [message]");
	return (EXIT_FAILURE);
}
