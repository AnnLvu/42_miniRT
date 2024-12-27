/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:38:04 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/27 16:34:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*new_color(float r, float g, float b)
{
	t_color	*c;

	c = (t_color *)malloc(sizeof(t_color));
	if (!c)
		return (NULL);
	c->r = r;
	c->g = g;
	c->b = b;
	return (c);
}

t_color	*get_color(char *str)
{
	int		r;
	int		g;
	int		b;
	char	**s;

	s = ft_split(str, ',');
	if (!s)
		return (NULL);
	r = ft_atoi(s[0]);
	g = ft_atoi(s[1]);
	b = ft_atoi(s[2]);
	ft_free_split(s);
	if (in_range_int(r, 0, 255) \
		&& in_range_int(g, 0, 255) \
		&& in_range_int(b, 0, 255))
		return (new_color(r / 255.0f, g / 255.0f, b / 255.0f));
	return (NULL);
}
