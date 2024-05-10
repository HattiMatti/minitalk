/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:04:48 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/10 17:05:34 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		result;

	if (argc != 2)
		return (0);
	pid = ft_atoi(argv[1]);
	result = kill(pid, SIGUSR1);
	if (result == 0)
		ft_printf("signal sent");
	else
		write(2,"Error\n", 6);
	return (0);
}
