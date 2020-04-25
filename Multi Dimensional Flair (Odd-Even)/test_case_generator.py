from sys import stdin, stdout
import math
import random

solution = []

with open("question/multi_dimensional_flair/input/input_0.txt", "w") as f:
    f.write("10\n")
    for i in range(10):
        n = random.randint(3, 101)
        m = random.randint(2, 11)
        print(n, m)

        if n & 1:
            solution.append("YES")
        else:
            solution.append("NO")

        f.write("{} {}\n".format(n, m))

        for j in range(n):
            for x in range(m):
                co = random.randint(-1000, 10001)
                print(co, end=" ")
                f.write("{} ".format(co))
            f.write("\n")
            print("")

with open("question/multi_dimensional_flair/output/output_0.txt", "w") as f:
    for i in solution:
        f.write("{}\n".format(i))
