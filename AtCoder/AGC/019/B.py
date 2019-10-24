s = input()
st = set()
st.add(s)
n = len(s)
cnt = 0
for i in range(n):
    for j in range(i+1, n):
        sub = s[i:j+1]
        if sub != sub[::-1]:
            if i == 1 and j == 2:
                for item in st:
                    print(item)
            if (s[:i] + sub[::-1] + s[j+1:]) in st:
                print(i, j, sub)
                print(s[:i] + sub[::-1] + s[j+1:])
            cnt += 1
        
        st.add(s[:i] + sub[::-1] + s[j+1:])
print(len(st))
print(cnt)