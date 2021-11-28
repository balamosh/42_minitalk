/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:42:09 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/28 13:26:30 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_reciever;
	act.sa_flags = SA_SIGINFO;
	ft_print_name_pid_head("Server", getpid());
	ft_putstr_cd_fd("Listening...\n", SH_FG_GREEN, 1);
	if (sigaction(SIGUSR1, &act, NULL) || sigaction(SIGUSR2, &act, NULL))
		return (ft_print_error(1, "Sigaction error\n"));
	while (1)
		pause();
	return (0);
}
