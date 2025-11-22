def add(a,b) :
    return a+b
def subtract(a,b) :
    return a-b
def multiply(a,b) :
    return a*b
def divide(a,b) :
    if b==0:
      return "division not possible" 
    else :
        return a/b
x=10
y=20
print(f"Sum of integers:{add(x,y)}")
print(f"Difference of integers:{subtract(x,y)}")
print(f"Product of integers:{multiply(x,y)}")
print(f"Quotient of integers:{divide(x,y)}")
p=4.05
q=2.79
print(f"Sum of float:{add(p,q)}")
print(f"Difference of float:{subtract(p,q)}")
print(f"Product of float:{multiply(p,q)}")
print(f"Quotient of float:{divide(p,q)}")
r=complex(2,3)
s=complex(1,7)
print(f"Sum of complex:{add(r,s)}")
print(f"Difference of complex:{subtract(r,s)}")
print(f"Product of complex:{multiply(r,s)}")
print(f"Quotient of complex:{divide(r,s)}")
