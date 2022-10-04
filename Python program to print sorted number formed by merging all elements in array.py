# Python program to print sorted number by merging
# all the elements in array function to print
# sorted number

def getSortedNumber(number):

	# sorting the string
	number = ''.join(sorted(number))

	# converting string to integer
	number = int(number)

	# returning the result
	print(number)

# function to merge elements in array


def mergeArray(lis):

	# convert the elements of list to string
	lis = list(map(str, lis))

	# converting list to string
	string = ''.join(lis)

	# passing this string to sortednumber function
	getSortedNumber(string)


# Driver code
lis = [7, 845, 69, 60]

# passing list to merge array function to merge
# the elements
mergeArray(lis)
