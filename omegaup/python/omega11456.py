n = int(input())
f = 1
a = input().split(" ")
b = input().split(" ")
for i in range(n):
    if int(a[i]) <= int(b[i]):
        f = 0
        break
print(f)