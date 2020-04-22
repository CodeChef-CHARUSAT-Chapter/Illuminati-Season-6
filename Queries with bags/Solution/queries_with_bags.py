#ILLUMINATI SEASON 6
'''
Name : Jaymeet Mehta
codechef id :mj_13
Problem : Queries with bags
'''
from sys import stdin,stdout

def find_set(v):
    global parent
    if parent[v]!=v:
        parent[v]= find_set(parent[v])
    return parent[v]
def union_set(a,b):
    global size,parent
    if size[a]<size[b]:
        a,b=b,a
    parent[b]=a
    size[a]+=size[b]
N,Q = map(int,stdin.readline().split())
assert(1<=N and N<=100000)
assert(1<=Q and Q<=100000)
parent=[i for i in range(N)]
size=[1 for i in range(N)]
bags=N
for _ in range(Q):
    query= [int(x) for x in stdin.readline().split()]
    if query[0]==1:
        assert(query[1]!=query[2])
        assert(1<=query[1] and query[1]<=N)
        assert(1<=query[2] and query[2]<=N)
        a=find_set(query[1]-1)
        b=find_set(query[2]-1)
        if a!=b:
            bags-=1
            union_set(a,b)
        continue
    if query[0]==2:
        assert(query[1]!=query[2])
        assert(1<=query[1] and query[1]<=N)
        assert(1<=query[2] and query[2]<=N)
        a=find_set(query[1]-1)
        b=find_set(query[2]-1)
        if a!=b:
            print("NO")
        else:
            print("YES")
        continue
    print(bags)