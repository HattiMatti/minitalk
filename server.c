/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:04:59 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/10 17:04:53 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

unsigned char g_bit;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_bit = (g_bit << 1) | 1;
		ft_printf("received 1\n");
	}
	if (signum == SIGUSR2)
	{
		g_bit = (g_bit << 1);
		ft_printf("received 0\n");
	}
}

unsigned char	reverse_bits(void)
{
	int				i;
	unsigned char	res;

	res = 0;
	i = 8;
	while (i > 0)
	{
		res = res * 2 + (g_bit % 2);
		g_bit = g_bit / 2;
		i--;
	}
	return (res);
}

int	main(void)
{
	pid_t			pid;
	int				bit_count;
	unsigned char	character;

	pid = getpid();
	ft_printf("%d\n", pid);
	bit_count = 0;

	while (bit_count < 8)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
		bit_count++;
	}
	character = reverse_bits();
	ft_printf("Signal received: %c\n", character);
	return (0);
}
