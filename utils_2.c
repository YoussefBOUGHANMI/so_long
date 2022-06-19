/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 08:55:26 by yboughan          #+#    #+#             */
/*   Updated: 2022/06/19 08:58:43 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"so_long.h"

int	word_count(char const *s, char c, int *nb_word)
{
	int	first_word;

	first_word = 1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (*(s - 1) == c || first_word)
			{
				*nb_word = *nb_word + 1;
				first_word = 0;
			}
			s++;
		}
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	len_dst;

	if (!s)
		return (NULL);
	i = 0;
	len_dst = ft_strlen(s + start);
	if (len > len_dst)
		dst = malloc((len_dst + 1) * sizeof(char));
	else
		dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[start + i] && i < len && start < ft_strlen((char *)s))
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char const	*ft_cp(char const *s, char c, char **new_word)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*new_word = ft_substr(s, 0, i);
	return (s + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy((char *)s3, (char *)s1, len_s1 + 1);
	ft_strlcpy((char *)(s3 + len_s1), (char *)s2, len_s2 + 1);
	free((char *)s1);
	return (s3);
}

void	check_file_map(char *path_map)
{
	int	fd;
	int	len_path;

	fd = open(path_map, O_RDONLY);
	
	if (fd < 0)
	{
		perror("ERROR \n");
		exit (-1);
	}
	len_path = ft_strlen(path_map);
	if (ft_strncmp(path_map + (len_path - 4), ".ber", 4) != 0)
	{
		ft_putstr_fd("ERROR \n: La carte n'est pas au format *.ber\n", 2);
		exit (-1);
	}	
}


