a=input().split()
b = a[0:3]
c = a[3:6]
c.sort()
b.sort()
r = 1
for i in range(3):
    if(int(c[i])<int(b[i])):
        r = 0
        break
print(r)
        
