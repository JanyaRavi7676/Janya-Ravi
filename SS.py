def is_sub_list(list1, list2): 
        if list2 == [] or list2 == list1: 
                sub_list = True 
        elif len(list2) > len(list1): 
                sub_list = False 
        else: 
                sub_list=False 
                for i in range(len(list1)-len(list2)+1): 
                        if list1[i] == list2[0]: 
                                j = 1 
                                while (j < len(list2)) and i+j < len(list1) and list1[i+j] == list2[j]: 
                                        j += 1 
                                if j == len(list2): 
                                        sub_list = True 
                                        break 
        return sub_list      
 
list1 = [int(item) for item in input("Enter a list of integers: ").split()] 
   
list2 = [int(item) for item in input("Enter a sub list of integers to be searched in the main list: ").split()] 
   
print("Main List:",list1) 
print("Sub list to be searched:",list2) 
 
if is_sub_list(list1, list2): 
        print(list2, "is a sub list of", list1) 
else: 
        print(list2, "is not a sub list of", list1)
