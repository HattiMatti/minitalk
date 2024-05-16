/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:04:48 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/16 15:23:18 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	send_bits(pid_t pid, char *str)
{
	int	bit;
	int	i;
	int	result;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if (((str[i] >> bit) & 1) == 1)
				result = kill(pid, SIGUSR1);
			else
				result = kill(pid, SIGUSR2);
			if (result == -1)
			{
				ft_printf("send failed");
				return ;
			}
			bit++;
			usleep(600);
		}
		i++;
	}
}

void	send_null(pid_t pid)
{
	int	check;
	int	i;

	i = 0;
	while (i < 8)
	{
		check = kill(pid, SIGUSR2);
		if (check == -1)
		{
			return ;
		}
		i++;
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_printf("string empty");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_bits(pid, str);
	send_null(pid);
	return (0);
}
