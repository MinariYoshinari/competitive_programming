h,w = map(int, input().split())
for i in range(h):
    s = input().split()
    print(s)
    for j in range(w):
        if s[j] == "snuke":
            print("{}{}".format(chr(ord('A')+j), i+1))