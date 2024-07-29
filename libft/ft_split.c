/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:32:20 by loic              #+#    #+#             */
/*   Updated: 2023/11/27 18:03:33 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	word_length(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] != c))
	{
		i++;
	}
	return (i);
}

static char	*_strdup(char const *src, char c)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = word_length(src, c);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (dest == NULL)
	{
		return (0);
	}
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_free(char **s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		free(*s++);
		count++;
	}
	free(s - count);
	return (NULL);
}

static int	words_counter(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
		{
			i++;
		}
		if (str[i] != '\0')
		{
			count++;
		}
		while (str[i] != '\0' && (str[i] != c))
		{
			i++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	int		i;
	int		u;

	i = 0;
	u = 0;
	array = (char **)malloc(sizeof(char *) * (words_counter(str, c) + 1));
	if (!array)
		return (NULL);
	while (str[i] != '\0' && u < words_counter(str, c))
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
		{
			array[u] = _strdup(str + i, c);
			if (!array[u++])
				return (ft_free(array));
		}
		while (str[i] != '\0' && (str[i] != c))
			i++;
	}
	array[u] = 0;
	return (array);
}

// int    main(void)
// {
//     char const   *str = "^^^1^^2a,^^^^3^^^^--h^^^^";
//     char    c = '^';
//     char    **p;
//     int i = 0;
//     p = ft_split(str, c);

//     if (p[0] == NULL)
//         printf(" ");

//     while (i < words_counter(str, c))
//     {
//         printf("%s\n", p[i]);
//         free(p[i]);
//         i++;
//     }
//     free(p);
//     return (0);
// }