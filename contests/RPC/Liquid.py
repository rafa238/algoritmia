import math
n = int(input())
vec = input().split()
vec = [float(i) for i in vec]
sum = 0
for i in vec:
    sum += pow(i, 3)

ans = sum**(1./3.)
print(ans)

