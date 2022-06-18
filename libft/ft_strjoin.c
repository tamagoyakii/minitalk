/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:58:59 by jihyukim          #+#    #+#             */
/*   Updated: 2022/01/28 19:03:04 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	total_len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * total_len + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	*(ret + i) = 0;
	ft_strlcat(ret, s2, total_len + 1);
	return (ret);
}
