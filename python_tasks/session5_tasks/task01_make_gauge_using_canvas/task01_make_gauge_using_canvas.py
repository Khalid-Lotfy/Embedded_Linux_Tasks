from tkinter import *

# the function used to make the movement of the needle
def update_gauge():
   global value
   global angle
   global flag
   # 2 conditions to control the movement whithin the limits
   if angle<=150 and flag==0:  
       angle-=1
       value+=.83
       if angle==30:
           flag=1
   if angle>=30 and flag==1:
       angle+=1
       value-=.83
       if angle==150:
           flag=0
    # set the angle and value to itemconfig function that will update these value and draw a new needle according to the new vlaue       
   canvas.itemconfig(needle,start=angle)
   canvas.itemconfig(id_text,text=str(round(value,0))+" %")
   window.after(50,update_gauge)
           
   
value=0
angle=150
flag=0

# the window and its configuration
window=Tk()
window.geometry("600x500+500+200")
window.title("canvas")
window.resizable(False,False)
window.configure(background='white')



# make a new canvas 
canvas=Canvas(window,background='white',width=600,height=500)
# make coordinates for the arcs
coord=100,80,500,480

# make the black arc
for i in range(30,150,20):
     canvas.create_arc(coord,start=i,extent=20,outline='black',width=1)

# make the three colored arcs
canvas.create_arc(coord,start=30,extent=20,outline='red',width=40,style='arc')
canvas.create_arc(coord,start=50,extent=20,outline='yellow',width=40,style='arc')
canvas.create_arc(coord,start=70,extent=80,outline='green',width=40,style='arc')

# write the required texts
canvas.create_text(300,30,font='Times 20 italic bold',text='Humidity')
canvas.create_text(110,200,font='Times 20 italic bold',text='0')
canvas.create_text(500,200,font='Times 20 italic bold',text='100')

# make handlers for the needle and the value of the gauge
id_text=canvas.create_text(300,300,font='Times 20 italic bold',text='0')
needle=canvas.create_arc(coord,start=70,extent=1,outline='black',width=5)

canvas.place(x=0,y=0)

# calling update function to make the needle move
update_gauge()


window.mainloop() 

