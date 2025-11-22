age=int(input("Enter age of your choice:"))
def classify_age(age):
    match age:
        case age if 0<=age<=11:
            return "kid"
        case age if 12<=age<=19:
            return "Teenager"
        case age if 20<=age<=35:
            return "Young"
        case age if 36<=age<=55:
            return "Middle aged"
        case age if 56<=age<=100:
            return "Old aged"
        case _:
            return "Invalid age"
print(f"You are {classify_age(age)}")        
