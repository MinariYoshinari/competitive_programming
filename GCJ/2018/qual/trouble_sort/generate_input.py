import random

print(100)
for _ in range(100):
    n = random.randrange(3, 100001)
    print(n)
    print(" ".join([str(random.randrange(1, 10**9+1)) for i in range(n)]))