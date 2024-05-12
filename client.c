/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:04:48 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/12 17:26:57 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>



int	main(int argc, char **argv)
{
	pid_t	pid;
	int		result;
	int		bit;
	int		i;
	char	*str;

	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
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
				ft_printf("send failed");
			bit++;
			usleep(300);
		}
		i++;
	}
	return (0);
}
