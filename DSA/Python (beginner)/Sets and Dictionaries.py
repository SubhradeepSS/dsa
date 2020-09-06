# Set (not ordered) - fast  # O(logn) almost O(1)- very fast
s = {1, 2, 3, 4}
print(type(s))
a = [1, 2, 3, 4]  # list(ordered) - O(n) for list
print(type(a))
# print(s[0])
a = [1, 1, 3, 4]
print(a)
s = {1, 1, 3, 4}
print(s)  # set does not support duplicate values
s = {'gf', 4, 9.0}
print(s)

# O(1) for add,remove in set

# To check duplicates
s = [1, 0, 3, 2, 10, 4, 5]
if len(set(s)) != len(s):
    print("present")
else:
    print('absent')

# Converting to set takes O(n) time

# Dictionaries - unordered,unique,mutable,key-value pair,operations are fast like set
d = {'apple': 8, 'pear': 9}
print(d)
print(d['apple'])  # access only by key,not index
d[(4, 2)] = 4
print(d)

s = "hellomyname"
output = {}
for i in s:
    if i in output:
        output[i] += 1
    else:
        output[i] = 1
print(output)
print(output['e'])
for i in output:
    print(i)
for i in output.values():
    print(i)
for i, j in output.items():
    print(str(i) + ':' + str(j))
