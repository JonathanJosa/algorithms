import random
a = [random.randint(0, 150) for _ in range(150)]
a.sort()
print(a[0:5])
