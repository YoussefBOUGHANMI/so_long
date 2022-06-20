/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:01:33 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/20 22:03:29 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>


typedef struct s_so_long
{
	int		x_pos;
	int		y_pos;
	int		counter;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_to_display;
}	t_so_long;


size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	check_nb_argv(int argc);
char	*read_file(char *path_map);
void	check_file_map(char *path_map);
char const	*ft_cp(char const *s, char c, char **new_word);
int	word_count(char const *s, char c, int *nb_word);
void	check_map(char **map);
void	check_element(char **map , char el);
void	check_caracter(char **map);
void	check_borders(char **map);
void	check_firstlast_rows(char **map , int nb_rows);
void	check_len_rows(char **map);
int	get_nb_rows(char **map);
void	display_player(void *mlx, void *mlx_win, int x, int y);
void	display_coin(void *mlx, void *mlx_win, int x, int y);
void	display_wall(void *mlx, void *mlx_win, int x, int y);
void	display_door(void *mlx, void *mlx_win, int x, int y);
void	display_floor(void *mlx, void *mlx_win, int x, int y);

#endif
