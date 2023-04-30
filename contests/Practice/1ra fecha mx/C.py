def count_triangles(N, K):
    mod = 10**9 + 7  # or any other prime number
    even = (N+1) % 2 == 0  # check which of N+1 and N+2 is even
    if not even:
        n_even = (N+2) // 2  # integer division
        n_odd = N+1
    else:
        n_even = (N+1) // 2
        n_odd = N+2
    k_odd = (K+1)
    total = (((n_even * n_odd) % mod) * k_odd)% mod
    return total

tc = int(input())
for i in range(tc):
    inp = input().split()
    N, K = int(inp[0]), int(inp[1])
    total = count_triangles(N, K)
    print(total)