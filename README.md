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
| Fcts | My functions| does|
|-|-|-|
| .gitignore | .gitignore| ignores certain files |
| Makefile | Makefile | Automation |
| fractol.c | fractol.c | checks args, initialize, fractolpic,... |
| fractol.h | fractol.h | two structs, #defines, libs, functs |
| algorithm.c | mandelbrot.c | for each y number the hole x row plus color | 
| algorithm2.c | julia.c | for each y number the hole x row plus color |
| utils.c | coloring.c | important for both sets to color number correctly with mlx_put_pixel |
| hooks.c | external_input | mouse and keyboard input handling check again |

