#count the number 4 in a given list

user_list=input("enter your list separated by spaces:")  #take the list from user as a string
user_list=user_list.split()                              #remove the spaces from the list
user_list=list(map(int,user_list))                       #conver the list from strings to integers
print("the count of 4 is :",user_list.count(4))          #use the function count to count the 4s in the list
