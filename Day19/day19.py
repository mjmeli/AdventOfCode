import re, sys
from numpy import vectorize

# Solution courtesy:
# https://www.reddit.com/r/adventofcode/comments/3xflz8/day_19_solutions/cy4crsv

# Parse input file for each possible replacement and the starting input
with open(sys.argv[1], 'r') as f:
    lines = [x.strip() for x in f.readlines()]
replacements = [re.findall(r'(\S+) => (\S+)', line)[0] for line in lines[:-2]]
start = lines[-1]

# Part 1 - Unique (set) molecules that can be made with single replacements
molecules = set()
for i, j in replacements:
    for k in range(len(start)):
        if start[k:k+len(i)] == i:
            new = start[:k] + j + start[k+len(i):]  # replacement
            molecules.add(new)
print("Part 1: There are " + str(len(molecules)) + " distinct molecules")

# Part 2 - Minimum number of replacements to construct the start module
def f(X):
    for j, i in replacements:
        for k in range(len(X)):
            if X[k:k+len(i)] == i:
                y = X[:k] + j + X[k+len(i):]
                yield y

replacements = sorted(replacements, key=lambda x: -len(x[1]))
visited = {start}
m = [start]
C = 0
while True:
    try:
        mm = []
        for i in m:
            for j in f(i):
                if j in visited:
                    continue
                mm.append(j)
                visited.add(j)
                break # the only change
        m = mm
        C += 1
        print(C, len(m), min(vectorize(len)(m)), flush=True)
    except IndexError:
        break
print("Part 1: It will take " + str(C-1) + " steps")
