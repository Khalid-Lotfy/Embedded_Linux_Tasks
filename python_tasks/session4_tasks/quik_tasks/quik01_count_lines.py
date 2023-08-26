

  #  count number of lines in a text file

with open("test.txt",'+r') as f:        
    print("number of lines in the file: ",len(f.readlines())) 
    

  #  count number of words in a text file

with open("test.txt",'+r') as f:        
    print("number of words in the file: ",len(f.read().split()))  



  #  other way  using enumerate

with open("test.txt",'+r') as f:
    for count,line in enumerate(f,1):      
        pass
    print("number of lines in the file: ",count)


