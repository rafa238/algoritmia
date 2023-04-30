def discount(a, b):
    if (a + b ) >= 500:
        return a+b - 100
    return a + b

def discount2(a, b, c):
    if (a + b +c) >= 500:
        return a+b+c - 100
    return a + b + c

purchases = input().split()
purchases = [int(i) for i in purchases]
fst = discount(purchases[0], purchases[1]) + discount(0, purchases[2])
snd = discount(purchases[0], purchases[2]) + discount(0, purchases[1])
trd = discount(purchases[1], purchases[2]) + discount(0, purchases[0])
fth = discount2(purchases[0], purchases[1], purchases[2])
fith = discount(0, purchases[0]) + discount(0, purchases[1]) + discount(0, purchases[2])

ans = 10000000000
ans = min(ans, fst)
ans = min(ans, snd)
ans = min(ans, trd)
ans = min(ans, fth)
ans = min(ans, fith)
print(ans)