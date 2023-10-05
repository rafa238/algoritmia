arr = []

def solve():
    n = len(arr)
    minProduct = arr[0]
    maxProduct = arr[0]
    ans = arr[0]
    
    for i in range(1, n):
        aux = max(arr[i], maxProduct * arr[i], minProduct * arr[i])
        minProduct = min(arr[i], maxProduct * arr[i], minProduct * arr[i])
        maxProduct = aux
        ans = max(maxProduct, ans)
    
    print(ans)

try:
    while True:
        arr = input().split()

        arr = [int(elem) for elem in arr]
        arr.pop()
        solve()
except EOFError:
    pass