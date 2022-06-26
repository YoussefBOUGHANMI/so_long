/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:15:53 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/26 22:28:32 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	display_monster(void *mlx, void *mlx_win, int x, int y)
{
	char	*relative_path = "./tiles/monster.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if ((int)img == 0)
	{
		ft_putstr_fd("ERROR \n:Le programme n'a pas reussi à charger l'image monster \n", 2);
		exit(-1);
	}
	mlx_put_image_to_window(mlx,mlx_win,img,x , y);
	mlx_destroy_image(mlx, img);
}


int	len_n(int n)
{
	int	i;

	i = 1;
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	neg_case(long *n, int *stop, int *len, char *a)
{
	if (!a)
		return ;
	*n = *n * -1;
	*stop = 1;
	*len = *len + 1;
	a[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*a;
	long	new_n;
	int		len;
	int		stop;

	new_n = n;
	stop = 0;
	len = len_n(n);
	if (new_n < 0)
	{
		a = malloc((len + 2) * sizeof(char));
		neg_case(&new_n, &stop, &len, a);
	}
	else
		a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[len--] = 0;
	while (len >= stop)
	{
		a[len--] = (new_n % 10) + 48;
		new_n = new_n / 10;
	}
	return (a);
}

