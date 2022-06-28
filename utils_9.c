/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <yboughan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:20:31 by youssef           #+#    #+#             */
/*   Updated: 2022/06/28 20:05:52 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_monster(t_so_long *vars, char c)
{
	if (c == 'M')
		vars->dead = 1;
}

void	move_left(t_so_long *vars)
{
	check_monster(vars, vars->map[vars->y_pos][vars->x_pos - 1]);
	if (vars->map[vars->y_pos][vars->x_pos - 1] == '0')
	{
		vars->map[vars->y_pos][vars->x_pos - 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->counter++;
	}
	else if (vars->map[vars->y_pos][vars->x_pos - 1] == 'C')
	{
		vars->map[vars->y_pos][vars->x_pos - 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
		vars->counter++;
	}
	else if (vars->map[vars->y_pos][vars->x_pos - 1] == 'E')
	{
		if (vars->nb_coin == 0)
		{
			printf("You win !");
			exit (0);
		}
	}
	vars->direction = 0;
}

void	move_rigth(t_so_long *vars)
{
	check_monster(vars, vars->map[vars->y_pos][vars->x_pos + 1]);
	if (vars->map[vars->y_pos][vars->x_pos + 1] == '0')
	{
		vars->map[vars->y_pos][vars->x_pos + 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->counter++;
	}
	else if (vars->map[vars->y_pos][vars->x_pos + 1] == 'C')
	{
		vars->map[vars->y_pos][vars->x_pos + 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
		vars->counter++;
	}
	else if (vars->map[vars->y_pos][vars->x_pos + 1] == 'E')
	{
		if (vars->nb_coin == 0)
		{
			printf("You win !");
			exit (0);
		}
	}
	vars->direction = 1;
}

void	move_down(t_so_long *vars)
{
	check_monster(vars, vars->map[vars->y_pos - 1][vars->x_pos]);
	if (vars->map[vars->y_pos - 1][vars->x_pos] == '0')
	{
		vars->map[vars->y_pos - 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->counter++;
	}
	else if (vars->map[vars->y_pos - 1][vars->x_pos] == 'C')
	{
		vars->map[vars->y_pos - 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
		vars->counter++;
	}
	else if (vars->map[vars->y_pos - 1][vars->x_pos] == 'E')
	{
		if (vars->nb_coin == 0)
		{
			printf("You win !");
			exit (0);
		}
	}
}

void	move_up(t_so_long *vars)
{
	check_monster(vars, vars->map[vars->y_pos + 1][vars->x_pos]);
	if (vars->map[vars->y_pos + 1][vars->x_pos] == '0')
	{
		vars->map[vars->y_pos + 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->counter++;
	}
	else if (vars->map[vars->y_pos + 1][vars->x_pos] == 'C')
	{
		vars->map[vars->y_pos + 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
		vars->counter++;
	}
	else if (vars->map[vars->y_pos][vars->x_pos - 1] == 'E')
	{
		if (vars->nb_coin == 0)
		{
			printf("You win !");
			exit (0);
		}
	}
}
