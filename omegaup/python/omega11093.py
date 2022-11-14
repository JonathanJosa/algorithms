a = int(input())
n = 0
f = [0]*a
m = []
for _ in range(a):
    m.append(f.copy())


for i in range(a):
    m[i][i] = i+1
    if(m[i][a-i-1] != 0):
        n = 1
    else:
        m[i][a-i-1] = a+i+1-n

print("Matriz X:")
for i in range(a):
    for j in range(a):
        print(str(m[i][j]),end=" ")
    print()

print("La matriz X invertida es:")
for i in range(a):
    for j in range(a):
        print(str(m[i][a-1-j]),end=" ")
    print()
