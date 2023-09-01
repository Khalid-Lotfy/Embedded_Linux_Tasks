from tkinter import *
import math

# function to be executed in when button pressed
def calc():
    global label2
    # check if the entry is number
    if entry.get().isdigit():
       fact=math.factorial(int(entry.get()))   #calculate the factorial
       label2.config(text=f'The factorial of {entry.get()} is: {entry.get()}! = {fact}')  # update the label with the result
   

       
        

# the window and its configuration
window=Tk()
window.geometry("400x300+500+200")
window.title("calculator")
window.resizable(False,False)
window.configure(background='white')


# make the widgets on the window
label1=Label(window,text=' enter value of M : ',background='white',fg='black',width=15,height=2)
label2=Label(window,background='white',fg='black',width=50,height=2)

entry=Entry(window,background='white')

button=Button(window,text='validate',width=5,height=2,command=calc)




# place the widgets on the window
label1.place(x=20,y=10)
label2.place(x=30,y=100)

entry.place(x=180,y=20)


button.place(x=200,y=150)




window.mainloop()