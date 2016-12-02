## Day 1

#### Problem
You're airdropped near Easter Bunny Headquarters in a city somewhere. "Near", unfortunately, is as close as you can get - the instructions on the Easter Bunny Recruiting Document the Elves intercepted start here, and nobody had time to work them out further.

The Document indicates that you should start at the given coordinates (where you just landed) and face North. Then, follow the provided sequence: either turn left (`L`) or right (`R`) 90 degrees, then walk forward the given number of blocks, ending at a new intersection.

##### Part 1
There's no time to follow such ridiculous instructions on foot, though, so you take a moment and work out the destination. Given that you can only walk on the street grid of the city, how far is the shortest path to the destination?

Puzzle input: `input.txt`

##### Part 2
Then, you notice the instructions continue on the back of the Recruiting Document. Easter Bunny HQ is actually at the first location you visit twice. How many blocks away is the first location you visit twice?

Puzzle input: `input.txt`

#### Solution
To solve this problem, I map the street grid as a coordinate system. We start at position `(0, 0)` facing North. I then analyze each instruction in turn. Depending on the current heading and the direction I have to turn, I perform a clockwise or counterclockwise rotation on the cardinal directions and map that to a movement modifier:

    movements = [
        (0, 1),  # North = 0
        (1, 0),  # East = 1
        (0, -1), # South = 2
        (-1, 0), # West = 3
    ]

This means that if the heading is North, movement will be 0 in the x-direction and 1 in the y-direction, for example. This modifier can then be multiplied by the scalar of the number of steps and added to the current position and by the end of the instruction list, you are at your destination.

The shortest path to the destination is simply the absolute value of the x and y coordinates summed.
