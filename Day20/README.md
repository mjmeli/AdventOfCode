## Day 20

#### Problem
To keep the Elves busy, Santa has them deliver some presents by hand,
door-to-door. He sends them down a street with infinite houses numbered
sequentially: `1`, `2`, `3`, `4`, `5`, and so on.

Each Elf is assigned a number, too, and delivers presents to houses based on
that number:

* The first Elf (number 1) delivers presents to every house: 1, 2, 3, 4, 5, ...
* The second Elf (number 2) delivers presents to every second house: 2, 4, 6, 8, 10, ...
* Elf number 3 delivers presents to every third house: 3, 6, 9, 12, 15, ...

There are infinitely many Elves, numbered starting with 1.

##### Part 1
Each Elf delivers presents equal to **ten times** his or her number at each
house. What is the lowest house number of the house to get at least as many
presents as the number in your puzzle input?

Puzzle input: `36000000`

##### Part 2
The Elves decide they don't want to visit an infinite number of houses. Instead,
each Elf will stop after delivering presents to `50` houses. To make up for it,
they decide to deliver presents equal to **eleven times** their number at each
house.

With these changes, what is the new lowest house number of the house to get at
least as many presents as the number in your puzzle input?

Puzzle input: `36000000`

#### Solution
At first, this seems like a somewhat trivial problem. One could simply implement
an algorithm with the following pseudocode:

    N = puzzle input
    for house = 1 to N
        sum = 0
        for elf = 1 to i
            if (house % elf == 0)
                sum += elf * 10
        if (sum >= N)
            print house
            exit

This code works for small puzzle inputs, but my puzzle input was **36 million**.
Quick analysis would show that the time-complexity of this code is atrocious.
For reference, my answer to part 1 was house `831600`. This means that the code
would take **hundreds of trillions** of iterations to get the correct answer.
Needless to say, this code does not run fast at all, and so this solution is
not feasible.

Thus, I needed to reduce the number of iterations significantly. This code
checks each house in order and finds all the possible elves that could deliver
to that house. However, checking if each `elf` divides `house` evenly takes far
too many iterations. As such, the code can be simplified by exchanging
time-complexity for memory usage. The algorithm below summarizes my changes:

    N = puzzle input
    houses[N/10] = {0}
    for elf = 1 to N/10
        house = elf
        while house < N/10
            houses[house] += elf    
            house += elf
    print index of the first element in house where value * 10 >= N

There are a few important changes to note here. First, I create an array to
represent each house. This turns out to be a massive array, but can be reduced
in size by an order of magnitude by observing that the fact that each elf
delivers its number times 10 presents means that the solution will always be in
the first `1/10` of the puzzle input. Still a large array, but I have a lot of
RAM and limited time.

Next, the number of iterations is significantly reduced by switching the order
of the house and elf loops. Now, the elf is the outer loop, which is made
possible by switching to the array which sets bounds on the number of elves
and the number of houses. I can then remove the modulo division and simply visit
every `elf`th house. This has a massive impact on the number of iterations.

Finally, I can remove multiplication by multiplying by 10 at the end. This does
not have a giant performance impact but it speeds up the code by about 10-20%.

All in all, this solution is much better. The original pseudocode ran
for over 10 minutes and did not reach an answer. The second pseudocode runs for
less than 15 seconds.

In terms of iterations, the second pseudocode executes about 50 million
iterations. Compared to hundreds of trillions, that's almost **4 orders of
magnitude different!!** Yep, that is probably why it runs faster.

`day20.py` - Python script that implements solution
