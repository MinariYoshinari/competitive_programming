t = int(input())
for tt in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    done = False
    while not done:
        done = True
        for i in range(n-2):
            if a[i] > a[i+2]:
                a[i], a[i+2] = a[i+2], a[i]
                done = False
    
    b = sorted(a)
    for i in range(n):
        if a[i] != b[i]:
            print("Case #{}: {}".format(tt+1, i))
            break
    else:
        print("Case #{}: OK".format(tt+1))