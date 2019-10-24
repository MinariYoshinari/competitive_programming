import random
random.seed(0)

print(100)
print('+'*997+'-'*3+' 3')
for _ in range(100-1):
    l = 1000
    s = ""
    for i in range(l):
        s += '+' if random.randint(0, 1) else '-'
    print(s + " {}".format(random.randint(1, 1000)))
