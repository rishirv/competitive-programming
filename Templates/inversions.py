#Number of inversions in an array (Modified mergesort)
def inversions(arr):
	if len(arr) == 1:
		return 0, arr
	mid = len(arr)//2
	leftInv, X = inversions(arr[:mid])
	rightInv, Y = inversions(arr[mid:])
	splitInv = 0
	i = j = 0
	for k in range(len(arr)):
		if i != len(X) and (j == len(Y) or X[i] <= Y[j]):
			arr[k] = X[i]
			i += 1
		else:
			arr[k] = Y[j]
			j += 1
			splitInv += len(X)-i

	return leftInv + rightInv + splitInv, arr

f = open("inversionsArray.txt","r")
arr = []
for line in f:
  arr.append(int(line))
f.close();
print(inversions(arr)[0])