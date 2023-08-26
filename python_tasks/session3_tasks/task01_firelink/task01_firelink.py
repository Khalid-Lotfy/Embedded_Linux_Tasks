
# program to open a site on the browser through user's input includes some stored favourite websites to choose form 
#the program uses firelink module
from firelink import *


# you can use built_in links    facebook_link  /  github_link   /  valeo_careers   /   youtube_link   /  yallakora_link
#                               whatsapp_web   /  google_search

print("you can choose from built_in links or enter your own URL \n") 
#list the built-in websites for the user  
print(websites.keys(),"\n")
#take the url from user
user_link=input("enter your link to open with firefox: ")

#check if the user's input in built-in websites dictionary                            
if user_link in websites:
   firefox(websites[user_link]) #use the corresponding url of the user's input from the dictionary
else:
   firefox(user_link)           # if the user's input is not from the my websites pass the url directly to the function 
