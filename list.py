def lost_ele(or_list,dup_list):
    or_set=set(or_list)
    dup_set=set(dup_list)
    return list(or_set-dup_set)
or_list=[1,3,5,7,9]
dup_list=[5,9]
print(or_list)
print(dup_list)
print("lost elemts are",lost_ele(or_list,dup_list))
