a = list(map(int,input().split()))
if(abs(a[0]-a[2]) >= abs(a[1]-a[2])):
    if(abs(a[0]-a[2]) == abs(a[1]-a[2])):
        print("raton C")
    else:
        print("gato B")
else:
    print("gato A")
    