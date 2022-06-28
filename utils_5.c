/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:13:09 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/28 19:53:49 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	display_player(t_so_long *vars, int x, int y)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*img;

	if (vars->direction == 0)
		relative_path = "./tiles/player_left.xpm";
	else if (vars->direction == 1)
		relative_path = "./tiles/player_rigth.xpm";
	if (vars->dead == 1)
		relative_path = "./tiles/player_dead.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, relative_path,
			&img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi ", 2);
		ft_putstr_fd("à charger l'image player \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
}

void	display_wall(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*img;

	relative_path = "./tiles/wall.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi ", 2);
		ft_putstr_fd("à charger l'image wall \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	mlx_destroy_image(mlx, img);
}

void	display_coin(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*img;

	relative_path = "./tiles/coin.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi ", 2);
		ft_putstr_fd("à charger l'image coin \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	mlx_destroy_image(mlx, img);
}

void	display_door(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*img;

	relative_path = "./tiles/door.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi ", 2);
		ft_putstr_fd("à charger l'image door \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	mlx_destroy_image(mlx, img);
}

void	display_floor(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*img;

	relative_path = "./tiles/floor.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi ", 2);
		ft_putstr_fd("à charger l'image floor \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	mlx_destroy_image(mlx, img);
}
