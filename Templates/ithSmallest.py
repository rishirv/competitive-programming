#Selects the ith smallest element in an array (Modified quicksort)
from random import randint

def select(arr, choosePivot, k):
	return selectPartition(arr, 0, len(arr), choosePivot, k-1)

def selectPartition(arr, start, end, choosePivot, k): #end = len
	if end - start <= 1:
		return arr[start]
	pos = choosePivot(arr, start, end)
	arr[start], arr[pos] = arr[pos], arr[start]
	pivot = arr[start]
	i = start + 1
	for j in range(start+1, end):
		if arr[j] < pivot:
			arr[i], arr[j] = arr[j], arr[i]
			i += 1
	arr[i-1], arr[start] = arr[start], arr[i-1]
	if k == i - 1:
		return arr[i - 1]
	if k < i - 1:
		return selectPartition(arr, start, i-1, choosePivot, k)
	return selectPartition(arr, i, end, choosePivot, k)



arr = [3, 1, 2, 4, 5]
print(select(arr, lambda arr, a, b: randint(a, b-1), 2))