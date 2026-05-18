/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:16 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:16 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char needle)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (flag && *str == needle)
			flag = 0;
		else if (!flag && *str != needle)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*get_substr(const char *str, char c)
{
	char	*substr;
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str, len + 1);
	return (substr);
}

char	**free_all(char **bad_array, int index)
{
	while (index >= 0)
		free(bad_array[index--]);
	free(bad_array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**explode;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	explode = ft_calloc(word_count + 1, sizeof(char *));
	if (!explode)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		explode[i] = get_substr(s, c);
		if (!explode[i])
			return (free_all(explode, i - 1));
		s += ft_strlen(explode[i++]);
	}
	explode[i] = NULL;
	return (explode);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	sample[] = "   m     mm m n f    f z";
// 	int		i;
// 	char	**result;

// 	i = 0;
// 	result = ft_split(sample, ' ');
// 	while (i < count_words(sample, ' '))
// 		printf("%s\n", result[i++]);
// 	free(result);
// 	return (0);
// }
