import sys
import random
import time


def lcs2(W, wt, val, n):
    # write your code here
    L = [[0 for x in range(W + 1)] for x in range(n + 1)]
    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                L[i][w] = 0
            elif wt[i-1] <= w:
                L[i][w] = max(val[i-1] + L[i-1][w-wt[i-1]], L[i-1][w])
            else:
                L[i][w] = L[i-1][w]
    return L[n][W]


if __name__ == '__main__':

    val = list(map(int, input().split()))
    n = len(val)
    wt = list(map(int, input().split()))
    m = len(wt)
    W = int(input())
    print(lcs2(W, wt, val, n))
    # input = sys.stdin.read()
    # data = list(map(int, input.split()))

    # n = data[0]
    # data = data[1:]
    # a = data[:n]

    # data = data[n:]
    # m = data[0]
    # data = data[1:]
    # b = data[:m]


#    an = random.randint(0, 100)
#    a =[]
#    for i in range(an):
#        a.append(random.randint(0, 100))
#    bn = random.randint(30, 100)
#    b =[]
#    for i in range(bn):
#        b.append(random.randint(0, 100))
#    start = time.time()
#    print(a)
#    print(b)
#    result = lcs2(a, b)
#    end = time.time()
#    print(result)
#    print('the running time is %0.5f s' % (end-start))
