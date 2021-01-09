/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:34:01 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 18:09:20 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
** Bonus part, turning sepia color filter and ratio of light shining
** ROTATE_ANGLE and MOVE_LEN manages camera translation/rotation
*/

# ifndef FILTER
#  define FILTER 0
# endif
# ifndef SHINE
#  define SHINE 15
# endif
# define ROTATE_ANGLE 1
# define MOVE_LEN 2

/*
** Minimal distance between camera and object (double)
*/

# define DIST 0.01

/*
** File name for scresaving, option --save
*/

# define SAVE_FILE_NAME "screensave.bmp"

/*
** File descriptor fo error messages (1 or 2 for stderr)
*/

# define FD_ERR 1

/*
** Error static messages
*/

# define PRECISION 0.1

# define MLX_ERR "MiniLibX error"
# define MLX_IMG_ERR "MiniLibX Image error"
# define MLX_WIN_ERR "MiniLibX Window error"
# define FILE_EXT_ERR "Wrong file extension, should be .rt"
# define ARGS_ERR "Wrong arguments"
# define SP_ERR "Mistake in Sphere data"
# define PL_ERR "Mistake in Plane data"
# define SQ_ERR "Mistake in Square data"
# define CY_ERR "Mistake in Cylinder data"
# define TR_ERR "Mistake in Triangle data"
# define TYPE_ERR "Unknown or wrong type of element"
# define TYPE_NUM_ERR "Wrong number or no Resolution, Ambient light or Cams"
# define GNL_ERR "GNL error or wrong line"
# define AMB_ERR "Mistake in Ambient light data"
# define CAM_ERR "Mistake in Camera data"
# define LIGHT_ERR "Mistake in Light data"
# define LIGHT_NORM_ERR "Wrong orientation vector in directed light last param"
# define LIBFT_ERR "Libft list function error"
# define RES_ERR "Wrong Resolution format"

/*
** Not error messages for user informing
*/

# define MLX_NAME "miniRT by tcider"
# define RT_GOING_MSG "Render processing.."
# define RT_OK_MSG "Done!"
# define RT_HELP1_MSG "Press q/w/e/a/s/d - rotate cam, r/t/y/f/g/h - move cam"
# define RT_HELP2_MSG "Use ESC for exit and left/right for changing camera"
# define RT_RES_MSG "Resolution has been shrinked to feet the screen"
# define SAVING_MSG "Saving image.."
# define SAVING_OK_MSG "Saving done"
# define BYE_MSG "Good bye!"

/*
** Keys codes for manipulating
*/

# define EXIT_KEY 53
# define PREV_CAM_KEY 123
# define NEXT_CAM_KEY 124
# define RXU_KEY 12
# define RYU_KEY 13
# define RZU_KEY 14
# define RXD_KEY 0
# define RYD_KEY 1
# define RZD_KEY 2
# define MXU_KEY 15
# define MYU_KEY 17
# define MZU_KEY 16
# define MXD_KEY 3
# define MYD_KEY 5
# define MZD_KEY 4

#endif
