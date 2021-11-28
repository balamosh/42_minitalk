/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:06:54 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/28 13:25:55 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "shell_colors.h"

typedef enum s_bool
{
	false,
	true
}			t_bool;

typedef struct s_string
{
	char	*ptr;
	size_t	size;
	size_t	capacity;
}				t_string;

t_bool	ft_malloc(void **ptr, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_atoi(const char *str);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putstr_cd_fd(const char *s, const char *cd, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_print_error(int code, const char *str);
void	ft_print_name_pid(const char *name, int pid);
void	ft_print_name_pid_head(const char *name, int pid);

t_bool	ft_string_push_back(t_string *str, char c);
void	ft_string_free(t_string *str);

#endif
