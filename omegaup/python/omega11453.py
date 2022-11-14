a=input()
b=input().split(" ")
c=input().split(" ")
s = 0
for i in range(int(a)):
    s += int(b[i]) * int(c[i])
print(s)