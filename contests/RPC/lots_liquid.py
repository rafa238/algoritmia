import math
n = int(input())
recipies = input().split()
recipies = [float(i) for i in recipies]
sum = 0
for i in recipies:
    sum += (i*i*i)

ans = sum**(1./3.)
print(ans)

