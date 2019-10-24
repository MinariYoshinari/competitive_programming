k = int(raw_input())

ans = [[] for kk in range(k)]

for kk in range(k):
    n = int(raw_input())
    users = raw_input().split(' ')

    m = int(raw_input())
    messages = [["", ""] for mm in range(m)]
    for mm in range(m):
        messages[mm] = raw_input().split(":")

    dp = [[False for nn in range(n)] for mm in range(m)]

    for mm in range(m):
        if messages[mm][0] == "?":
            for nn in range(n):
                if users[nn] not in messages[mm][1]:
                    dp[mm][nn] = True
                if mm > 0 and dp[mm-1][nn]:
                    dp[mm][nn] = False
                    continue
                if mm < m-1 and (users[nn] == messages[mm+1][0] or dp[mm+1][nn]):
                    dp[mm][nn] = False
        else:
            for nn in range(n):
                if users[nn] == messages[mm][0]:
                    dp[mm][nn] = True

    flag = True
    for mm in range(m):
        if messages[mm][0] == "?":
            for nn in range(n):
                if dp[mm][nn]:
                    messages[mm][0] = users[nn]
                    break
            else:
                flag = False

    if flag:
        for mm in range(m):
            ans[kk].append(":".join(messages[mm]))
    else:
        ans[kk].append("Impossible")

for kk in range(k):
    m = len(ans[kk])
    for mm in range(m):
        print ans[kk][mm]
