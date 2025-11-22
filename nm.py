def grp(colors):
    result={}
    for key,value in colors:
        result.setdefault(key,[]).append(value)
    return result
colors=[('blue',1),('green',2),('blue',3)]
print(grp(colors))
