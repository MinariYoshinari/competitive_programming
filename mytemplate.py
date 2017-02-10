#ひとつだけの入力
X = int(raw_input())

#スペース区切りの1行入力
A,B,C = map(int, raw_input().split())

#N行入力
N = input()
A = [input() for i in range(N)]

#2分探索
min = 0
max = 10**9
mid = (min+max) // 2
Xn = mid**4

while Xn != X:
    if Xn > X:
        max = mid
    else:
        min = mid
    mid = (min+max) // 2
    Xn = mid**4

print mid
 
#カウンタを使う
import collections
hogehoge = ['list', 'directory', 'tuple']
c = collections.Counter(hogehoge)
print c['list']
print c.most_common #値を降順にソート
print c.most_common(1) #最大値

#全部の値を試してみる
import math
for x in range(n, int(math.sqrt(n)) - 1,-1):
    for y in range(1, int(math.sqrt(n)) + 1,1):
        if x*y > n:
            break
        else:
            f = min(f, x - y + n - x*y)
            
print f

#キュー(スタック)
from collections import deque

q = deque([])
q.append(i)
q.popleft()
    
print cost

#二分木
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
    def insert_left(self, data):
        self.left = Node(data)

    def insert_right(self, data):
        self.right = Node(data)
    
    def write_data(self, data):
        self.data = data

    def delete_left(self):
        self.left = None

    def delete_right(self):
        self.right = None

    def get_left(self):
        return self.left

    def get_right(self):
        return self.right
    
    def get_data(self):
        return self.data

#木？
from collections import deque
class Node:
    def __init__(self, data):
        self.data = data
        self.next = deque([])
    
    def insert(self, data):
        self.next.append(data)
        
    def insert(self, data, parent):
        q = self.next
        while len(q) > 0:
            if self.data == d:
                self.next.insert(d)
                return True
            child = self.next.popleft()
            child.insert(d, self)
        return False
        
    def delete(self, data, parent):
        q = self.next
        while len(q) > 0:
            if self.data == d:
                parent.self.next.remove(d)
                return True
            child = self.next.popleft()
            child.delete(d, self)
        return False
    
    def write_data(self, data):
        self.data = data

    def get_child(self):
        child = self.next.popleft()
        self.next.append(child)
        return child
    
    def get_data(self):
        return self.data
        
    def search(self, d):
        q = self.next
        while len(q) > 0:
            if self.data == d:
                return True
            child = self.next.popleft()
            child.search(d)
        return False
            
        
        
myinput = lambda:map(int,raw_input().split())
n,m,s = myinput()
root = Node(s)
t = root
for i in xrange(m):
    u,v = myinput()
    if t.search(u):
        t.insert(Node(v), u)
    elif t.search(v):
        t.insert(Node(u), v)

t = root
for i in xrange(1,n+1):
    if t.search(i):
        print i

#よく使う入力
myinput = lambda:map(int,raw_input().split())


#幅優先探索

#A*法

#DPまじ大事
#間違ってたDP
from collections import deque

n = int(input())
a = map(int, raw_input().split())
cost = [0]*n

cost[2] = abs(a[-2] - a[-1])
cost[3] = abs(a[-3] - a[-2]) + cost[2]

for i in range(4, n, 1):
    print cost[i-2] , abs(a[-i+2] - a[-i]), cost[i-1],  abs(a[-i+2] - a[-i+1])
    cost[i] = min(cost[i-2] + abs(a[-i+2] - a[-i]), cost[i-1] + abs(a[-i+2] - a[-i+1]))
    
    
print cost
