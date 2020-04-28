from sys import stdin, stdout
import math
import random

t = stdin.readline()
t = int(t)

while t:
    n, m = map(int, stdin.readline().split())
    # print(n, m)

    x, y = map(int, stdin.readline().split())
    # print(x, y)

    top_left_x = math.inf
    top_left_y = -math.inf
    bottom_right_x = -math.inf
    bottom_right_y = math.inf

    for i in range(m):
        for j in range(n):
            print("Q {} {}".format(i, j), flush=True)
            rgb = stdin.readline()[:-1]
            if rgb == "-1":
                exit(0)
            # print("RGB:", rgb)
            # rgb = "2"
            if rgb == "255 255 255":
                top_left_x = min(top_left_x, i)
                top_left_y = max(top_left_y, j)
                bottom_right_x = max(bottom_right_x, i)
                bottom_right_y = min(bottom_right_y, j)

    length = abs(top_left_x - bottom_right_x) + 1
    breadth = abs(top_left_y - bottom_right_y) + 1

    # print(length, breadth)

    shape_name = "rectangle"

    if length == breadth:
        shape_name = "square"

    print("A {} {} {} {} {}".format(top_left_x, top_left_y, bottom_right_x, bottom_right_y, shape_name), flush=True)

    # stdout.write("\n")
    t -= 1
