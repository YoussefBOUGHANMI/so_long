/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:59:19 by youssef           #+#    #+#             */
/*   Updated: 2022/06/28 20:23:07 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	char	*file;

	check_nb_argv(argc);
	file = read_file(argv[1]);
	map = ft_split(file, '\n');
	check_map(map);
	so_long(map);
}
