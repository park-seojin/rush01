/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:09:14 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/12 21:24:25 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_H
# define UNISTD_H
# include <unistd.h>
#endif

extern int	g_board[5][5];
int			g_row[5][5];
int			g_col[5][5];
int			g_condition[16];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		blank(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		check_condition(char *cond)
{
	int	count;

	count = 0;
	while (*cond)
	{
		while (*cond && blank(*cond))
			++cond;
		if (*cond)
		{
			if ('1' <= *cond && *cond <= '4')
			{
				if (count == 16 || (*(cond + 1) && !blank(*(cond + 1))))
					return (0);
				g_condition[count++] = *cond - '0';
			}
			else
				return (0);
			++cond;
		}
	}
	return (count == 16);
}
