/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:06:29 by synicole          #+#    #+#             */
/*   Updated: 2023/01/20 10:06:30 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * int	ft_recursive_power(int nb, int power)
 * This function returns the result of nb ^ power
 * Example: ft_recursive_power(2, 3) = 2 ^ 3 = 8
*/
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
