#Karatsuba multiplication
import math

def multiply(x, y):
	if(x<10 or y<10):
		return x*y
	n = math.floor(math.log10(min(x, y))) + 1 #Number of digits in smaller number
	div = 10**(n//2)
	(a, b), (c, d) = divmod(x, div), divmod(y, div)
	first = multiply(a, c)
	last = multiply(b, d)
	middle = multiply(a+b, c+d) - first - last
	return first*(div**2) + middle*div + last


x, y = 3141592653589793238462643383279502884197169399375105820974944592, 2718281828459045235360287471352662497757247093699959574966967627
print(multiply(x, y))