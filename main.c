/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:59:19 by youssef           #+#    #+#             */
/*   Updated: 2022/06/21 22:23:03 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"



void	free_map(char **map)
{
	int len_map;
	int	i;

	len_map = get_nb_rows(map);
	i = 0;
	while ( i < len_map)
	{
		free(map[i]);
		i++;
	}
}


void	init_map_to_display(t_so_long *vars)
{
	int	i;

	i = 0;
	vars->map_to_display = malloc(11 * sizeof(char *));
	while ( i < 11 )
	{
		vars->map_to_display[i] = malloc(11 * sizeof(char));
		i++;
	}
}	



void	update_player_pos(t_so_long *vars);

void	get_map_to_display2(t_so_long *vars, int y_start, int y_end, char **map_to_display)
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
	get_map_to_display2(vars, y_start, y_end , vars->map_to_display);
}

void	display_map(t_so_long *vars)
{
	int o = 0;
	while (vars->map_to_display[o])
	{
		printf("%s\n", vars->map_to_display[o]);
		o++;
	}
	int	i;
	int	ii;
	
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


void	move_left(t_so_long *vars)
{
	if (vars->map[vars->y_pos][vars->x_pos - 1] == '0')
	{
		vars->map[vars->y_pos][vars->x_pos - 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
	}
	else if (vars->map[vars->y_pos][vars->x_pos-1] == 'C')
	{
		vars->map[vars->y_pos][vars->x_pos - 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
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


void	move_rigth(t_so_long *vars)
{
	if (vars->map[vars->y_pos][vars->x_pos + 1] == '0')
	{
		vars->map[vars->y_pos][vars->x_pos + 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
	}
	else if (vars->map[vars->y_pos][vars->x_pos + 1] == 'C')
	{
		vars->map[vars->y_pos][vars->x_pos + 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
	}
	else if (vars->map[vars->y_pos][vars->x_pos + 1] == 'E')
	{
		if (vars->nb_coin == 0)
		{
			printf("You win !");
			exit (0);
		}
	}
}


void	move_down(t_so_long *vars)
{
	if (vars->map[vars->y_pos - 1][vars->x_pos] == '0')
	{
		vars->map[vars->y_pos - 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
	}
	else if (vars->map[vars->y_pos - 1][vars->x_pos] == 'C')
	{
		vars->map[vars->y_pos - 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
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
	if (vars->map[vars->y_pos + 1][vars->x_pos] == '0')
	{
		vars->map[vars->y_pos + 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
	}
	else if (vars->map[vars->y_pos + 1][vars->x_pos] == 'C')
	{
		vars->map[vars->y_pos + 1][vars->x_pos] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->nb_coin = vars->nb_coin - 1;
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






int	move_player(int key, t_so_long *vars)
{
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
	if (key == 1 || key == 2 || key == 13 || key ==0)
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
	init_map_to_display(&vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, ft_strlen(map[0]) * 60, get_nb_rows(map) * 60, "so_long");
	update_player_pos(&vars);
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
