import turtle
def draw_sqr(animal,size):
    for colors in("Red","Pink","Black","Yellow"):
       animal.color(colors)
       animal.forward(size)
       animal.left(90)
Window=turtle.Screen()
Window.bgcolor("light green")
tess=turtle.Turtle()
tess.pensize(5)
size=20
for _ in range(15):
    draw_sqr(tess,size)
    size+=10
    tess.forward(10)
    tess.right(20)
    
Window.mainloop()
