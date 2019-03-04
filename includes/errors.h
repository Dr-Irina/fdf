/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:11 by hrice             #+#    #+#             */
/*   Updated: 2019/02/27 14:34:48 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
#include <errno.h>

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_MAP_READING	"Reading error"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CONV_TO_ARR	"Conversion to array"
# define ERR_CAMERA_INIT	"Camera initialization error"

#endif
