
#   write list to a text file

ls=["red","yellow","black","green"]

with open("text1.txt",'a') as f :  #open the file
    for item in ls:                # write each item in the list separately
        f.write(item+" ")
    f.write("\n")    