/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <yboughan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:18:40 by youssef           #+#    #+#             */
/*   Updated: 2022/06/29 19:48:59 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	init_map_to_display(t_so_long *vars)
{
	int	i;
	int	nb_rows;
	int	nb_cols;

	nb_rows = get_nb_rows(vars->map);
	nb_cols = ft_strlen(vars->map[0]);
	if (nb_rows > 11)
		nb_rows = 11;
	if (nb_cols > 11)
		nb_cols = 11;
	i = 0;
	vars->map_to_display = malloc((nb_rows + 1) * sizeof(char *));
	while (i < nb_rows)
	{
		vars->map_to_display[i] = malloc((nb_cols + 1) * sizeof(char));
		i++;
	}
}

void	get_map_to_display2(t_so_long *vars, int y_start, int y_end)
{
	if (y_end >= 11)
		vars->map_to_display[11] = NULL;
	else
		vars->map_to_display[y_start] = NULL;
}

void	get_map_to_display(t_so_long *vars)
{
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;

	x_start = get_x_start(vars);
	x_end = get_x_end(vars);
	y_start = get_y_start(vars);
	y_end = get_y_end(vars);
	while (y_start <= y_end)
	{
		get_rowto_display(y_start, x_start, x_end, vars);
		y_start++;
	}
	get_map_to_display2(vars, y_start, y_end);
}

void	display_map_2(t_so_long *vars, int i, int ii)
{
	if (vars->map_to_display[i][ii] == 'C')
		display_coin(vars->mlx, vars->mlx_win, ii * 60, i * 60);
	if (vars->map_to_display[i][ii] == 'P')
		display_player(vars, ii * 60, i * 60);
	if (vars->map_to_display[i][ii] == '1')
		display_wall(vars->mlx, vars->mlx_win, ii * 60, i * 60);
	if (vars->map_to_display[i][ii] == '0')
		display_floor(vars->mlx, vars->mlx_win, ii * 60, i * 60);
	if (vars->map_to_display[i][ii] == 'E')
		display_door(vars->mlx, vars->mlx_win, ii * 60, i * 60);
	if (vars->map_to_display[i][ii] == 'M')
		display_monster(vars->mlx, vars->mlx_win, ii * 60, i * 60);
}

void	display_map(t_so_long *vars)
{
	int		i;
	int		ii;
	char	*nb_counter;

	i = 0;
	while (vars->map_to_display[i])
	{
		ii = 0;
		while (vars->map_to_display[i][ii])
		{
			display_map_2(vars, i, ii);
			ii++;
		}
		i++;
	}
	nb_counter = ft_itoa(vars->counter);
	mlx_string_put(vars->mlx, vars->mlx_win, 25, 25, 16777215, nb_counter);
	free(nb_counter);
}
