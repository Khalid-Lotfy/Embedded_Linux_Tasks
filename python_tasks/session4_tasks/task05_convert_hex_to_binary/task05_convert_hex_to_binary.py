# convert hex file to binary file

# xxd -p <input_file> <output_file>  command generates hex file form a python file

import binascii


with open('input.hex', 'r') as f:
    hex_data = f.read().strip()

# Convert the hex data to binary
binary_data = bin(int.from_bytes(binascii.unhexlify(hex_data),byteorder='big'))

# Write the binary data to a file
with open('output.bin', 'w') as f:
    f.write(binary_data[2:])   # remove 0b from the first


       # another solution  without bin 
'''

with open('input.hex', 'r') as f:
    hex_data = f.read().strip()


# Convert the hex data to binary

hex_to_int=int(hex_data,16)
binary_data=bin(hex_to_int)

# Write the binary data to a file
with open('output.bin', 'w') as file:
    file.write(binary_data)
    
    '''