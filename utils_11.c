/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <yboughan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:22:54 by youssef           #+#    #+#             */
/*   Updated: 2022/06/28 20:11:33 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	init_mlx_win(t_so_long *vars)
{
	int	nb_rows;
	int	nb_cols;

	nb_rows = get_nb_rows(vars->map);
	nb_cols = ft_strlen(vars->map[0]);
	if (nb_rows < 12 && nb_cols < 12)
		vars->mlx_win = mlx_new_window(vars->mlx, ft_strlen(vars->map[0])
				* 60, get_nb_rows(vars->map) * 60, "so_long");
	else if (nb_rows > 12 && nb_cols > 12)
		vars->mlx_win = mlx_new_window(vars->mlx, 11 * 60, 11 * 60, "so_long");
	else if (nb_rows > 12 && nb_cols < 12)
		vars->mlx_win = mlx_new_window(vars->mlx,
				ft_strlen(vars->map[0]) * 60, 11 * 60, "so_long");
	else if (nb_rows < 12 && nb_cols > 12)
		vars->mlx_win = mlx_new_window(vars->mlx, 11 * 60,
				get_nb_rows(vars->map) * 60, "so_long");
}

void	so_long(char **map)
{
	t_so_long	vars;

	vars.direction = 0;
	vars.dead = 0;
	vars.counter = 0;
	vars.nb_coin = ft_count_coin(map);
	vars.map = map;
	vars.mlx = mlx_init();
	init_mlx_win(&vars);
	init_map_to_display(&vars);
	update_player_pos(&vars);
	get_map_to_display(&vars);
	display_map(&vars);
	mlx_key_hook(vars.mlx_win, move_player, &vars);
	mlx_loop(vars.mlx);
}

void	check_element_diff(char **map)
{
	int	i;
	int	ii;

	i = 0;
	while (map[i])
	{
		ii = 0;
		while (map[i][ii])
		{
			if (map[i][ii] != '1' && map[i][ii] != '0' && map[i][ii] != 'C' &&
				map[i][ii] != 'P' && map[i][ii] != 'M' && map[i][ii] != 'E')
			{
				ft_putstr_fd("ERROR \n:La map ne respecte pas les ", 2);
				ft_putstr_fd("régles (élement non défini) \n", 2);
				exit(-1);
			}
			ii++;
		}
		i++;
	}
}
