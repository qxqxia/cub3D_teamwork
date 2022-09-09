/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:38:20 by rliu              #+#    #+#             */
/*   Updated: 2022/09/09 13:05:34 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*s1_holder;
	unsigned char	*s2_holder;

	index = 0;
	s1_holder = (unsigned char *)s1;
	s2_holder = (unsigned char *)s2;
	while (s1_holder[index] && s2_holder[index] && \
			s1_holder[index] == s2_holder[index])
		index++;
	return (s1_holder[index] - s2_holder[index]);
}
