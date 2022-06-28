/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:41:32 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/28 19:57:47 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	get_x_start(t_so_long *vars)
{
	int	len_x;

	len_x = ft_strlen(vars->map[0]);
	if (len_x < 12)
		return (0);
	else if (vars->x_pos + 5 > len_x - 1)
		return (len_x - 11);
	else if (vars->x_pos - 5 < 0)
		return (0);
	else
		return (vars->x_pos - 5);
}

int	get_x_end(t_so_long *vars)
{
	int	len_x;

	len_x = ft_strlen(vars->map[0]);
	if (len_x < 12)
		return (len_x - 1);
	else if (vars->x_pos - 5 < 0)
		return (10);
	else if (vars->x_pos + 5 > len_x - 1)
		return (len_x - 1);
	else
		return (vars->x_pos + 5);
}

int	get_y_start(t_so_long *vars)
{
	int	len_y;

	len_y = get_nb_rows(vars->map);
	if (len_y < 12)
		return (0);
	else if (vars->y_pos + 5 > len_y - 1)
		return (len_y - 11);
	else if (vars->y_pos - 5 < 0)
		return (0);
	else
		return (vars->y_pos - 5);
}

int	get_y_end(t_so_long *vars)
{
	int	len_y;

	len_y = get_nb_rows(vars->map);
	if (len_y < 12)
		return (len_y - 1);
	else if (vars->y_pos - 5 < 0)
		return (10);
	else if (vars->y_pos + 5 > len_y - 1)
		return (len_y - 1);
	else
		return (vars->y_pos + 5);
}

void	get_rowto_display(int y_start, int x_start, int x_end, t_so_long *vars)
{
	int	i;
	int	y_end;

	y_end = get_y_end(vars);
	i = 0;
	while (x_start <= x_end)
	{
		if (y_end >= 11)
			vars->map_to_display[10 - (y_end - y_start)][i]
				= vars->map[y_start][x_start];
		else
			vars->map_to_display[y_start][i] = vars->map[y_start][x_start];
		x_start++;
		i++;
	}
	if (y_end >= 11)
		vars->map_to_display[10 - (y_end - y_start)][i] = '\0';
	else
		vars->map_to_display[y_start][i] = '\0';
}
