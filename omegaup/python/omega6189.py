c = d = int(input())
a = [int(input()), int(input()), int(input())]
while(d>0):
    t = d//3
    a[0] += t
    a[1] += t
    a[2] += t
    d = d%3
    if(d>0):
        a[0]+=1
        d-=1
        if(d>0):
            a[1]+=1
            d-=1
    while(a[0]>=35):
        a[0]-=35
        d+=30
        c+=30
    while(a[1]>=100):
        a[1]-=100
        d+=60
        c+=60
    while(a[2]>=10):
        a[2]-=10
        d+=9
        c+=9
print(c)