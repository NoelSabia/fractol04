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
| fractol.c | main.c | checks args, initialize, fractolpic,... |
| fractol.h | fractol.h | two structs, #defines, libs, functs |
| algorithm.c | mandelbrot.c | for each y number the hole x row plus color | 
| algorithm2.c | julia.c | for each y number the hole x row plus color |
| utils.c | coloring.c | important for both sets to color number correctly with mlx_put_pixel |
| hooks.c | external_input | mouse and keyboard input handling check again |

## Main
- The code defines a program for visualizing fractals.
- The main function initializes a t_fract structure, mlx_t and mlx_image_t objects.
- The print_usage function prints usage information if the command-line arguments are incorrect.
- The convert_argv function converts command-line arguments to floating-point numbers for Julia set parameters.
- The routines function determines the fractal set based on command-line arguments and calls relevant functions.
- The initialize function sets default values for the fractal parameters in the t_fract structure.
- The program uses the mlx library for graphical operations, including window creation and event handling.
- The main function checks command-line arguments, initializes fractal parameters, and sets up the graphical environment.
- Various hooks are registered for handling keyboard, mouse, and window events.
- The program enters the mlx event loop to continuously update and display the fractal.

To does:
- mouse wheel zoom 
- esc-button (not sure but maybe just one function)
- resize

to do:
- eine eval
- code umschreiben
- zoom fixxen (done)