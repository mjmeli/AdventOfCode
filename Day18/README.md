## Day 18

#### Problem
You have a grid of ten thousand lights in a `100x100` grid. Santa mails you
instructions to configure the lights, as in Day 6. This time, a `#` means "on"
and a `.` means "off".

He then wants you to animate your grid in steps, where each step decides the next
configuration based on the current one. Each light's next state (either on or
off) depends on its current state and the current states of the eight lights
adjacent to it (including diagonals).

Lights on the edge of the grid may have fewer than 8 neighbors; missing ones
should simply be considered as off.

The following rules should be applied to determine the next state:

* A light which is **on** stays on when `2` or `3` neighbors are on, and turns
off otherwise.
* A light which is **off** stays on when exactly `3` neighbors are on, and turns
off otherwise.

**NOTE**: All of the lights update simultaneously; they all consider the same
current state before moving to the next.

##### Part 1
In your grid of 100x100 lights, given your initial configuration, how many
lights are on after 100 steps?

##### Part 2
Your grid starts to malfunction so that the 4 lights in the corners of the grid
are stuck on and can't be turned off. These lights still count as being "on"
for the animation.

In your grid of 100x100 lights, given your initial configuration, but with the
four corners always in the on state, how many lights are on after 100 steps?

#### Solution
This was a fun problem, but not necessarily a riveting solution. I start with a
2D array to represent my grid. To make my code generic to any input file, I
allocate the array at run-time using `malloc`, which is particularly fun for 2D
arrays. I then parse the input into the initial grid.

For each animation step, I create a copy of the grid and use this to consider
the current state. Iterating between each light, I check the copy of the grid
for how many lights surrounding it are on and then apply the rules. I turn on
or off the light in the original grid.

For part 2, I simply made sure that the corner lights are active after this
process and everything works out well.

There isn't much interesting about my code except for doing some cool code things
like malloc and free and the ternary operator.

One major optimization I made was removing bounds checking on the array by
adding a ring of "off" lights to the grid. Usually when checking the neighbors
of a light, you have to make sure to add bounds checking for the neighbors of
lights that are on the edges of the grid. These comparisons can be
computationally expensive over 100,000 lights, especially when you consider most
lights are not on the edge and do not need this check. By adding a ring of "off"
lights around, I can eliminate these checks in all cases.

`day18.c` - C code that implements solution
