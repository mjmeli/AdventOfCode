import re, sys

class Reindeer:
    def __init__(self, speed, flying, rest):
        self.speed = int(speed)
        self.flying = int(flying)
        self.rest = int(rest)
        self.distance = 0
        self.score = 0
    def addScore(self):
        self.score = self.score + 1
    def step(self, time):
        if time % (self.flying + self.rest) < self.flying:
            self.distance = self.distance + self.speed

text = open(sys.argv[1], 'r').read()
pattern = r'(\w+) can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds.'
reindeer = [Reindeer(speed, flying, rest) for name, speed, flying, rest in re.findall(pattern, text)]

for i in range(0, int(sys.argv[2])):
    # Part 1
    [r.step(i) for r in reindeer]
    # Part 2
    [r.addScore() for r in reindeer if r.distance == max([r.distance for r in reindeer])]

print("Part 1: " + str(max([r.distance for r in reindeer])) + " km")    # part 1
print("Part 2: " + str(max([r.score for r in reindeer])) + " points")   # part 2
