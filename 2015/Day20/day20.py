import sys, time
from itertools import count

goalRaw = int(sys.argv[1])

# Part 1
start = time.time()
goal1 = int(goalRaw/10)+1
houses = [0]*goal1
iterations = 0
for elf in range(1,goal1):
    for house in range(elf, goal1, elf):
        houses[house] = houses[house] + elf
        iterations = iterations + 1
houseNum1 = next(i for i,v in enumerate(houses) if v*10 >= goalRaw)
end = time.time()
print("Part 1: House #" + str(houseNum1))
print("\t" + "{0:.4f}".format(end - start) + "s")
print("\t" + str(iterations) + " iterations")

# Part 2
start = time.time()
goal2 = int(goalRaw/11)+1
houses = [0]*goal2
for elf in range(1,goal2):
    houseCount = 0
    for house in range(elf, goal2, elf):
        houses[house] = houses[house] + elf
        houseCount = houseCount + 1
        if (houseCount == 50):
            break
houseNum2 = next(i for i,v in enumerate(houses) if v*11 >= goalRaw)
end = time.time()
print("Part 2: House #" + str(houseNum2))
print("\t" + "{0:.4f}".format(end - start) + "s")
