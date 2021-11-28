/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:26:55 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/28 18:29:30 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_sender_wait(pid_t pid)
{
	size_t	i;

	i = 0;
	while (!g_status.recieved && i < 20000)
	{
		usleep(10);
		if (g_status.busy)
			return (2);
		else if (kill(pid, 0))
			return (-1);
		++i;
	}
	if (g_status.recieved)
		return (0);
	return (1);
}

static int	ft_sender_char(pid_t pid, char c)
{
	int	bit;
	int	error;

	error = 0;
	bit = 0;
	while (bit < 8)
	{
		g_status.recieved = false;
		if ((c >> bit) & 1)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		if (error)
			break ;
		error = ft_sender_wait(pid);
		if (error)
			break ;
		++bit;
	}
	return (error);
}

int	ft_sender(pid_t pid, char *str)
{
	size_t	i;
	int		error;

	g_status.busy = false;
	i = 0;
	while (1)
	{
		error = ft_sender_char(pid, str[i]);
		if (error || str[i] == '\0')
			break ;
		write(1, &str[i++], 1);
	}
	if (i)
		write(1, "\n", 1);
	if (error == -1)
		return (ft_print_error(-1, "Lost connection\n"));
	else if (error == 1)
		return (ft_print_error(-1, "Connection timeout\n"));
	else if (error == 2)
		return (ft_print_error(-1, "Server is busy\n"));
	ft_putstr_cd_fd("Message is delivered\n", SH_FG_GREEN, 1);
	return (0);
}
