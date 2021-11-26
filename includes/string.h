/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:33:00 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/26 22:47:18 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "libft.h"

typedef struct s_string
{
	char	*ptr;
	size_t	size;
	size_t	capacity;
}				t_string;

#endif
