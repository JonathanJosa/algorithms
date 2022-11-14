x=["Sur","Central","Norte"]
a = input()
if(a.isnumeric()):
    for i in range(int(a)):
        b = input().capitalize()
        c = input()
        if((ord(b)>=65 and ord(b)<=90)):
            if(c.isnumeric()):
                if(int(c)>=1 and int(c)<=40):
                    if(int(c)<=15):
                        print("Propedeutico")
                        print(ord(b)-64)
                        continue
                    if(int(c)>18):
                        print("Canchas")
                        continue
                    print(x[int(c)-16])
                    print(ord(b)-64)
                    continue
                print("CNV")
                continue
            print("CNV")
            continue
        print("CNV")
else:
    print("CNV")
    