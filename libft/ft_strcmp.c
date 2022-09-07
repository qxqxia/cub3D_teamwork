/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:38:20 by rliu              #+#    #+#             */
/*   Updated: 2022/05/13 18:15:18 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int		index;
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
