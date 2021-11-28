/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_cd_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:35:02 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/28 13:22:25 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_cd_fd(const char *s, const char *cd, int fd)
{
	ft_putstr_fd(cd, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(SH_FG_RESET, fd);
}
