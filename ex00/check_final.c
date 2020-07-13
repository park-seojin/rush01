/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_final.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 21:33:42 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/12 21:39:07 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int g_board[5][5];
int g_condition[16];
int g_idx;

void	ft_putchar(char c);

int		check_up(void)
{
	int cnt;
	int temp;
	int i;
	int j;

	j = 0;
	while (++j < 5)
	{
		i = 0;
		temp = 0;
		cnt = 0;
		while (++i < 5)
		{
			if (temp < g_board[i][j])
			{
				temp = g_board[i][j];
				cnt++;
			}
		}
		if (cnt != g_condition[g_idx++])
			return (0);
	}
	return (1);
}

int		check_down(void)
{
	int cnt;
	int temp;
	int i;
	int j;

	j = 0;
	while (++j < 5)
	{
		i = 5;
		temp = 0;
		cnt = 0;
		while (--i > 0)
		{
			if (temp < g_board[i][j])
			{
				temp = g_board[i][j];
				cnt++;
			}
		}
		if (cnt != g_condition[g_idx++])
			return (0);
	}
	return (1);
}

int		check_left(void)
{
	int cnt;
	int temp;
	int i;
	int j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		temp = 0;
		cnt = 0;
		while (++j < 5)
		{
			if (temp < g_board[i][j])
			{
				temp = g_board[i][j];
				cnt++;
			}
		}
		if (cnt != g_condition[g_idx++])
			return (0);
	}
	return (1);
}

int		check_right(void)
{
	int cnt;
	int temp;
	int i;
	int j;

	i = 5;
	while (++i < 5)
	{
		j = 5;
		temp = 0;
		cnt = 0;
		while (--j > 0)
		{
			if (temp < g_board[i][j])
			{
				temp = g_board[i][j];
				cnt++;
			}
		}
		if (cnt != g_condition[g_idx++])
			return (0);
	}
	return (1);
}

int		is_possible(void)
{
	int i;

	i = 0;
	g_idx = 0;
	if (check_up() && check_down() && check_left() && check_right())
		return (1);
	return (0);
}
