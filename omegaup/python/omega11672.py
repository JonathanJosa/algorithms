a = input().split(" ")
z = input().split(" ")
v= [int(x) for x in z]
for i in range(int(a[1])):
    e = input().split(" ")
    if(e[0]=="A"):
        v[int(e[1])-1] = int(e[2])
    else:
        r = v[int(e[1])-1:int(e[2])]
        r.sort()
        print(r[0],r[-1])

tiempo_final = time() 
tiempo_ejecucion = tiempo_final - tiempo_inicial 
print 'El tiempo de ejecucion fue:',tiempo_ejecucion #En segundos