/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:27:00 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/13 23:14:17 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrword(char const *s, char c)
{
	int			nbr;
	size_t		i;

	i = 0;
	nbr = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i + 1] != c && s[i] == c)
			nbr++;
		i++;
	}
	if (s[i - 1] != c)
		nbr++;
	return (nbr);
}

static char	*ft_strdup_mod(const char *s, char c, size_t *i)
{
	int		lensrc;
	char	*dest;
	size_t	j;

	lensrc = 0;
	j = *i;
	while (s[j] != c && s[j] != '\0')
	{
		lensrc++;
		j++;
	}
	j = 0;
	dest = ft_calloc(lensrc + 2, sizeof(char));
	if (!dest)
		return (NULL);
	while (s[*i] != '\0' && s[*i] != c)
	{
		dest[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	dest[j] = c;
	dest[j + 1] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	res = ft_calloc((ft_nbrword(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			res[j] = ft_strdup_mod(s, c, &i);
			j++;
		}	
	}
	res[j] = 0;
	return (res);
}
