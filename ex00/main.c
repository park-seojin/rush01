/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:08:39 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/12 21:18:15 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_H
# define UNISTD_H
# include <unistd.h>
#endif

int	check_condition(char *cond);
int	rush(void);

int	main(int argc, char *argv[])
{
	if (argc != 2 || !(check_condition(argv[1]) && rush()))
		write(1, "Error\n", 6);
	return (0);
}
