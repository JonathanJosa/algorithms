n = int(input())
c = input().split(" ")
b = int(input())
for i in range(n):
    if (int(c[i]) % b) == 0:
        print(c[i],end=" ")
    else:
        print("X",end=" ")
    