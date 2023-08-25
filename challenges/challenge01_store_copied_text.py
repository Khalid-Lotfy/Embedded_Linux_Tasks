import pyperclip
import keyboard
import os
import threading

 
# task to store the copied text from clipboard to 'copied_text' variable
def copy_task():
    global copied_text                # global to be seen in other tasks

    while True:                       # make the function always working
      copied_text=pyperclip.paste()   #function paste from pyperclip module that takes the copied text form clipboard


# task to open the notes file and sotre the wwrite 'copied_text' in the file (only when the shortcut is triggered)
def on_triggered():
    if os.name == 'posix':
      file=open(notes_file,"a")       #open the file which its path is input from user
      file.write(copied_text)         #write the stored text

# task uses keyboard module to listen for shortcut and call (on_triggered) task to be executed when the shortcut is pressed
def listen_for_shortcut():
    # Set the desired shortcut key combination
    shortcut = "alt + shift + s"
    keyboard.add_hotkey(shortcut, on_triggered)      
    # Register the callback function for the shortcut
    keyboard.wait()   


if __name__== "__main__" :

    notes_file=input("please enter your notes file path: ")  #take the file path from user
    # divide the process into  threads  because they have two infinite loops
    t1=threading.Thread(target=copy_task)               # task1 to store the copied text
    t2=threading.Thread(target=listen_for_shortcut)     # task2 uses the kyboard and listen for shortcut

     # start  threads
    t1.start()
    t2.start()
    # wait for threads to terminate
    t1.join()
    t2.join()
  