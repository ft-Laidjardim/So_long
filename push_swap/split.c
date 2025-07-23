/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:00:30 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/23 12:15:53 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			count++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*make_word(char *str, int *start)
{
	int		i;
	int		j;
	char	*word;

	i = *start;
	j = 0;
	while (str[i + j] && (str[i + j] != ' ' && str[i + j] != '\t'))
		j++;
	word = malloc(sizeof(char) * (j + 1));
	if (!word)
		return (NULL);
	*start += j;
	j = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	{
		word[j] = str[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

static char	**free_split_function(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**split;

	split = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			split[j] = make_word(str, &i);
			if (!split[j])
				return (free_split_function(split));
			j++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
