a = int(input())
for i in range(a):
    if(i==((a-1)/2)):
        print(" "*(i-1),end="@")
    else:
        print(" "*(i-1),"@"," "*(a-i),"@",end="")
    print()
    
