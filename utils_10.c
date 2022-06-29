/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <yboughan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:21:40 by youssef           #+#    #+#             */
/*   Updated: 2022/06/29 19:37:41 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	quit_cause_dead(t_so_long *vars)
{
	free_map(vars->map_to_display);
	free_map(vars->map);
	ft_putstr_fd("Sorry you lose try again ! \n", 0);
	exit(-1);
}

int	move_player(int key, t_so_long *vars)
{
	if (vars->dead == 1)
		quit_cause_dead(vars);
	if (key == 0)
		move_left(vars);
	else if (key == 13)
		move_down(vars);
	else if (key == 2)
		move_rigth(vars);
	else if (key == 1)
		move_up(vars);
	else if (key == 53)
		exit(0);
	if (key == 1 || key == 2 || key == 13 || key == 0)
	{
		update_player_pos(vars);
		get_map_to_display(vars);
		display_map(vars);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == 0)
		return ((char *)s);
	return (NULL);
}

void	update_player_pos(t_so_long *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map[y] && !ft_strchr(vars->map[y], 'P'))
		y++;
	while (vars->map[y][x] && vars->map[y][x] != 'P')
		x++;
	vars->x_pos = x;
	vars->y_pos = y;
}

int	ft_count_coin(char **map)
{
	int	i;
	int	ii;
	int	nb;

	i = 0;
	nb = 0;
	while (map[i])
	{
		ii = 0;
		while (map[i][ii])
		{
			if (map[i][ii] == 'C')
				nb++;
			ii++;
		}
		i++;
	}
	return (nb);
}
