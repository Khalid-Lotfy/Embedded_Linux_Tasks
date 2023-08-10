#find the maximum number in a given list

ls=input ("enter your list separated by spaces:")
ls=ls.split()
ls=list(map(int,ls))

print("tha maximum number in the list is:{}".format(max(ls)))
