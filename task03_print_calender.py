#print calender of a given month and year

import calendar

Y=int(input("input the year:"))
M=int(input("input the month:"))

print("\n",calendar.month(Y,M))