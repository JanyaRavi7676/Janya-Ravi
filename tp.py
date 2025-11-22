list_of_tuples=[(2,3),(5,8),(2,7),(1,5)]
print("original list is",list_of_tuples)
list_of_tuples.sort(key=lambda x:x[0]+x[1])
print(list_of_tuples)
