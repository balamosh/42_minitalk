/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:26:55 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 12:27:39 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_sender_char(pid_t pid, char c)
{
	int	bit;
	int	error;

	error = 0;
	bit = 0;
	while (bit < 8)
	{
		g_flag = 0;
		if ((c >> bit) & 1)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		if (error)
			return (error);
		bit++;
		while (!g_flag)
			continue ;
	}
	return (error);
}

int	ft_sender(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_sender_char(pid, str[i]))
			return (-1);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
