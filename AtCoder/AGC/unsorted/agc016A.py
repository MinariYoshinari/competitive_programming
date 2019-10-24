from collections import Counter
s = input()
count = Counter(s).most_common()
ans = 100
for c,n in count:
    ss = s
    cnt = 0
    while any(ssi != ss[0] for ssi in ss):
        ss_new = ""
        for i in range(len(ss)-1):
            if ss[i] != c and ss[i+1] == c:
                ss_new += c
            else:
                ss_new += ss[i]
        ss = ss_new
        cnt += 1
    if cnt < ans:
        ans = cnt

print(ans)