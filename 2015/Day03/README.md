## Day 3

#### Problem
Santa is delivering presents to a set of houses. He is receiving directions from
an elf at the North Pole, but the elf has had a little too much eggnog to drink
and gives him poor directions. In fact, Santa ends up visiting some houses more
than once! In part 1, Santa is working alone. However, in part 2 Santa decides
to create a Robo-Santa. The two Santas start at the same location and alternate
directions, moving independently. Again, they may visit the same houses. Assume
the following:

* The directions given to the Santa's by the drunk elf are in `input.txt`.
* Moves are always exactly one house to the north (`^`), south (`v`), east
(`>`), or west (`<`).
* After each move, a present is delivered.
* The Santa's both deliver a present to the starting house.
* The houses are laid out on an infinite two-dimensional grid.

Based on these assumptions, determine the following:

1. When Santa is working alone (Part 1), how many houses receive **at least
one** present?
2. When Santa is working with Robo-Santa (Part 2), how many houses receive **at
least one** present?

#### Solution
The solution I chose is simple - a hash table! The coordinates of each Santa are
tracked throughout reading the directions. At each stop, the location is checked
with the hash table. If it does not exist, it is added. At the end, the number
of houses in the hash table are counted, and this is the number of houses who
received at least one gift.

`day3.c` - C code file that implemented solution

`uthash.h` - C library for a hash table implementation written by Troy D.
Hanson (https://troydhanson.github.io/uthash/)
