ar = []
ar = [int(i) for i in input("Enter the input list of numbers: ").split()]

SUM = 2
n = len(ar)
ar.sort()

ans = []

for i in range(n - 3):
	for j in range(i + 1, n - 2):
		diff = SUM - ar[i] - ar[j]

		left, right = j + 1, n - 1

		while left < right:
			if ar[left] + ar[right] < diff:
				left += 1
			
			elif ar[left] + ar[right] > diff:
				right -= 1 

			else:
				ans.append([ar[i], ar[j], ar[left], ar[right]])
				left += 1
				right -= 1

print(f"\nQuadruplets summing to {SUM} are:\n")

for i in ans:
	print(i)