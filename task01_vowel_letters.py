#test whether a passed letter is vowel or not

vowel_letters=['a','e','i','o','u','A','I','O','U','E']

letter=input("enter your letter:")

print("your letter is a vowel") if letter in vowel_letters else print("your letter is not a vowel")