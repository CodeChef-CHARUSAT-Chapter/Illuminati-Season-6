#ILLUMINATI SEASON 6
'''
Name : Jaymeet Mehta
codechef id :mj_13
Problem : Monty Hall Paradox 2.0
'''

from sys import stdin,stdout
test=int(stdin.readline())
for _ in range(test):
    N=int(stdin.readline())
    assert(2<N and N<=1000000000)
    print(1,N,N-1,N)