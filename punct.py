import string
def remove_punct(my_story):
    words_without_punct=""
    for letter in my_story:
        if letter not in string.pictuation:
           words_without_punct+=letter
    return words_without_punct
my_story="""India is my country,All Indians are my "Brothers and Sisters";I love my country!"""
my_result=remove_punct
print("are the words without punctuation: ",my_result)
words=my_result.split()
print(words)
