def triple(a):
    b = []
    a = [i*i for i in a]
    t1 = a[0]
    t2 = a[1]
    for i in a[2::]:
        if(t1+t2==i):
            b.append(1)
            t1=t2
            t2=i
            continue
        if(t1+i==t2):
            b.append(1)
            t1=t2
            t2=i
            continue
        if(t1==i+t2):
            b.append(1)
            t1=t2
            t2=i
            continue
        b.append(0)
    return b

a = [0,5,5,0,5,13,12]
print(triple(a))
    
    
    