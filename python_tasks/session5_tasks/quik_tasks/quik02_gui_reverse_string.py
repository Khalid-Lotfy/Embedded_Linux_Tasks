from tkinter import *

# function will be executed when pressing the button  make a new label and write the entry reversed
def reverse():
    label2.config(text=entry.get()[::-1])

# make the window and configure its parameters
window=Tk()
window.geometry("400x200+500+200")
window.title("tk")
window.resizable(False,False)
window.configure(background='white')

label=Label(window,text=' enter a word : ',background='white',fg='black',width=15,height=2)
label2=Label(window,background='white',fg='black',width=20,height=2)
entry=Entry(window,background='white')
button=Button(window,text='validate',width=5,height=2,command=reverse)

label.place(x=20,y=10)
label2.place(x=120,y=80)

entry.place(x=150,y=20)
button.place(x=150,y=150)


window.mainloop()