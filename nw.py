num=[1,1,2,3,2]
def check(num):
 for i in range(len(num)):
    if num[i]==1 or num[i]==2 or num[i]==3:
        return True
    else:
        return False
res=check(num)
print(res)        