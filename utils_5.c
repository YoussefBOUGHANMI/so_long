/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:13:09 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/19 18:14:40 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	display_player(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path = "./tiles/player.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi à charger l'image player \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx,mlx_win,img,x , y);
	mlx_destroy_image(mlx, img);
}

void	display_wall(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path = "./tiles/wall.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi à charger l'image wall \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx,mlx_win,img,x , y);
	mlx_destroy_image(mlx, img);
}

void	display_coin(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path = "./tiles/coin.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi à charger l'image coin \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx,mlx_win,img,x , y);
	mlx_destroy_image(mlx, img);
}



void	display_door(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path = "./tiles/door.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi à charger l'image door \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx,mlx_win,img,x , y);
	mlx_destroy_image(mlx, img);
}

void	display_floor(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path = "./tiles/floor.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi à charger l'image floor \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx,mlx_win,img,x , y);
	mlx_destroy_image(mlx, img);
}
