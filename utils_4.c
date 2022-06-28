/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:01:09 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/28 19:44:42 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_firstlast_rows(char **map, int nb_rows)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[nb_rows - 1][i] != '1')
		{
			ft_putstr_fd("ERROR \n:La map ne respecte pas", 2);
			ft_putstr_fd("les régles (last first rows) \n", 2);
			exit(-1);
		}
		i++;
	}
}

void	check_borders(char **map)
{
	int	len_rows;
	int	i;

	len_rows = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len_rows - 1] != '1')
		{
			ft_putstr_fd("ERROR \n:La map ne respecte pas ", 2);
			ft_putstr_fd("les régles (borders) \n", 2);
			exit(-1);
		}
		i++;
	}
}

void	check_caracter(char **map)
{
	int	nb_carac;
	int	i;
	int	ii;

	i = 0;
	nb_carac = 0;
	while (map[i])
	{
		ii = 0;
		while (map[i][ii])
		{
			if (map[i][ii] == 'P')
				nb_carac++;
			ii++;
		}
		i++;
	}
	if (nb_carac != 1)
	{
		ft_putstr_fd("ERROR \n:La map ne respecte pas ", 2);
		ft_putstr_fd("les régles (Caracter) \n", 2);
		exit(-1);
	}
}

void	check_element(char **map, char el)
{
	int	nb_el;
	int	i;
	int	ii;

	i = 0;
	nb_el = 0;
	while (map[i])
	{
		ii = 0;
		while (map[i][ii])
		{
			if (map[i][ii] == el)
				nb_el++;
			ii++;
		}
		i++;
	}
	if (nb_el < 1)
	{
		ft_putstr_fd("ERROR \n:La map ne respecte pas ", 2);
		ft_putstr_fd("les régles (Exit or Coin) \n", 2);
		exit(-1);
	}
}

void	check_map(char **map)
{
	int	nb_rows;

	nb_rows = get_nb_rows(map);
	check_len_rows(map);
	check_firstlast_rows(map, nb_rows);
	check_borders(map);
	check_caracter(map);
	check_element(map, 'E');
	check_element(map, 'C');
	check_element_diff(map);
}
