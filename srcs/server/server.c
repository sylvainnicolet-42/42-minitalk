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

/**
 * Display character.
 * If character is "\0", send a signal SIGUSR2 with the kill() function.
 *
 * @param int *client_pid
 * @param int *c
 * @param int *nbr_bit
 *
 * @return void
 */
static void	ft_print_server(const int *client_pid, char *c, int *nbr_bit)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		*c = 0;
		if (kill(*client_pid, SIGUSR2) == -1)
			ft_print_error("Can't reach the client...");
		return ;
	}
	*nbr_bit = 0;
}

/**
 * Convert binary to char and display them.
 *
 * 1. Check if "client PID" exist, if not assign it + reset variables.
 * 2. Use the doubling method
 * 4. If nbr_bit is 7, display the character.
 * 	  Else increment nbr_bit
 * 5. Send a signal SIGUSR1 to receive the next bit.
 *
 * @param int signal
 * @param siginfo_t *info
 * @param void *context
 *
 * @return void
 */
static void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	nbr_bit;
	static char	c;

	(void) context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		nbr_bit = 0;
		c = 0;
	}
	c *= 2;
	if (signal == SIGUSR2)
		c += 1;
	if (nbr_bit == 7)
		ft_print_server(&client_pid, &c, &nbr_bit);
	else
		nbr_bit++;
	if (kill(client_pid, SIGUSR1) == -1)
		ft_print_error("Can't reach the client...");
}

/**
 * Listen signals SIGUSR1 & SIGUSR2.
 *
 * SIGUSR1 (30): Defines bit 0
 * SIGUSR2 (31): Defines bit 1
 *
 * Usage of _Noreturn:
 * https://learn.microsoft.com/fr-fr/cpp/c-language/noreturn?view=msvc-170
 *
 * @param void
 *
 * @return _Noreturn void
*/
_Noreturn static void	ft_start_server(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}

/**
 * 1. Show PID
 * 2. Start the server
*/
int	main(void)
{
	ft_printf("PID: [%d]\n", getpid());
	ft_start_server();
}
