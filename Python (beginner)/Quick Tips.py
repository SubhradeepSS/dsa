# for else
l = [2, 3, 1, 6, 8]
m = [4, 2, 7, 8]
for i in l:
    for j in m:
        if i == j:
            print(i, "present in both lists")
            break
    else:
        print(i, 'present in one list')

# Enumerate
for i, j in enumerate(l):
    print(i, j)

# Swap in one line
a = 56
b = 87
a, b = b, a
print(a, b)
