/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:16:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/09 17:00:27 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keyhook(mlx_key_data_t keydata, t_fractal *fractal)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
	else if (keydata.key == MLX_KEY_LEFT)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_RIGHT)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_UP)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_DOWN)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_KP_ADD)
		fractal->max_iter += 10; 
	else if (keydata.key == MLX_KEY_KP_SUBTRACT)
		fractal->max_iter -= 10;
	fractal_render(fractal);
}


void	ft_scroll_zoom(double ydelta, double xdelta, t_fractal *fractal)
{
	//scroll arriba
	if (xdelta > 0)
	{
		fractal->zoom *= 0.95;
	}
	//scroll abajo
	else if (xdelta < 0)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
}



void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_scroll_zoom(double ydelta, double xdelta, void *param)
{
	(void)param;
	(void)ydelta;
	
		printf("%f, \n", xdelta);
}

// void	hooks_init(t_fractal *fractal)
// {
// 	mlx_scroll_hook(fractal->mlx, &ft_scroll_zoom, fractal); //TODO ftscroll
// 	mlx_key_hook(fractal->mlx, &ft_keyhook, NULL); //ft_keyhook
// 	// añadir hooks de cerrar ventana, seguimiento del cursor 
// }



void	keys(mlx_key_data_t keydata, void *param)
{
	(void)param;
	(void)keydata;
	if (keydata.action == MLX_PRESS)
		ft_printf("%d, \n", keydata.os_key);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		ft_printf("cara");
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		ft_printf("cola!!");
}

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	// Create a new image
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (EXIT_FAILURE);

	ft_printf("%i",ft_atoi("89"));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        ft_error();

	mlx_key_hook(mlx, &keys, NULL);
	mlx_scroll_hook(mlx, &ft_scroll_zoom, NULL);
	// mlx_mouse_hook(mlx, &ft_mouse_hook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
