/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:26:43 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:26:45 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_ext(const char *str)
{
	char	*ext;

	ext = ".ber";
	if (ft_strncmp(str + ft_strlen(str) - 4, ext, 4) != 0)
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("Error: no arguments\n"), 0);
	if (ac > 2)
		return (ft_printf("Error: too many argument\n"), 0);
	if (!check_ext(av[1]))
		return (ft_printf("Error: invalid file\n"), 0);
	return (1);
}
