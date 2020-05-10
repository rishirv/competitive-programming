#Merge sort an array
def sort(arr):
	if len(arr) == 1:
		return arr
	mid = len(arr)//2
	X = sort(arr[:mid])
	Y = sort(arr[mid:])
	i = j = 0
	for k in range(len(arr)):
		if i != len(X) and (j == len(Y) or X[i] < Y[j]):
			arr[k] = X[i]
			i += 1
		else:
			arr[k] = Y[j]
			j += 1
	return arr

arr = [1, 3, 5, 2, 4, 6]
print(sort(arr))