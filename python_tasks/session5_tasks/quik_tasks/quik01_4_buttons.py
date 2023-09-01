
from tkinter import *


# four funcions to be executed when the buttons are pressed
def fun1():
    print('khalid')
def fun2():
    print('mohamed')

def fun3():
    print('ahmed')

def fun4():
    print('mahmoud')    

# make the window and configure its parameters
window=Tk()
window.geometry("220x200+500+200")
window.title("Buttons")
window.resizable(False,False)
window.configure(background='black')

# make four buttons with Button widget function
button1=Button(window,text='button1',width=5,height=3,command=fun1)
button2=Button(window,text='button2',width=5,height=3,command=fun2)
button3=Button(window,text='button3',width=5,height=3,command=fun3)
button4=Button(window,text='button4',width=5,height=3,command=fun4)

# place each button using grid function
button1.grid(row=0,column=1)
button2.grid(row=1,column=0)
button3.grid(row=1,column=2)
button4.grid(row=2,column=1)


window.mainloop()