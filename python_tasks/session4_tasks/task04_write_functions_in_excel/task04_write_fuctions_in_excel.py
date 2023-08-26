# parse header file and read all prototypes of function and insert it into excel sheet with unique ID start with IDX0

'''
   explanation for pattern used to search for C function prototyopes in the header file  according to 're' module

1. `^` - The caret symbol at the beginning of the pattern denotes that the line should start with the following pattern.

2. `\s*` - This matches zero or more whitespace characters. It allows for optional leading whitespace before the return type of the function prototype.

3. `\w+` - This matches one or more word characters (letters, digits, or underscores). It is used to match the return type of the function prototype.

4. `\s+` - This matches one or more whitespace characters. It is used to separate the return type from the function name.

5. `\w+` - This matches one or more word characters. It is used to match the function name in the prototype.

6. `\(` - This matches the opening parenthesis character. It is used to mark the start of the parameter list in the function prototype.

7. `[^)]*` - This matches any character except the closing parenthesis. It allows for any number of characters within the parameter list of the function prototype.

8. `\)` - This matches the closing parenthesis character. It is used to mark the end of the parameter list in the function prototype.

9. `\s*` - This matches zero or more whitespace characters. It allows for optional whitespace between the closing parenthesis and the semicolon.


'''


import re
import openpyxl

cfunction_list=[]
# read the header file 
with open("prototypes.h",'r') as f:
    lines_list=f.readlines()
    pattern = r'^\s*\w+\s+\w+\([^)]*\)\s*;'  
    # loop on the file lines list to compare each line with the pattern
    for item in lines_list:
      
      if re.match(pattern,item):      # use 're.match' function to compare the line with the pattern
         cfunction_list.append(item)  # when the line matches the pattern  add it to the function list
      else:
         pass   

# clean each function line from the spaces and the \n using strip
cfunction_list = [string.strip() for string in cfunction_list] 

# open the new workbook
workbook=openpyxl.Workbook()

sheet=workbook.active
# make the width of the column bigger
sheet.column_dimensions['A'].width = 40

for i,item in enumerate(cfunction_list,1):
   sheet['A'+str(i)]=item                        # write the function prototypes in column A
   sheet['B'+str(i)]='IDX'+str(i).zfill(3)       # write the ID in column B  
                                                 # use 'zfill' function to write the number in form of  3 digit
     



# save our workbook  and close
workbook.save('prototypes.xlsx')
workbook.close() 