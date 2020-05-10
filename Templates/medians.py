#Running medians solution
from heapq import heappush, heappop

with open('medians.txt') as f:
	nums = [int(x) for x in f]

Hlow = []
Hhigh = []
heappush(Hlow, -nums[0])
s = nums[0]
n = 1

while n < len(nums):
	if(nums[n] <= -Hlow[0]):
		heappush(Hlow, -nums[n])
		if len(Hlow) > len(Hhigh) + 1:
			heappush(Hhigh, -heappop(Hlow))
	else:
		heappush(Hhigh, nums[n])
		if len(Hlow) < len(Hhigh):
			heappush(Hlow, -heappop(Hhigh))

	s += -Hlow[0]
	s %= 10000
	n += 1

print(s)