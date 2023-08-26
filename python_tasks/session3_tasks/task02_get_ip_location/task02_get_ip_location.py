# program to get public ip and use it to get the position of the user using requestes module

import requests

url=requests.get("https://api.ipify.org/?format=json")
#print the public ip
print(url.json())

print("---------------------------------------------------------")
#location website needs the public ip
#add the public ip form the last step to url of the location website
location=requests.get("https://ipinfo.io/"+url.json()['ip']+"/geo")
#print location details
print("location details:\n",location.json())