/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:53:49 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/19 15:29:25 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*new_camera(t_vector *origin, t_vector *direction, float fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		print_error(-1);
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = fov;
	return (camera);
}
