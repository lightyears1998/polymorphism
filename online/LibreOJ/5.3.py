# 1000000007

from math import *

d = []
d += range(int(1e9)-10, int(1e9)+11) 
d += range(int(3e9)-10, int(3e9)+11)
for x in d:
    if abs(sin(pi * (x + 25) / 32)) <= 1e-8:
        print(x)
        break
