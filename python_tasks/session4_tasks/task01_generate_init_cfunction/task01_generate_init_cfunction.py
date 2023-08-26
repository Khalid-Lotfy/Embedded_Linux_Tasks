
# generate init function for GPIO of AVR

mode="0b"   #initialize mode variable

# take inputs from user  'in' for '0' and 'out' for '1'   loop for 8 times the register size
for i in range(0,8):
    bit=input("Pleade enter Bit {} mode: ".format(i))
    if bit=="in":
       mode+='0'        # add '0' to the end of mode
    elif bit=="out":
       mode+='1'       # add '1' to the end of mode
   
#  format the c program to be generated and add the register mode to it
program='int main(){\n  \
   void INIT_PORTA_DIR(void){\n          DDRA=' +mode+'\n     }\n}'

        
  
#  open the file and write the porgram to it
with open("gpio.c",'w') as f:
    f.write(program)




