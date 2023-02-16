from math import ceil
steps = int(input())

if 15*steps <= 3000:
    print(15)
else:
    ans = 3000/steps
    print(ceil(ans))
