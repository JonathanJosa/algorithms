a = {}
for _ in range(int(input())):
    b = int(input())
    if(a.get(b)!=None):
        a[b]+=1;
        continue
    a[b]=1
b = int(input())
print(a.get(b) or 0)


