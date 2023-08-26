#a program to automatically install some of VS code extensions using pyautogui module

import pyautogui
import time
import os

pyautogui.press('win')    #press win key
time.sleep(2)
pyautogui.write("code")   #type code to search for vs code program

#get the image of vs logo path
imagepath=os.path.dirname(os.path.realpath(__file__))+"/vs.png"

#search for the image of vs logo on the screen
x=None
y=None
while x is None:
   x=pyautogui.locateCenterOnScreen(imagepath,confidence=.7)

#when fing the vs logo click on it to open vs
pyautogui.click(x.x, x.y)   
time.sleep(5)
#press ctrl shift x to open vs extensions
pyautogui.hotkey('ctrl' ,'shift','x')
time.sleep(2)

extensions=["cmake","cmake tools","clangd","c++ helper","c++ testmate"]  #extensions needed to be installed
search_bar=[206,145]                                                  #search bar position (x,y)
extension_result=[235,200]                                             # first extension result position (x,y)
install_button=[666,252]                                               #install button position (x,y)


#loop in the list of extensions
for x in extensions:
     
     #go to search bar position and triple clixk
     pyautogui.tripleClick(search_bar[0],search_bar[1])
     #press backspace to remove any previous searches
     pyautogui.press('backspace')
     #write desired extension name
     pyautogui.write(x)
     #wait for result to be appear
     time.sleep(3)
     #go to the first result position and click
     pyautogui.click(extension_result[0],extension_result[1])
     #wait 
     time.sleep(3)
     #go to the install button position and click
     pyautogui.click(install_button[0],install_button[1])
     #wait for the extension to be installed
     time.sleep(10)
 