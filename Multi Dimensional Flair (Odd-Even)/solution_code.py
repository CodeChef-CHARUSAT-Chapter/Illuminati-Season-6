from sys import stdin, stdout
import math
import random

t = stdin.readline()
t = int(t)

while t:
    n, m = map(int, stdin.readline().split())
    # print(n, m)
    for i in range(n):
        stdin.readline()

    if n & 1:
        stdout.write("YES")
    else:
        stdout.write("NO")

    stdout.write("\n")
    t -= 1
