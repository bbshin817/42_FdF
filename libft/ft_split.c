/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 03:09:25 by user              #+#    #+#             */
/*   Updated: 2025/06/05 18:02:00 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str != delimiter && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == delimiter)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*get_next_word(const char **str, char delimiter)
{
	const char	*start;

	start = *str;
	while (**str && **str != delimiter)
		(*str)++;
	return (ft_substr(start, 0, *str - start));
}

static void	allocate_result(char ***result, int word_count)
{
	*result = (char **)ft_calloc(word_count + 1, sizeof(char *));
}

static int	process_words(const char **s, char c, char **result)
{
	int	i;

	i = 0;
	while (**s)
	{
		if (**s != c)
		{
			result[i] = get_next_word(s, c);
			if (!result[i])
				return (i);
			i++;
		}
		else
			(*s)++;
	}
	return (-1);
}

char	**ft_split(const char *s, char c)
{
	int		word_count;
	int		process_word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	if (0 == word_count)
		return (NULL);
	allocate_result(&result, word_count);
	if (!result)
		return (NULL);
	process_word_count = process_words(&s, c, result);
	if (0 < process_word_count)
	{
		while (process_word_count > 0)
			free(result[--process_word_count]);
		free(result);
		return (NULL);
	}
	return (result);
}
