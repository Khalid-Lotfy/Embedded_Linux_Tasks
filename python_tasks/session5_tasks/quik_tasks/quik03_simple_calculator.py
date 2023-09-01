from tkinter import *

# function to be executed in when button pressed
def calc():
    global label3
    # when the radio button value is 1 'subtract'
    if v.get()==1:
      label3.config(text=f'The sub is: {entry1.get()} - {entry2.get()} = {int(entry1.get())-int(entry2.get())}')
    # when the radio button value is 2 'sum'
    elif v.get()==2:
       label3.config(text=f'The sum is: {entry1.get()} + {entry2.get()} = {int(entry1.get())+int(entry2.get())}')
    else:
        label3.config(text='please choose an operation')
       
        

# the window and its configuration
window=Tk()
window.geometry("400x300+500+200")
window.title("calculator")
window.resizable(False,False)
window.configure(background='white')


# make the widgets on the window
label1=Label(window,text=' enter value of M : ',background='white',fg='black',width=15,height=2)
label2=Label(window,text=' enter vlaue of N : ',background='white',fg='black',width=15,height=2)
label3=Label(window,background='white',fg='black',width=30,height=2)

entry1=Entry(window,background='white')
entry2=Entry(window,background='white')

button=Button(window,text='validate',width=5,height=2,command=calc)

v=IntVar()
rb1=Radiobutton(window,text='sub',variable=v,value=1)
rb2=Radiobutton(window,text='sum',variable=v,value=2)


# place the widgets on the window
label1.place(x=20,y=10)
label2.place(x=20,y=40)
label3.place(x=120,y=100)

entry1.place(x=180,y=20)
entry2.place(x=180,y=50)

rb1.place(x=100,y=150)
rb2.place(x=100,y=170)

button.place(x=200,y=150)




window.mainloop()