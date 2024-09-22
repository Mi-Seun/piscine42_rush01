/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:51:21 by ludebion          #+#    #+#             */
/*   Updated: 2024/09/22 20:09:10 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	fill_arr(int arr_params[4][4], int arr[4][4], int col, int row)
{
	int	sky;

	row = (col == 4 - 1) ? row + 1 : row;
	col = (col + 1) % 4;
	sky = 1;
	while (sky <= 4)
	{
//		if (check_rows(arr[col][row]) && check_cols(arr[col][row]))
//		{
			arr[col][row] = sky;
			sky++;
			if (fill_arr(arr_params, arr, col, row) == 0)
				return (0);
//		}
	}
	arr[col][row] = 0;
	return (1);
}

void	ft_putchar(int n)
{
	n += '0';
	write(1, &n, 1);
}

void	print_arr(int arr[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(arr[i][j]);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	arr_params[4][4] = {{4, 3, 2, 1}, {1, 2, 2, 2}, {4, 3, 2, 1}, {1, 2, 2, 2}};
	int	arr[4][4];

	if (fill_arr(arr_params, arr, 0, 0) == 0)
	{
		print_arr(arr);
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
