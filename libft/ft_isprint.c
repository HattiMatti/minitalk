/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:38:37 by msiitone          #+#    #+#             */
/*   Updated: 2023/10/31 18:41:44 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i < 127)
		return (1);
	return (0);
}