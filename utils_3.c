/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 08:58:53 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/28 20:47:41 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char const	*ft_cp(char const *s, char c, char **new_word)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*new_word = ft_substr(s, 0, i);
	return (s + i);
}

char	*read_file(char *path_map)
{
	char	*file;
	char	*tmp;
	int		nb_buffer;
	int		fd;

	check_file_map(path_map);
	fd = open(path_map, O_RDONLY);
	file = malloc(11 * sizeof(char));
	nb_buffer = read(fd, file, 10);
	file[nb_buffer] = '\0';
	tmp = malloc(11 * sizeof(char));
	nb_buffer = read(fd, tmp, 10);
	tmp[nb_buffer] = '\0';
	while (tmp[0])
	{
		file = ft_strjoin(file, tmp);
		nb_buffer = read(fd, tmp, 10);
		tmp[nb_buffer] = '\0';
	}
	free(tmp);
	return (file);
}

void	check_nb_argv(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("ERROR \n:Le programme doit ", 2);
		ft_putstr_fd("contenir un seul argument (le fichier .ber)\n", 2);
		exit (-1);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		nb_word;
	int		p_word;

	if (!s)
		return (NULL);
	nb_word = 0;
	p_word = 0;
	word_count(s, c, &nb_word);
	dst = malloc((nb_word + 1) * sizeof (char *));
	if (!dst)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			s = ft_cp(s, c, &dst[p_word]);
			p_word = p_word + 1;
		}
	}
	dst[p_word] = 0;
	return (dst);
}

void	check_len_rows(char **map)
{
	int	len_row;
	int	i;

	i = 0;
	len_row = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len_row)
		{
			ft_putstr_fd("ERROR \n:La map ne respecte ", 2);
			ft_putstr_fd("pas les régles (len rows)\n", 2);
			exit(-1);
		}
		i++;
	}
}
