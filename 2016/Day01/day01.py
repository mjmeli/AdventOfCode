import sys
import itertools
from sets import Set

with open('input.txt', 'r') as f:
    puzzle_input = f.read().strip().split(', ')

# Represents the movements in the (x, y) dimensions for each cardinal direction
movements = [
    (0, 1),  # North = 0
    (1, 0),  # East = 1
    (0, -1), # South = 2
    (-1, 0), # West = 3
]

""" Part 1 """
facing = 0   # Starting north
pos = (0, 0) # Starting position

# Perform movements
for instruction in puzzle_input:
    # Parse instruction (use direction to rotate index of movements by 90 deg)
    direction = (facing + (1 if instruction[0] == 'R' else -1)) % 4
    steps = int(instruction[1:])

    # Move based on the parsed input
    facing = direction     # adjust facing location
    pos = tuple(x + y*steps for x, y in itertools.izip(pos, movements[direction]))

# Shortest distance is the x-y dimensions
print "Shortest distance = %d" % (abs(pos[0]) + abs(pos[1]))

""" Part 2 """
facing = 0      # Starting north
pos = (0, 0)    # Starting position
visited = Set() # Where we've been

# Perform movements
for instruction in puzzle_input:
    # Parse instruction (use direction to rotate index of movements by 90 deg)
    direction = (facing + (1 if instruction[0] == 'R' else -1)) % 4
    steps = int(instruction[1:])

    # Move based on the parsed input
    facing = direction     # adjust facing location
    for i in range(steps): # move one step at a time, checking the position
        pos = tuple(x + y*1 for x, y in itertools.izip(pos, movements[direction]))
        if pos in visited:
            print "First visited twice distance = %d" % (abs(pos[0]) + abs(pos[1]))
            sys.exit()
        else:
            visited.add(pos)
