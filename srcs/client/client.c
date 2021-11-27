/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:24:40 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 13:24:24 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					pid;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_reciever;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) || sigaction(SIGUSR2, &act, NULL))
		return (ft_print_error(1, "Sigaction error.\n"));
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (kill(pid, 0))
			return (ft_print_error(2, "Invalid PID.\n"));
		if (ft_sender(pid, av[2]))
			return (ft_print_error(3, "Error in transfer.\n"));
	}
	else
		return (ft_print_error(4, "Invalid_arguments.\n"));
	return (0);
}
