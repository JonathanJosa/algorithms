while(True):
    a = input().split()
    if(a[0]=="0"):
        break
    a.append(len(a[1]))
    a.append(a[2]//int(a[0]))
    a[2] = ""
    for i in range(int(a[0])):
        a[2] += a[1][(i*a[3]):(i+1)*a[3]][::-1]
    print(a[2])
            
