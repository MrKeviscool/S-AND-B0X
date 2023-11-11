# S-AND-B0X
a shitty sand sim

INSTALLS:
make sure sfml is installed in the default location

S&ND B0X README:

How to use custom map support:

to make a map, You will need to edit a file called "map.txt". the available items you can currently use is 0's for empty space, 5's for sand, 7's for floors and 8's for sand spawners. each number should be separated by a comma (,) and nothing else. To make a map, i would recommend making it in 2D first and then removing all returns to make it a 1D line. Remember what width and height your map was in 2D as this info will be needed when you load the sim. I also recommend keeping the width and height of you map in the file name until you copy its contents to map.txt as this will make reusing and sharing your map more successful. 


an example of proper naming for below map: "test map w9h6.txt" because the map has a width of 9 and a height of 6.

unusable 2D:

0,0,0,8,8,8,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,7,7,7,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
7,7,7,7,7,7,7,7,7,


same map but in 1D (usable):

0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7



Delay:

the delay is how long between each sim update (frame). You can set this as low as you want but it may become unstable at extremely low time per frame


Bugs:

If you find any bugs or have an idea, please mail me at: danielandkev@outlook.com
