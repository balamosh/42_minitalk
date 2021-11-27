/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:41:14 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 13:28:40 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#define _XOPEN_SOURCE 700

# include <signal.h>
# include "libft.h"

typedef struct s_reciever
{
	unsigned char	bit;
	char			c;
	int				pid;
}				t_reciever;

void	ft_reciever(int signal, siginfo_t *info, void *data);

#endif
