/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 07:16:19 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *str, char delim)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i] == delim)
		i++;
	while (str[i])
	{
		if (str[i] == delim && str[i + 1] != delim && str[i + 1] != '\0')
			words++;
		i++;
	}
	if (str[0] != '\0')
		words++;
	return (words);
}

static	char	*ft_get_word(const char *str, char delim, int *index_ptr)
{
	char	*word_arr;
	int		i;
	int		j;

	j = *index_ptr;
	while (j != delim && str[j])
		j++;
	word_arr = (char *)malloc(sizeof(word_arr) * (j - *index_ptr));
	if (!word_arr)
		return (NULL);
	i = 0;
	while (str[*index_ptr] != delim && str[*index_ptr])
	{
		word_arr[i] = str[*index_ptr];
		i++;
		*index_ptr += 1;
	}
	word_arr[i] = '\0';
	while (str[*index_ptr] == delim && str[*index_ptr])
		*index_ptr += 1;
	return (word_arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		y;
	int		word_count;
	char	**db;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	word_count = ft_count_words(s, c);
	db = (char**)malloc((word_count + 1) * sizeof(char*));
	if (!db)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (y < word_count && s[i])
	{
		db[y] = ft_get_word(s, c, &i);
		y++;
	}
	db[y] = 0;
	return (db);
}
