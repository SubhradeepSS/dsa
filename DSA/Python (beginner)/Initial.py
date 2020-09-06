# Reading from a file
file = open('eg.txt', 'r')
f = file.readlines()
# print(file)
o = []
for line in f:
    o.append(line.strip())
file.close()
# print(o)

# Writing to a file
file = open('eg.txt', 'w')
file.write('python\n')
file.write('next line')
file.close()

# Methods on string and list .find() and .count()
s = 'hello'
print(s.find('o'))
print(s.find('i'))
print(s.count('h'))
print(s.count('le'))

s1 = input("Please enter a string:")
if s1.count('_') != 0:
    print('_ present')
else:
    print('_ not present')

# Modular Programming
import math
import myModule

print(math.sqrt(7))
print(math.radians(math.pi))
print(myModule.myFunc(8))
print(myModule.another_func(8))


# Optional Parameters
def func(x=6, text='2'):
    print(x)
    if text == '1':
        print('Text is 1')
    else:
        print('text is ' + str(text))

func(5, '67')
func()

# Try and except
text = input('Username:')
try:
    number = int(text)
    print(number)
except:
    print("Invalid Username")
