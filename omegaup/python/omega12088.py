b = []
for _ in range(int(input())):
    a = input().split()
    b.append((int(a[0])**int(a[1]),a[0]+" "+a[1]))
b.sort()
for i,j in b:
    print(j)
    
    
        
        
        