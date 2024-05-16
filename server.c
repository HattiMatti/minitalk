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

unsigned char	g_bit;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_bit = (g_bit << 1) | 1;
	}
	if (signum == SIGUSR2)
	{
		g_bit = (g_bit << 1);
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

char	*str_comp(char *s1, unsigned char character)
{
	char	*res;
	char	str[2];
	int		len;

	if (!character)
		return (0);
	if (!s1)
		s1 = ft_strdup("");
	str[0] = character;
	str[1] = '\0';
	len = ft_strlen(s1);
	res = malloc((len + 2) * sizeof(char));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(res, s1, len + 1);
	ft_strlcat(res, str, len + 2);
	free(s1);
	return (res);
}

void	handler(char *str)
{
	pid_t			pid;
	int				bit_count;
	unsigned char	character;

	pid = getpid();
	ft_printf("server pid: %d\n", pid);
	bit_count = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		while (bit_count++ < 8)
			pause();
		bit_count = 0;
		character = reverse_bits();
		if (character == 0)
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		if (character != 0)
			str = str_comp(str, character);
	}
	return ;
}

int	main(void)
{
	char	*str;

	str = NULL;
	handler(str);
	return (0);
}
