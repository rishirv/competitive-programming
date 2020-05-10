#Performs a quicksort with function input for choosing Pivot
def sort(arr, start, end, choosePivot): #end = len
	if(end - start > 1):
		t = end - start - 1
		pos = choosePivot(arr, start, end)
		arr[start], arr[pos] = arr[pos], arr[start]
		pivot = arr[start]
		i = start + 1
		for j in range(start+1, end):
			if(arr[j] < pivot):
				arr[i], arr[j] = arr[j], arr[i]
				i += 1
		arr[i-1], arr[start] = arr[start], arr[i-1]
		t += sort(arr, start, i-1, choosePivot)
		t += sort(arr, i, end, choosePivot)
		return t
	return 0

def medianOfThree(arr, i, k):
	k -= 1
	j = (i + k)//2
	if arr[i] < arr[j]:
		if arr[j] < arr[k]:
			return j
		if arr[i] < arr[k]:
			return k
		return i
	if arr[j] > arr[k]:
		return j
	if arr[i] > arr[k]:
		return k
	return i

# def sortPivotLast(arr, start, end): #end = len - 1
# 	if(start < end):
# 		t = end - start
# 		pivot = arr[end]
# 		i = start
# 		for j in range(start, end):
# 			if(arr[j] < pivot):
# 				arr[i], arr[j] = arr[j], arr[i]
# 				i += 1
# 		arr[i], arr[end] = arr[end], arr[i]
# 		t += sortPivotLast(arr, start, i-1)
# 		t += sortPivotLast(arr, i + 1, end)
# 		return t
# 	return 0

f = open("quicksortArray.txt","r")
arr = []
for line in f:
  arr.append(int(line))
f.close();

print(sort(arr[:], 0, len(arr), lambda arr, start, end: start))
print(sort(arr[:], 0, len(arr), lambda arr, start, end: end-1))
print(sort(arr[:], 0, len(arr), medianOfThree))