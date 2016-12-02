import json, sys, os

# Only check the immediate children of the dictionary for 'red'
def hasRed(value, doRecursion):
    if isinstance(value, unicode) and str(value) == 'red':
        return 1
    if isinstance(value, dict) and doRecursion:
        return sum(map(lambda x: hasRed(x, 0), value.values()))
    return 0

# Check for red only in part 2
def sumNumbers(value, part):
    if isinstance(value, int):
        return value
    if isinstance(value, list):
        return sum([sumNumbers(x, part) for x in value])
    if isinstance(value, dict) and (part == 1 or not hasRed(value, 1)):
        return sum(map(lambda x: sumNumbers(x, part), value.values()))
    return 0

# If a file is specified
if os.path.isfile(sys.argv[1]):
    data = json.load(open(sys.argv[1], 'r'))
    print "Part 1: " + str(sumNumbers(data, 1))  # part 1
    print "Part 2: " + str(sumNumbers(data, 2))  # part 2
# If a json string is specified
else:
    data = json.loads(sys.argv[1])
    print "Part 1: " + str(sumNumbers(data, 1))   # part 1
    print "Part 2: " + str(sumNumbers(data, 2))   # part 2
