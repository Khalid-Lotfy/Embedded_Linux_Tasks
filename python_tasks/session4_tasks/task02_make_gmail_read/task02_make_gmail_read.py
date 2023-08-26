import pyautogui
import webbrowser
import time
import os

#open firefox on the gmail inbox link
webbrowser.get("/snap/bin/firefox").open("https://mail.google.com/mail/u/0/#inbox")

#get the image of setting button of gmail path
imagepath=os.path.dirname(os.path.realpath(__file__))+"/gmail.png"

#search for the image of vs logo on the screen
x=None
y=None
while x is None:
   x=pyautogui.locateCenterOnScreen(imagepath,confidence=.7)

#when fing the setting button in the inbox click on it to open menu
pyautogui.click(x.x, x.y)   
time.sleep(1)

# move mouse to the first choice in the menu 'mark as read' and click
pyautogui.click(x.x+30, x.y+30)   


