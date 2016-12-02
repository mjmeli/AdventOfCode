## Day 9

#### Problem

##### Part 1
In order for Santa to deliver all of his presents in a single night, he must
find the shortest path between all the cities he must visit. His elves have
provided him with the distances between every pair of locations. Assume the
following:

* The distances are provided in `input.txt`.
* He can start and end at any two (different) locations he wants.
* He must visit each location exactly once.

What is the distance of the shortest route?

##### Part 2
To show off, Santa decides to take the route with the longest distance instead.
The same assumptions hold true.

What is the distance of the longest route?

#### Solution
This problem is similar to the classic Traveling Salesman Problem. It is slightly
different in that it does not require a cycle, but like the TSP, this problem
is also NP Complete. As such, there is no algorithm that gives the answer in
polynomial time.

Easy approaches would be to compute the permutations for each possible path and
compare them to find the shortest/longest distance. This would be O(n!).

There are approaches that can get the correct answer in better than O(n!). Of
course, there are also approaches that can get the correct answer in worse than
O(n!)!

To be special, I decided to make an extremely inefficient solution. Monte Carlo
simulations rely on repeated iterations using randomness to find a solution.
In my code, I randomly shuffle the list of cities that Santa can visit and
iteratively compute the shortest/longest distance. I found that I can always
converge to the correct answer after about only **100,000** iterations.

Hey, it works! Santa never asked for an efficient solution.

Java code: `Day9.java`
