from collections import Counter

def solve():
    h,w = map(int, input().split())
    cnt = Counter()
    for _ in range(h):
        cnt.update(list(input()))

    if h == 1 or w == 1:
        print("Yes")
        return

    for _,n in cnt.most_common():
        if h % 2:
            if n % h == 0:
                continue
            else:
                
        else:
            if n % 2 == 1:
                print("No")
                return


solve()