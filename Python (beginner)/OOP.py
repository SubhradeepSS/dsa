x = 5
y = 'hjgrg'
print(type(x))
print(type(y))


# Creating classes and objects
class Dog(object):
    def __init__(self, name, age):  # Constructor
        self.name = name
        self.age = age
        self.li = [4, 2, 7, 7]
        # print('made a dog class')

    def speak(self):
        print(self.name)
        print(self.age)

    def change_age(self, age):
        self.age = age

    def add_weight(self, weight):
        self.weight = weight


tim = Dog('Tim', 55)
fred = Dog('fred', 3)
tim.change_age(9)
tim.add_weight(78)
tim.speak()
fred.speak()
print(tim.weight)


# Inheritance
class Dog(object):
    def __init__(self, name, age):  # Constructor
        self.name = name
        self.age = age

    def speak(self):
        print(self.name)
        print(self.age)

    def talk(self):
        print('Bark')


class Cat(Dog):  # Parent of Cat is Dog
    def __init__(self, name, age, color):
        super().__init__(name, age)
        self.color = color

    def talk(self):
        print('Mew')

    def speak(self):
        print(self.name)
        print(self.age)
        print(self.color)


tim = Cat('tim', 78, 'blue')
tim.speak()
tim.talk()
dog = Dog('dog', 98)
dog.talk()


# General class eg
class Vehicle(object):
    def __init__(self, price, gas, color):
        self.price = price
        self.gas = gas
        self.color = color

    def filluptank(self):
        self.gas = 100

    def emptytank(self):
        self.gas = 0

    def gasleft(self):
        return self.gas


class Car(Vehicle):
    def __init__(self, price, gas, color, speed):
        super().__init__(price, gas, color)
        self.speed = speed

    def beep(self):
        print("Beep!Beep!")


class Truck(Car):
    def __init__(self, price, gas, color, speed, tires):
        super().__init__(price, gas, color, speed)
        self.tires = tires

    def beep(self):
        print("Honk!")


# Overloading Methods
class Point(object):
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        self.coord = (self.x, self.y)

    def move(self, x, y):
        self.x += x
        self.y += y

    def magnitude(self):
        return self.x * self.x + self.y * self.y

    def __add__(self, p):
        return Point(self.x + p.x, self.y + p.y)

    def __str__(self):
        return str(self.x) + " " + str(self.y)

    def __ge__(self, p):
        return self.magnitude() >= p.magnitude()

    def __gt__(self, p):
        return self.magnitude() > p.magnitude()

    def __lt__(self, p):
        return self.magnitude() < p.magnitude()

    def __le__(self, p):
        return self.magnitude() <= p.magnitude()

    def __eq__(self, p):
        return self.x == p.x and self.y == p.y


p1 = Point(3, 4)
p2 = Point(3, 2)
p3 = Point(1, 3)
p4 = Point(0, 1)
p5 = p1 + p3
print(p5.x, p5.y)
print(p5)
print(p1 == p2)
print(p1 > p2)
print(p1 < p2)
print(p1 >= p2)
print(p1 <= p2)


# Static and Class Methods
class myClass:
    lis = []

    def __init__(self, name):
        self.name = name

    @classmethod
    def num(cls):
        return len(cls.lis)

    @staticmethod
    def pr(n):
        for _ in range(n):
            print('Printing')


tim = myClass('tim')
print(tim.num())
myClass.pr(5)

# Private and Public Classes
# Nothing is truly private or public in Python : use _ add prefix to indicate private
