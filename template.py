# map(int, input().split())
# list(map(int, input().split()))
# for _ in range(int(input())):

def matmult(a,b):
    n, m, l = len(a), len(a[0]), len(b[0])
    c = [[0]*l for i in range(n)]
    for i in range(n):
        for j in range(l):
            c[i][j] = sum([a[i][k]*b[k][j] for k in range(m)])
    return c

def matpow(a,b):
    n = len(a)
    c = [[0]*n for i in range(n)]
    for i in range(n):
        c[i][i]=1
    while (b>0):
        if b%2:
            c = matmult(c,a)
        b = b//2
        a = matmult(a,a)
    return c
