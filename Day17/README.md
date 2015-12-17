## Day 17

#### Problem
The elves bought too much eggnog ('150' liters). To fit it all into your
refrigerator, you'll need to move it into smaller containers. You have a list
of inventory of the capacities of available containers.

* The available container sizes (in liters) are in `input.txt`.
* You need to be able to store `150` liters.
* All containers that are used are filled entirely.

##### Part 1
How many different combinations of containers can exactly fit all of the eggnog?

##### Part 2
Now you want to use the fewest containers possible. How many different ways can
you fill the fewest number of containers and still hold all of the eggnog?

#### Solution
To develop this solution, I first made an observation that given `n` containers,
there are `2^n` possible combinations. After seeing this `2^n` number, I
recalled that an `n-bit` binary number would be able to represent each of these
`2^n` combinations. Thus, I could consider every number from `1` to `2^n` as
a combination, where each bit in the binary representation would represent a
single container being used or not used. After considering each number in this
range, every possible combination has been considered.

My algorithm is developed by that reasoning. First, I determine the number of
containers and then iterate on `i` from `0` to `1 << numContainers` to create my
search space. Then, for every `container[j]` in `container` in the range `j = 0
to numContainers`, I check whether that bit is set in the current number `i` I
am considering using basic bit-masking (`i & (1 << j)`). If so, then I can add
the capacity of `container[j]` to the current running capacity. After checking
every container, if the amount is exactly `150`, I can consider that a possibility!

This algorithm, while `O(2^n)`, is fast to execute thanks to making use of
bit-shifting and bit-wise operations, which are very fast.

`day17.c` - C code that implements solution
