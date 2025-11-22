n=int(input("enter the size of the table:"))
for row in range(1,n+1):
    for column in range(1,n+1):
        product=row*column
        print('{0:4}'.format(product),end='')
    print()    
