def XOR (a,b):
    if(a==b):
        return "0"
    return "1"

def COMP(a,b):
    a = str(bin(a)[2:]) 
    b = str(bin(b)[2:])
    la = len(a)
    lb = len(b)
    if(la>lb):
        m = la
    else:
        m = lb
    a = "0"*(lb-la) + a
    b = "0"*(la-lb) + b
    s=""
    for i in range(m):
        s = XOR(a[m-i-1],b[m-i-1]) + s
    return int(s,2)
        
def XORNACCI(a, b, c):
    if(c<=0):
        return a
    if(c==1):
        return b
    else:
        return COMP(XORNACCI(a,b,c-1), XORNACCI(a,b,c-2))

for i in range(int(input())):
    a = input().split()
    a = [int(i) for i in a]
    print(XORNACCI(a[0],a[1],a[2]))
    
    