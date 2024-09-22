/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maudel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:55:39 by maudel            #+#    #+#             */
/*   Updated: 2024/09/22 18:15:01 by maudel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_row(int *row)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 4)
	{
		while (j < 4)
		{
			if (row[i] == row[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_double_row(int *row[])
{
	int	i;
	int	j;

	while (i < 4)
	{
		while (j < 4)
		{
			if (row[0][i] == row[0][j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_col(int *row[])
{
	int	i;
	int	j;

	while (i < 4)
	{
		while (j < 4)
		{
			if (row[i][0] == row[j][0])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
