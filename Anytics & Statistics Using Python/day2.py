# <----------------------------------------STRINGS----------------------------------------------->

name = 'virat'
lastName = 'kohli'


# -----------------------------------------------------------
# concatenate strings

    # '+' operator
fullName = name + ' ' + lastName
print(fullName)

    # using formatter
fullName = f'{name} {lastName}'
print(fullName)

    # using join() function
' '.join([name, lastName])

# -----------------------------------------------------------


len(fullName)


# ------------------------------------------------------------

# escape characters

neg = 'don\'t'
print(neg)
    # \n
    # \t
    # \\
    # \'
    # \"

# ------------------------------------------------------------


language = 'python'


# --------------------------------------------------------------------------------------


# formatted string

    #using %s
formatedString = 'I am %s %s. I am learning %s.'%(name,lastName,language)
print(formatedString)

    # using %r
formatedString = 'I am %r %r. I am learning %r.'%(name, lastName,language)
print(formatedString)

    # using {}
formatedString = 'I am {} {}. I am learning {}.'.format(name, lastName,language)
print(formatedString)

    # using {} with considering index as (name,lname,language)
formatedString = 'I am {2:} {0:}. I am learning {1:}.'.format(name, lastName,language)
print(formatedString)


for c in formatedString:
    print(c,end = '-')
    
    
# --------------------------------------------------------------------------------------


    
# -----------------------------------

# unpacking
    # language = 'python'
a,b,c,d,e,f = language
print(a,b,c,d,e,f)

# -----------------------------------



# -----------------------------------
    
# string slicing

language[2:4]
language[::-1]

formatedString[3:12:2]


# -----------------------------------


    # lower case to upper case

sentence = 'neeraj wins silver medals'
sentence.capitalize()

    # counting letter in a string

sentence.count('e')

    # using endswith method

sentence.endswith('medals')


    # using expandtabs method
    
sentence = 'neeraj\twins\tsilver\tmedal'
sentence.expandtabs()


    # using find method

sentence.find('silver')

    # used to check from right side

sentence.rfind('e')

    # finding index

sentence.index('silver')

    # finding index from right side
    
sentence.rindex('silver')


# ---------------------------------------------------------


sentence = 'neeraj wins silver medal'
sentence1 = 'neeraj wins silver medal in 2024'
sentence2 = 'neerajwinssilvermedalin2024'
sentence3 = 'neerajwinssilvermedal'


    # checking if string contains only numbers

print(sentence.isalnum())
print(sentence1.isalnum())
print(sentence2.isalnum())
print(sentence3.isalnum())


    # checking if string contains only alpabets

print(sentence.isalpha())
print(sentence1.isalpha())
print(sentence2.isalpha())
print(sentence3.isalpha())


#-------------------------------------------------------------


    # using split method
sentence1.split()


    # using split method with separator
''.join(sentence1.split())



#-------------------------------------------------------------

    #checking type of number
num = '123'
print(num, ":", num.isdecimal())

num = '12.3'
print(num, ":", num.isdecimal())

num.split('.')

num = '\u00B2'
print(num, ":", num.isdigit())

num = '10\u00BD'
print(num, ":", num.isnumeric())


#-------------------------------------------------------------
sent = 'variable'
sent.isidentifier()

name.islower()
name.lower()
name.isupper()
name.upper()

word = ' almands '
word.strip()

word1 = 'alola'
word1.strip('a')

sentence4 = 'NeerajWinsSilverMedal'
sentence4.istitle()

sentence4.title()

sentence4.swapcase()



str = 'abbcbba'
if str[::-1] == str[0:]:
    print("palindrome")
else:
    print("not a palindrome")
    
