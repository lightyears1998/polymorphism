# 20010911

from math import *

d = range(20000000-911, 20000000)
x = 0
while x <= 1248679:
    if x in d:
        print(x)
        exit()
    x += 1

d = range(911)
x = 1248679
y = []
while x <= 20021231:
    if 20000000 - (x ^ (x % 1248679)) in d:
        y.append(x)
    x += 1

def fpow(a, b, mod):
    ans = 1
    a %= mod
    while b > 0:
        if b&1:
            ans *= a
            ans %= mod
        a *= a
        a %= mod
        b >>= 1
    return ans

for x in y:
    if ((fpow(x, x, 911)) + (x ^ (x % 1248679)) == 20000000):
        print(x)
        break
