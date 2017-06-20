n = int(input())
for i in range(n):
    t = input()
    ans = []
    print("Case #{}: ".format(i+1))
    for j in range(1, len(t)):
        if t[j] < t[j-1]:
            ans.append(int(t[j-1]) - 1)
            for k in range(j, len(t)+1):
                ans.append(9)
            break
        else:
            ans.append(int(t[j-1]))
            if j == len(t)-1:
                ans.append(int(t[j]))
    print("".join(ans))       
