from sys import stdin, stdout
import math
import random

random.seed(2)

for test_case_no in range(5):

    solution = []

    t = 0
    max_range = 0

    if test_case_no == 0:
        t = 200
        max_range = 10
    elif test_case_no == 1:
        t = 100
        max_range = 100
    elif test_case_no == 2:
        t = 10
        max_range = 500
    elif test_case_no == 3:
        t = 100
        max_range = 10 ** 8
    elif test_case_no == 4:
        t = 100
        max_range = 10 ** 18

    with open("question/Vivid Placement (Binary Search -  Pixel grid)/input/input_subtask_{}.txt".format(test_case_no),
              "w") as f:
        f.write("{}\n".format(t))

        for _ in range(t):
            # dimensions of the image - N x M
            n = random.randint(1, max_range)
            m = random.randint(1, max_range)

            f.write("{} {}\n".format(n, m))

            print("Dimensions:", n, m)

            # Centers
            x = random.randint(0, m - 1)
            y = random.randint(0, n - 1)

            f.write("{} {}\n".format(x, y))
            print("Center:", x, y)

            # Now select any valid dimension for the rectangle or square and output the coordinates of its
            # top left corner and bottom right corner

            length = random.randint(1, m)
            breadth = random.randint(1, n)

            if random.randint(0, 2) == 1:
                # it should be a square
                print("Square")
                length = breadth = random.randint(1, min(m, n))

            if length % 2 == 0:
                length += 1
            if breadth % 2 == 0:
                breadth += 1

            print("length =", length, ", breadth =", breadth)

            # Check if the dimensions we want with the given sample is even possible or not
            length = min(length // 2, min(x, m - x - 1))
            breadth = min(breadth // 2, min(y, n - y - 1))

            print("l_portion =", length, ", b_portion =", breadth)

            shape_name = "rectangle"
            if length == breadth:
                shape_name = "square"

            # here the length and breadth denote the length of a portion on either side
            top_left_corner_x = x - length
            bottom_right_corner_x = x + length

            top_left_corner_y = y + breadth
            bottom_right_corner_y = y - breadth

            print("length_final =", length * 2 + 1, ", breadth_final =", breadth * 2 + 1)

            solution.append(
                (top_left_corner_x, top_left_corner_y, bottom_right_corner_x, bottom_right_corner_y, shape_name))
            print(solution[-1])

        with open("question/Vivid Placement (Binary Search -  Pixel grid)/output/output_subtask_{}.txt".format(
                test_case_no), "w") as f:
            for i in solution:
                f.write("{} {} {} {} {}\n".format(i[0], i[1], i[2], i[3], i[4]))
