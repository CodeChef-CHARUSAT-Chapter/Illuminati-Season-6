from sys import stdin, stdout
import math
import random

t = stdin.readline()
t = int(t)

while t:
    n, m = map(int, stdin.readline().split())
    # print(n, m)

    center_x, center_y = map(int, stdin.readline().split())
    # print(x, y)

    top_left_x = 0
    top_left_y = 0
    bottom_right_x = 0
    bottom_right_y = 0

    # Binary search for length (0,m)
    left_index = 0
    right_index = center_x  # x coordinate of the center
    while left_index <= right_index:
        mid = left_index + (right_index - left_index) // 2
        print("Q {} {}".format(mid, center_y), flush=True)
        rgb = stdin.readline()[:-1]
        if rgb == "-1":
            exit(0)
        if rgb == "255 255 255":
            right_index = mid - 1
            top_left_x = mid
        else:
            left_index = mid + 1

    bottom_index = 0
    top_index = center_y
    while bottom_index <= top_index:
        mid = bottom_index + (top_index - bottom_index) // 2
        print("Q {} {}".format(center_x, mid), flush=True)
        rgb = stdin.readline()[:-1]
        if rgb == "-1":
            exit(0)
        if rgb == "255 255 255":
            top_index = mid - 1
            bottom_right_y = mid
        else:
            bottom_index = mid + 1

    top_left_y = center_y + (center_y - bottom_right_y)
    bottom_right_x = center_x + (center_x - top_left_x)

    length = abs(top_left_x - bottom_right_x) + 1
    breadth = abs(top_left_y - bottom_right_y) + 1

    # print(length, breadth)

    shape_name = "rectangle"

    if length == breadth:
        shape_name = "square"

    print("A {} {} {} {} {}".format(top_left_x, top_left_y, bottom_right_x, bottom_right_y, shape_name), flush=True)

    # stdout.write("\n")
    t -= 1
