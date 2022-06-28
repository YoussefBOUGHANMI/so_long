/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:59:19 by youssef           #+#    #+#             */
/*   Updated: 2022/06/27 21:22:56 by youssef          ###   ########.fr       */
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
	int	nb_rows;
	int	nb_cols;


	nb_rows = get_nb_rows(vars->map);
	nb_cols = ft_strlen(vars->map[0]);
	if (nb_rows > 11)
		nb_rows = 11;
	if (nb_cols > 11)
		nb_cols = 11;
	i = 0;
	vars->map_to_display = malloc(nb_rows * sizeof(char *));
	while ( i < nb_rows )
	{
		vars->map_to_display[i] = malloc(nb_cols * sizeof(char));
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

void	display_map_2(t_so_long *vars, int i, int ii)
{
	if (vars->map_to_display[i][ii] == 'C')
		display_coin(vars->mlx, vars->mlx_win, ii*60 , i*60);
	if (vars->map_to_display[i][ii] == 'P')
		display_player(vars, ii*60, i*60);
	if (vars->map_to_display[i][ii] == '1')
		display_wall(vars->mlx, vars->mlx_win, ii*60, i*60);
	if (vars->map_to_display[i][ii] == '0')
		display_floor(vars->mlx, vars->mlx_win, ii*60, i*60);
	if (vars->map_to_display[i][ii] == 'E')
		display_door(vars->mlx, vars->mlx_win, ii*60, i*60);
	if (vars->map_to_display[i][ii] == 'M')
		display_monster(vars->mlx, vars->mlx_win, ii*60, i*60);

}
void	display_map(t_so_long *vars)
{
	int	i;
	int	ii;
	char	*nb_counter;
	
	i = 0;
	while (vars->map_to_display[i])
	{
		ii = 0;
		while (vars->map_to_display[i][ii])
		{
			display_map_2(vars, i ,ii);
			ii++;
		}
		i++;
	}
	nb_counter = ft_itoa(vars->counter);
	mlx_string_put(vars->mlx ,vars->mlx_win, 25 , 25, 16777215 , nb_counter);
	free(nb_counter);
}


void	check_monster(t_so_long *vars , char c)
{
	int i = 0;
	if (c == 'M')
		vars->dead = 1;
}



void	move_left(t_so_long *vars)
{
	check_monster(vars , vars->map[vars->y_pos][vars->x_pos - 1]);
	if (vars->map[vars->y_pos][vars->x_pos - 1] == '0')
	{
		vars->map[vars->y_pos][vars->x_pos - 1] = 'P';
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->counter++;
	}
	else if (vars->map[vars->y_pos][vars->x_pos-1] == 'C')
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
	check_monster(vars , vars->map[vars->y_pos][vars->x_pos + 1]);
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
	check_monster(vars , vars->map[vars->y_pos - 1][vars->x_pos]);
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
	check_monster(vars , vars->map[vars->y_pos + 1][vars->x_pos]);
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




void	quit_cause_dead(void)
{
	ft_putstr_fd("Sorry you lose try again ! \n", 0);
	exit(0);
}

int	move_player(int key, t_so_long *vars)
{
	if (vars->dead == 1)
		quit_cause_dead();
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
}

int	ft_count_coin(char **map)
{
	int	i;
	int	ii;
	int	nb;

	i = 0;
	nb = 0;
	while (map[i])
	{
		ii = 0;
		while (map[i][ii])
		{
			if (map[i][ii] == 'C')
				nb++;
			ii++;
		}
		i++;
	}
	return (nb);
}


void	init_mlx_win(t_so_long *vars)
{
	int	nb_rows;
	int	nb_cols;

	nb_rows = get_nb_rows(vars->map);
	nb_cols = ft_strlen(vars->map[0]);
	if (nb_rows < 12 && nb_cols < 12)
		vars->mlx_win = mlx_new_window(vars->mlx, ft_strlen(vars->map[0]) * 60, get_nb_rows(vars->map) * 60, "so_long");
	else if (nb_rows > 12 && nb_cols > 12)
		vars->mlx_win = mlx_new_window(vars->mlx, 11 * 60, 11 * 60, "so_long");
	else if (nb_rows > 12 && nb_cols < 12)
		vars->mlx_win = mlx_new_window(vars->mlx, ft_strlen(vars->map[0]) * 60, 11 * 60, "so_long");
	else if (nb_rows < 12 && nb_cols > 12)
		vars->mlx_win = mlx_new_window(vars->mlx, 11 * 60, get_nb_rows(vars->map) * 60, "so_long");
}


void	so_long(char **map)
{
	t_so_long	vars;
	
	vars.direction = 0;
	vars.dead  = 0;
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
	while(map[i])
	{
		ii = 0;
		while(map[i][ii])
		{
			if (map[i][ii] != '1' && map[i][ii] != '0' && map[i][ii] != 'C' &&
				map[i][ii] != 'P' && map[i][ii] != 'M' && map[i][ii] != 'E')
			{
				ft_putstr_fd("ERROR \n:La map ne respecte pas les régles (élement non défini) \n", 2);
				exit(-1);
			}
			ii++;

		}
		i++;
	}
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
	so_long(map);
}
