# Map function
li = [1, 2, 3, 4, 5, 6]


def func(x):
    return x ** x


newlist = []
for x in li:
    newlist.append(func(x))
print(newlist)
print(list(map(func, li)))
print([func(x) for x in li])


# Filter function
a = [1, 2, 3, 4, 5, 6]


def isOdd(x):
    return x % 2 != 0


def add7(x):
    return x + 7


print(list(filter(isOdd, a)))
print(list(filter(isOdd, map(add7, a))))


# Lambda functions
def func(x):
    func2 = lambda x: x + 5  # Using Lambda for nested functions having smaller code
    return func2(x) + 5


# func2 = lambda x: x + 5
print(func(4))
func2 = lambda x, y: x + y  # Any no of parameters (even optional also) but only one return result
print(func2(5, 2))

# Collections - Counter()
import collections
from collections import Counter, namedtuple, deque

c = Counter('gallad')
print(c)
c = Counter(['a', 'a', 'b', 'c', 'c', 'c'])
print(c)
c = Counter({'a': 1, 'b': 3, 'c': 8})
print(c)
c = Counter(a=7, b=5, c=3, d=9)
l = ['a', 'a', 'b', 'd', 'd', 'd']
print(c)
print(c['a'])
print(c['o'])
print(list(c.elements()))
print(c.most_common(2))
c.subtract(l)
print(c)
c.update(l)
print(c)
c.clear()
print(c)

# Named Tuple
Point = namedtuple('Point', 'x y z')
newP = Point(2, 3, 1)
print(newP)
print(newP.x, newP.y, newP.z)  # indexing with name
newQ = newP._replace(x=5)
print(newQ)

# Deque
d = deque('hello')
d.appendleft(3)
print(d)

#
print(hex(30))