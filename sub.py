list1=list(map(int,input("enter the list of elements:").split()))
list2=list(map(int,input("enter the list of elements:").split()))
if set(list2).issubset(list1):
    print("subset")
else:
    print("no")
