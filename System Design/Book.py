class Book:
	def __init__(self, name, published_year, price):
		self.name = name
		self.published_year = published_year
		self.price = price

book_list = []

NUMBER_OF_BOOKS = 5

for i in range(NUMBER_OF_BOOKS):
	name, published_year, price = input("Enter book name, published_year and price as space-separated input: ").split()
	published_year, price = int(published_year), int(price)
	book_list.append(Book(name, published_year, price))

book_list.sort(key = lambda x: x.price)
print("\nBook List sorted by price:\n")
print("Book name\tBook Price\tBook Published Year")
for i in book_list:
	print(f"{i.name}\t\t{i.price}\t\t{i.published_year}")

print()
book_list.sort(key = lambda x: x.name)
print("\nBook List sorted by name:")
print("Book name\tBook Price\tBook Published Year")
for i in book_list:
	print(f"{i.name}\t\t{i.price}\t\t{i.published_year}")

print()
book_list = [[book.published_year, book.price, book.name] for book in book_list]
print("Shuffled book data in the format: Published Year, Price, Name")
for book in book_list:
	print(book)