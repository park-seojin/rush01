/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:43:10 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/12 22:03:25 by hlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_board[5][5];
extern int g_row[5][5];
extern int g_col[5][5];
extern int g_condition[16];

int		fill_board(int r, int c);
void	ft_putchar(char c);
int		is_possible();

void	print_board(void)
{
	int	r;
	int	c;

	r = 0;
	while (++r < 5)
	{
		c = 0;
		while (++c < 4)
		{
			ft_putchar('0' + g_board[r][c]);
			ft_putchar(' ');
		}
		ft_putchar('0' + g_board[r][c]);
		ft_putchar('\n');
	}
}

int		sub_fill_board(int r, int c)
{
	int val;

	val = 0;
	while (++val < 5)
	{
		if (g_row[r][val] || g_col[c][val])
			continue;
		g_row[r][val] = 1;
		g_col[c][val] = 1;
		g_board[r][c] = val;
		if (fill_board(r, c + 1))
			return (1);
		g_row[r][val] = 0;
		g_col[c][val] = 0;
	}
	return (0);
}

int		fill_board(int r, int c)
{
	if (r == 5)
	{
		if (is_possible())
		{
			print_board();
			return (1);
		}
		return (0);
	}
	if (c == 5)
		return (fill_board(r + 1, 1));
	else
		return (sub_fill_board(r, c));
}

void	init(void)
{
	int i;
	int j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			g_row[i][j] = 0;
			g_col[i][j] = 0;
		}
	}
}

int		rush(void)
{
	init();
	return (fill_board(1, 1));
}
