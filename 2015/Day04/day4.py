from hashlib import md5

key = "bgvyzdsv"

# Part 1
ans1 = 1
while True:
    if md5((key + str(ans1)).encode('utf-8')).hexdigest()[:5] == '00000':
        break
    ans1 = ans1 + 1
print("Part 1: " + str(ans1))

# Part 2
ans2 = ans1     # continue where we left off
while True:
    if md5((key + str(ans2)).encode('utf-8')).hexdigest()[:6] == '000000':
        break
    ans2 = ans2 + 1
print("Part 2: " + str(ans2))
