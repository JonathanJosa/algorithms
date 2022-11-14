m1 = ["."]*10
m = []
for _ in range(10):
    m.append(m1.copy())
r = int(input())
f = input().split(" ")
for i in range(r):
    n = int(f[i])
    for j in range(11):
        if(j==10):
            m[j-1][n] = "#"
            m[j-1][n+1] = "#"
            m[j-2][n] = "#"
            m[j-2][n+1] = "#"
            break
        if(m[j][n]!="." or m[j][n+1]!="."):
            m[j-1][n] = "#"
            m[j-1][n+1] = "#"
            m[j-2][n] = "#"
            m[j-2][n+1] = "#"
            break
for i in range(10):
    for j in range(10):
        print(m[i][j],end=" ")
    print()
    