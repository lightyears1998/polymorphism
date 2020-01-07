# 121919171932

from math import *

x = 1463030063184
print(bin(x))

def func(x):
    return x * ((x & -x) + ((x - (x & -x)) & -(x - (x & -x))))

x = 0
d = []
while x <= 64:
    y = x * ((x & -x) + ((x - (x & -x)) & -(x - (x & -x))))
    if '1010000' in bin(y):
        d.append(x)
    x += 1

print(d)

def cnt(n):
    cur = 0
    remain = 2
    rslt = []
    while n and remain:
        if n&1:
            remain -= 1
            rslt.append(cur)
        cur += 1
        n >>= 1
    return rslt

for dd in d:
    bits = cnt(dd)
    if len(bits)<2: continue
    
    add = 0
    for bit in bits:
        add += 2 ** bit
    x = 1463030063184 // add
    if (x * ((x & -x) + ((x - (x & -x)) & -(x - (x & -x)))) == 1463030063184):
        print(x)