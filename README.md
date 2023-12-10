# fractol04

# Informations
- https://qst0.github.io/ft_libgfx/man_mlx.html
- 

# Math
Formel: zn + 1 = zn + c

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
