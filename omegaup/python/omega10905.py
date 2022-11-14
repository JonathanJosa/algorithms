a = input().split()
m = int(a[1])
for _ in range(int(a[0])):
    if(m>0):
        n = (int(input()))
        if(n<=m):
            print("pasa")
            m -= n
        else:
            print("espera")
    else:
        print("espera")
