/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:16:08 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/07 16:52:28 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < n && sum == 0 && (s1[i] || s2[i]))
	{
		sum = (unsigned char) s1[i] - (unsigned char) s2[i];
		i++;
	}
	return (sum);
}
