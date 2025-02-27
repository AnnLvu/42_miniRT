/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:32:36 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/21 17:10:25 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	base_intersect(t_vector *camera, t_vector *ray, \
									t_figure *plane, float radius)
{
	float		distance;
	t_vector	*intersection_point;
	t_vector	*camera_to_point;

	distance = plane_intersect(camera, ray, plane);
	if (distance > 0)
	{
		intersection_point = new_vec(
				camera->x + ray->x * distance,
				camera->y + ray->y * distance,
				camera->z + ray->z * distance);
		camera_to_point = vec_sub(intersection_point, plane->coord);
		if (vec_len(camera_to_point) <= radius)
		{
			free(intersection_point);
			free(camera_to_point);
			return (distance);
		}
		free(intersection_point);
		free(camera_to_point);
	}
	return (0);
}

static void	compute_cylinder_intersection(t_vector *camera, t_vector *ray, \
							t_figure *cylinder, t_cylinder_intersect *ci)
{
	ci->camera_to_cylinder = vec_sub(camera, cylinder->coord);
	ci->a = vec_dot_prod(ray, ray) - \
			powf(vec_dot_prod(ray, cylinder->norm_v3d), 2.0f);
	ci->b = 2 * (vec_dot_prod(ray, ci->camera_to_cylinder) - \
		(vec_dot_prod(ray, cylinder->norm_v3d) * \
			vec_dot_prod(ci->camera_to_cylinder, cylinder->norm_v3d)));
	ci->c = vec_dot_prod(ci->camera_to_cylinder, ci->camera_to_cylinder) - \
	powf(vec_dot_prod(ci->camera_to_cylinder, cylinder->norm_v3d), 2.0f) - \
	powf(cylinder->diameter / 2.0f, 2.0f);
	ci->discriminant = ci->b * ci->b - 4 * ci->a * ci->c;
}

static void	check_cylinder_intersection(t_vector *ray, t_figure *cylinder, \
									t_cylinder_intersect *ci, float *d_min)
{
	if (ci->discriminant < 0)
	{
		free(ci->camera_to_cylinder);
		return ;
	}
	ci->t1 = (-ci->b - sqrtf(ci->discriminant)) / (2 * ci->a);
	ci->t2 = (-ci->b + sqrtf(ci->discriminant)) / (2 * ci->a);
	ci->m = vec_dot_prod(ray, cylinder->norm_v3d) * ci->t1 + \
		vec_dot_prod(ci->camera_to_cylinder, cylinder->norm_v3d);
	if (ci->t1 > 0 && ci->m >= 0 && ci->m <= cylinder->hight)
		*d_min = ci->t1;
	ci->m = vec_dot_prod(ray, cylinder->norm_v3d) * ci->t2 + \
		vec_dot_prod(ci->camera_to_cylinder, cylinder->norm_v3d);
	if (ci->t2 > 0 && ci->m >= 0 && ci->m <= cylinder->hight && ci->t2 < *d_min)
		*d_min = ci->t2;
	free(ci->camera_to_cylinder);
}

static void	lateral_plane_intersect(t_vector *camera, t_vector *ray, \
			t_figure *cylinder, float *d_min)
{
	t_cylinder_intersect	ci;

	compute_cylinder_intersection(camera, ray, cylinder, &ci);
	check_cylinder_intersection(ray, cylinder, &ci, d_min);
}

float	cylinder_intersect(t_vector *camera, t_vector *ray, \
											t_figure *cylinder)
{
	float	d_min;

	d_min = FLT_MAX;
	lateral_plane_intersect(camera, ray, cylinder, &d_min);
	cylinder_base_intersect(camera, ray, cylinder, &d_min);
	if (d_min < FLT_MAX)
		return (d_min);
	return (0);
}
