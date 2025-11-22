n=float(input("enter a number to find its square root using approximation method:"))
threshold=0.001
approximation=n/2
while True:
    better=(approximation+n/approximation)/2
    if abs(approximation-better)<threshold:
        print(round(better,2))
        break
    approximation=better
