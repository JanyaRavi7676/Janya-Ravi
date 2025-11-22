def check_character(ch):
    if ch.isdigit():
        return "digit"
    elif ch.isalpha():
        if ch.lower() in 'aeiou':
            return "vowel"
        else :
            return "consonant"
    else :
        return "special character"
char=input("enter a character")
print(f"{char} is {check_character(char)}")
