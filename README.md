# 42_graphics_FdF
FdF (Fil de Fer) is a graphical project in C, a "wire of a field" in 3D

## Intro

Bascicallly, I am given a set of positions represented by 0 (x, y) and a 'z' altitude given by values inferior or superior to 0. With these, I will draw lines accordingly and represent elevation given by 'z' to create a 3D effect.

My FdF project handles:
* 2 types projections (Isometric and Parallel) - default being Isometric (switch available)
* Centered object position and display center option
* Zoom in/out controls
* Move camera controls
* Reset and quit controls
* 'z' altitude inc/dec controls

*See more details about controls and bindings in Steps*

Here is an example of an FdF representation computed from /test_maps/42.fdf.
This is how my program represents it:

![screen shot 2019-02-27 at 5 39 05 pm](https://user-images.githubusercontent.com/45239771/53507366-0859b100-3ab8-11e9-8f19-7791b1e78d07.png)

*To try it out, you will need to do a "make" in your terminal at folder root level.*

## Steps

1. Do "make" at folder root level to compile program
2. Execute program using "./fdf" and add a selected map from "test_maps" folder *(like "./fdf test_maps/42.fdf" for example)*
3. You can interact with the object using these bindings:

![screen shot 2019-02-27 at 6 04 26 pm](https://user-images.githubusercontent.com/45239771/53508526-37712200-3aba-11e9-820e-814db0165741.png)

## Maps

You can try out using the same steps other maps, just by changing the map path (contained in the same "test_maps" folder).

For example, here is the map of France *(IGN_France_250_ASC_L93_OCEAN0_M.fdf)*:

![screen shot 2019-02-27 at 5 37 15 pm](https://user-images.githubusercontent.com/45239771/53508696-8cad3380-3aba-11e9-8b04-4e3cd18497ef.png)

## Make options

Makefile allows you to do several "make" actions including:
* make -> compile and create binary
* make clean -> remove .o files
* make fclean -> remove .o files and binary
* make re -> make fclean + make
