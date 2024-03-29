/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:34:43 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/11 20:34:45 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_len(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s && *s != c)
	{
		res++;
		s++;
	}
	return (res);
}
