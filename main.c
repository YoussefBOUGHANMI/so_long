/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:59:19 by youssef           #+#    #+#             */
/*   Updated: 2022/06/20 22:41:49 by yboughan         ###   ########.fr       */
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
		return (len_x - 12);
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
	printf("len : %i\n" , len_y);
	if (len_y < 12)
		return (0);
	else if (vars->y_pos + 5 > len_y - 1)
		return (len_y - 12);
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




char	*get_rowto_display(int y_start, int x_start, int x_end, char **map)
{
	char	*row_to_return;
	int	i;

	i = 0;
	row_to_return = malloc(12 * sizeof(char));
	while (x_start <= x_end)
	{
		row_to_return[i] = map[y_start][x_start];
		x_start++;
		i++;
	}
	row_to_return[i] = '\0';
	return (row_to_return);
}

void	get_map_to_display(t_so_long *vars)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;
	char		**map_to_display;

	x_start = get_x_start(vars);
	x_end = get_x_end(vars);
	y_start = get_y_start(vars);
	y_end = get_y_end(vars);
	map_to_display = malloc(12 * sizeof(char *));
	while (y_start <= y_end)
	{
		if (y_end > 11)
			map_to_display[10 - (y_end - y_start)] = get_rowto_display(y_start , x_start , x_end, vars->map);
		else
			map_to_display[y_start] = get_rowto_display(y_start , x_start , x_end, vars->map);
		y_start++;
	}
	if (y_end > 11)
		map_to_display[11] = NULL;
	else 
		map_to_display[y_start] = NULL;
	vars->map_to_display = map_to_display;
}










void	display_map(t_so_long *vars)
{
	int	i;
	int	ii;
	
	printf("display \n");
	i = 0;
	while (vars->map_to_display[i])
	{
		ii = 0;
		while (vars->map_to_display[i][ii])
		{
			if (vars->map_to_display[i][ii] == 'C')
				display_coin(vars->mlx, vars->mlx_win, ii*60 , i*60);
			if (vars->map_to_display[i][ii] == 'P')
				display_player(vars->mlx, vars->mlx_win, ii*60, i*60);
			if (vars->map_to_display[i][ii] == '1')
				display_wall(vars->mlx, vars->mlx_win, ii*60, i*60);
			if (vars->map_to_display[i][ii] == '0')
				display_floor(vars->mlx, vars->mlx_win, ii*60, i*60);
			if (vars->map_to_display[i][ii] == 'E')
				display_door(vars->mlx, vars->mlx_win, ii*60, i*60);
			ii++;
		}
		i++;
	}
}

//void move_left(char **map)



void	update_player_pos(t_so_long *vars);



int	move_player(int key, t_so_long *vars)
{
	if (key == 0)
	{
		vars->map[7][1] = '0';
		vars->map[7][2] = 'P';
		update_player_pos(vars);
		get_map_to_display(vars);
		display_map(vars);
		printf("0\n");
	//	move_left(map);
	}
	else if (key == 1)
	//	move_down(map);
		printf("1\n");
	else if (key == 2)
	//	move_rigth(map);
		printf("2\n");
	else if (key == 13)
	//	move_up(map);
		printf("13\n");
	else if (key == 53)
		exit(0);
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
	while(vars->map[y] && !ft_strchr(vars->map[y] , 'P'))
		y++;
	while(vars->map[y][x] && vars->map[y][x] != 'P')
		x++;
	vars->x_pos = x;
	vars->y_pos = y;
	printf("%i , %i \n" , x, y );
}


void	so_long(char **map)
{
	t_so_long	vars;


	vars.map = map;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, ft_strlen(map[0]) * 60, get_nb_rows(map) * 60, "so_long");
	update_player_pos(&vars);
	//display_map(&vars);
	get_map_to_display(&vars);
	int i = 0;
	while (vars.map_to_display[i])
	{
		printf(":::::    %s\n" , vars.map_to_display[i]);
		i++;
	}
	display_map(&vars);
	printf("ok\n");
	mlx_key_hook(vars.mlx_win, move_player, &vars);
	mlx_loop(vars.mlx);
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
