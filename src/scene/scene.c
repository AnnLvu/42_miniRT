/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:15 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/19 15:32:52 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(t_camera *camera, t_sphere *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		print_error(-1);
	scene->camera = camera;
	scene->sphere = sphere;
	scene->width = 0;
	scene->hight = 0;
	return(scene);
}
