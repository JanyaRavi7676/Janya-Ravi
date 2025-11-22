import string
def remove_punct(mystory):
    phrase=""
    for letters in mystory:
        if letters not in string.punctuation:
            phrase+=letters
            
    return phrase
mystory="""All Indians are my "brothers and sisters",India is my country;I love my country."""
result=remove_punct(mystory)
print("\nphrases without punctuations:\n"+result)
words=result.split()
print("\nwords are:\n",words)
