def is_prime(n):
    flag=True
    for f in range(2,n//2+1):
     if n%f==0:
        flag=False
    return flag
def prm_list(num):
    list=[]
    for n in range(2,num):
        if is_prime(n):
            list.append(n)
    return list
n=int(input("enter the value:"))
print("list of prime are",prm_list(n))     
        
