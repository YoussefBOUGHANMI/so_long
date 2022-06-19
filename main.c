/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:59:19 by youssef           #+#    #+#             */
/*   Updated: 2022/06/19 15:02:15 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

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




void	display_map(void *mlx, void *mlx_win, char **map)
{
	int	i;
	int	ii;

	i = 0;
	while (map[i])
	{
		ii = 0;
		while (map[i][ii])
		{
			if (map[i][ii] == 'C')
				display_coin(mlx, mlx_win, ii*60 , i*60);
			if (map[i][ii] == 'P')
				display_player(mlx, mlx_win, ii*60, i*60);
			if (map[i][ii] == '1')
				display_wall(mlx, mlx_win, ii*60, i*60);
			if (map[i][ii] == '0')
				display_floor(mlx, mlx_win, ii*60, i*60);
			if (map[i][ii] == 'E')
				display_door(mlx, mlx_win, ii*60, i*60);
			ii++;
		}
		i++;
	}
}









void	so_long(char **map)
{

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, ft_strlen(map[0]) * 60, get_nb_rows(map) * 60, "so_long");
	display_map(mlx, mlx_win, map);
	mlx_loop(mlx);
}

int main(int argc, char **argv)
{
	char **map;
	char *file;
	int i=0;

	check_nb_argv(argc);
	file = read_file(argv[1]);
	map = ft_split(file , '\n');
	check_map(map);
	while(map[i])
		printf("%s\n" , map[i++]);
	so_long(map);
}
