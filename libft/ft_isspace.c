/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:11:55 by jpasty            #+#    #+#             */
/*   Updated: 2021/03/08 17:57:00 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	return (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ');
}
