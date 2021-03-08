/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:54:50 by jpasty            #+#    #+#             */
/*   Updated: 2021/03/08 17:57:01 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strcspn(const char *str, const char *sym)
{
	const char	*s;
	const char	*c;

	s = str;
	while (*str)
	{
		c = sym;
		while (*c)
		{
			if (*str == *c)
				break ;
			c++;
		}
		if (*c)
			break ;
		str++;
	}
	return (str - s);
}
