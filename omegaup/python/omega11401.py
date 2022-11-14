c = int(input()) - 1
a = list(map(int, input().split()))
m = 0
for _ in range(c):
        b = list(map(int, input().split()))
        v = (b[1]-a[1])//(b[0] - a[0])
        a = b
        if(v > m):
            m = v
print(m)
        
