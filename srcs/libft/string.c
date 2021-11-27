/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:29:01 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 10:53:32 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_string_push_back(t_string *str, char c)
{
	char	*tmp;

	if (!str->capacity)
	{
		if (ft_malloc((void *)&str->ptr, sizeof(char)))
			str->capacity = 1;
	}
	else if (str->capacity == str->size \
				&& ft_malloc((void *)&tmp, 2 * str->capacity * sizeof(char)))
	{
		ft_memcpy(tmp, str->ptr, str->size);
		free(str->ptr);
		str->ptr = tmp;
		str->capacity *= 2;
	}
	if (str->capacity > str->size)
	{
		str->ptr[str->size++] = c;
		return (true);
	}
	return (false);
}

void	ft_string_free(t_string *str)
{
	free(str->ptr);
	str->capacity = 0;
	str->size = 0;
}
