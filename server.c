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

/*void	signal_handler(int signum)
{
	ft_printf("received SIGINT!\n", signum);
	return (0);
}*/

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d", pid);
	pause();
	ft_printf("Signal received\n");
	return (0);
}
