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
 * TODO Understand while
*/
int	main(void)
{
	ft_start_server();
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		usleep(WAIT_TIME);
	}
}

/**
 * Listen signals SIGUSR1 & SIGUSR2.
 *
 * SIGUSR1 (30): Defines bit 0
 * SIGUSR2 (31): Defines bit 1
// */
void	ft_start_server(void)
{
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
}

/**
 * TODO Understand
 * Handle a signal.
 *
 * @param int signal
 */
void	ft_signal_handler(int signal)
{
	printf("%d\n", signal);
//	static int	char_value = 0;
//	static int	current_bit = 0;
//	static int	len_received = 0;
//	static int	i = 0;
//	static char	*final_str = 0;
//
//	if (!len_received)
//		ft_receive_strlen(&current_bit, &final_str, &len_received, signal);
//	else
//	{
//		if (signal == SIGUSR2)
//			char_value += ft_recursive_power(2, current_bit);
//		if (current_bit == 7)
//		{
//			final_str[i++] = char_value;
//			current_bit = 0;
//			if (char_value == 0)
//				return (ft_restart_variables(&len_received, &final_str, &i));
//			char_value = 0;
//			return ;
//		}
//		current_bit++;
//	}
}

/**
 * static int ft_receive_strlen(int curr_bit)
 * This is the function used in the first step to extract the length of the
 * final string and initiate the string which will be displayed at the end.
*/
//static void	ft_receive_strlen(int *curr_bit, char **str, int *received, int s)
//{
//	static int	len_val = 0;
//
//	if (s == SIGUSR2)
//		len_val += ft_recursive_power(2, *curr _bit);
//	if (*curr_bit == 31)
//	{
//		*received = 1;
//		*str = ft_calloc(len_val + 1, sizeof(char));
//		*curr_bit = 0;
//		len_val = 0;
//		return ;
//	}
//	(*curr_bit)++;
//}

/**
 * static void	ft_restart_variables(int *len_received, char **str, int *i)
 * This function is called at the end of the execution of the program
 * after displaying the string in order to reset all of the variables values
*/
//static void	ft_restart_variables(int *len_received, char **str, int *i)
//{
//	*len_received = 0;
//	if (str)
//	{
//		ft_printf("%s\n", *str);
//		free(*str);
//		*str = 0;
//	}
//	*i = 0;
//}