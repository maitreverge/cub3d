/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psf_font.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:05:30 by p          #+#    #+#             */
/*   Updated: 2024/04/23 14:58:30 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// port of profanOS's psf font loader and renderer
// https://github.com/elydre/profanOS/blob/main/zlibs/mod/panda.c

#include <cub3d.h>

t_font_data	*font_load(char *file)
{
	t_font_data	*psf;
	uint32_t	magic;
	uint32_t	version;
	int			fd;
	int			u;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	psf = secure_malloc(sizeof(t_font_data));
	u = read(fd, &magic, sizeof(uint32_t));
	u = read(fd, &version, sizeof(uint32_t));
	u = read(fd, &u, sizeof(uint32_t));
	u = read(fd, &u, sizeof(uint32_t));
	u = read(fd, &psf->charcount, sizeof(uint32_t));
	u = read(fd, &psf->charsize, sizeof(uint32_t));
	u = read(fd, &psf->height, sizeof(uint32_t));
	u = read(fd, &psf->width, sizeof(uint32_t));
	if (magic != 0x864ab572 || version != 0)
		return (NULL);
	psf->data = secure_malloc(psf->charcount * psf->charsize);
	u = read(fd, psf->data, psf->charcount * psf->charsize);
	close(fd);
	return (psf);
}

void	font_free(t_font_data *psf)
{
	if (!psf)
		return ;
	free(psf->data);
	free(psf);
}

void	set_tow_vars(int *a, int *b, int v)
{
	*a = v;
	*b = v;
}

void	font_draw(t_map *map, uint32_t xo, uint32_t yo, uint8_t c)
{
	uint32_t	x;
	uint32_t	y;
	int			i;
	int			j;

	set_tow_vars((int *) &x, (int *) &y, 0);
	set_tow_vars(&i, &j, -1);
	while (++i < (int) map->font->charsize)
	{
		if (x >= map->font->width)
		{
			x = 0;
			y++;
		}
		j = 8;
		while (j--)
		{
			if ((map->font->data + (c * map->font->charsize))[i] & (1 << j))
				map->mlx->image_data[(yo + y) * WIN_WIDTH + (xo + x)] = 0;
			if (x >= map->font->width)
				break ;
			x++;
		}
	}
}

void	font_print(t_map *map, uint32_t x, uint32_t y, char *str)
{
	t_font_data	*psf;
	uint32_t	c;

	psf = map->font;
	while (*str)
	{
		c = *str;
		if (c >= psf->charcount)
			c = 0;
		font_draw(map, x, y, c);
		x += psf->width;
		str++;
	}
}
