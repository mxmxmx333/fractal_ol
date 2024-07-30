/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_messages.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:45:12 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 14:33:09 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_MESSAGES_H
# define DEF_MESSAGES_H

# define USAGE "Usage (modes to start program):\n\
 ./fractol [options] \n\
	options:\n\
[<empty> = default mode \n| <mandelbrot> mandelbrot mode \n \
	<julia> <-2.0 - 2.0> <-2.0 - 2.0> = julia mode inkl starting params \n\
	<buddhabrot> = buddhabrot mode \
	(optional: <POS_INT> <POS_INT> <POS_INT> to define the iterations of the \
three layers of buddhabrot\n"
# define DEFAULT_MODE "You entered the program in default mode\n"
# define JULIA_MODE "You entered the program in julia mode\n"
# define MLX_ERROR "Error initializing mlx\n"
# define MANDELBROT_MODE "You entered the program in mandelbrot mode\n"
# define BUDDHABROT_MODE "You entered the program in buddhabrot mode\n"
# define CONTROLS "CONTROLS:\n\
	- Move: arrows\n\
	- Zoom: mouse wheel | left and right click\n\
	- Change colorsets: numbers 1 - 0\n\
	- Modes (julia: j, mandelbrot: m, buddhabrot: b)\n\
	- Rotate: r\n\
	- Exit: esc\n\
	- q / w: copy colorset to color 2 / 3 (for buddha only)\n\
	- s: swap coloring (for julia and mandelbrot)\n"

#endif