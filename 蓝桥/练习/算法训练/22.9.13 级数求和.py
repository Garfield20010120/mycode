K = int(input())
n = 1
Sn = 1
while Sn <= K:
    n += 1
    Sn += 1/n
print(n)