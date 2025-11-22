import turtle
import time
def drw_poly(n):
    try:
        win=turtle.Screen()
        win.bgcolor("light green")
        tess=turtle.Turtle()
        if n<0:
            raise ValueError
        else:
            angle=360/n
            for i in range(n):
                tess.forward(50)
                tess.left(angle)
                time.sleep(1)
    except ValueError:
         print("no of sides cant be negative")
    finally:
         win.mainloop()
n=int(input("enter the number of sides"))
drw_poly(n)
         
