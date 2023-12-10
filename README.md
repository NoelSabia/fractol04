# fractol04

# Informations
- https://qst0.github.io/ft_libgfx/man_mlx.html
- https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5

# Math
Formel: zn + 1 = zn + c
If the number is a finite number show it in color 1
If the number is an infinite number show it in color 2

# Library (.h)
- mlx.h
- mlx_init() --> entry point
- mlx_new_window --> manage windows
- mlx_pixel_put --> draw inside window
- mlx_new_image --> manipulate images
- mlx_loop --> handel keyboard or mouse events
- (LINKING: -lmlx -framework OpenGL -framework AppKit)

# Worksteps
1. Setup MiniLibX library
2. Create a window, image etc pp
3. Iterate through every pixel of the window
4. For every pixel calculate the complex number it represents and put it into the suite
5. If the suite diverges, color the pixel in white.
6. If the suite converges, color the pixel in black.

# Functions
## Main
- set x and y to 0
- two while loops (first for x, second for y)
- inside of secons while loop --> if (strncmp mandel or julia with input) | else ft_putendl_fd and exit
- mlx_put_image_to_window();
## ft_mandelbrot
- 
