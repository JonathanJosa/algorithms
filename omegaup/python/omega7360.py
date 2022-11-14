a = []
b = 0
p = int(input())
r = int(input())
for _ in range(p):
    c = int(input())
    a.append(c)
    b+=c
for _ in range(r):
    c = input().split()
    if(c[0]=="1"):
        a[int(c[1])-1]=int(c[2])
        continue
    print(sum(a[int(c[1])-1:int(c[2])])//p)
    
    
    
    