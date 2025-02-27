/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:42:48 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 17:08:36 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*get_plane(t_ftype type, char **s)
{
	t_vector	*coord;
	t_vector	*nv3d;
	t_color		*color;

	coord = get_vec(s[1], false);
	if (!coord)
		return (NULL);
	nv3d = get_vec(s[2], true);
	if (!nv3d)
	{
		free(coord);
		return (NULL);
	}
	color = get_color(s[3]);
	if (!color)
	{
		free(coord);
		free(nv3d);
		return (NULL);
	}
	return (new_figure((t_figure){type, nv3d, coord, color, NULL, NULL, 0, 0}));
}

float	plane_intersect(t_vector *camera, t_vector *ray, t_figure *plane)
{
	t_vector	*camera_to_plane;
	float		normal_dot_ray;
	float		normal_dot_dist;
	float		distance;

	normal_dot_ray = vec_dot_prod(plane->norm_v3d, ray);
	camera_to_plane = vec_sub(plane->coord, camera);
	if (normal_dot_ray != 0)
	{
		normal_dot_dist = vec_dot_prod(camera_to_plane, plane->norm_v3d);
		distance = normal_dot_dist / normal_dot_ray;
		free(camera_to_plane);
		if (distance < 0)
			return (0);
		return (distance);
	}
	free(camera_to_plane);
	return (0);
}
