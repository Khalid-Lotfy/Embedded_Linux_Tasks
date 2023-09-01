from tkinter import *

def led_off():
    canvas.itemconfig(led,fill='white')   # fill with white as off
    label1.config(text='Led is off')      # update the label

def led_on():
    canvas.itemconfig(led,fill='red')  # fill with red as on
    label1.config(text='Led is on')   # update the label


# the window and its configuration
window=Tk()
window.geometry("500x500+500+200")
window.title("led")
window.resizable(False,False)
window.configure(background='white')

# make a new canvas 
canvas=Canvas(window,background='white',width=600,height=500)
# make coordinates for the arcs
coord=50,50,150,150

#  create a circle as led
led=canvas.create_oval(coord,outline='black',fill='white')

#  create label to write led status
label1=Label(window,text='Led is off',background='white',fg='black',width=15,height=2)

# 2 buttons for turning on and off
button1=Button(window,text='led ON',width=5,height=2,command=led_on)
button2=Button(window,text='Led OFF',width=5,height=2,command=led_off)

# place each widget on the window
canvas.place(x=0,y=0)
label1.place(x=230,y=300)
button1.place(x=250,y=340)
button2.place(x=250,y=390)

window.mainloop()


