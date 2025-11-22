import turtle
def multi(animal,size):
    for colors in["Red","Blue","Black","Pink"]:
        animal.color(colors)
        animal.forward(size)  
        animal.left(90)
window=turtle.Screen()
window.bgcolor("lightgreen")
tess=turtle.Turtle()
tess.pensize(5)
size=20
for _ in range(15):
    multi(tess,size)
    size+=10
    tess.forward(10)
    tess.right(18)
window.mainloop    
        
