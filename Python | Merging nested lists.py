# Python3 program to find Greatest common
# intersection of two nested lists
import itertools
import functools

def GCI(lst1, lst2):
	
	temp1 = functools.reduce(lambda a, b: set(a).union(set(b)), lst1)
	temp2 = functools.reduce(lambda a, b: set(a).union(set(b)), lst2)
	
	lst3 = [list(set(a).intersection(set(b)))
		for a, b in itertools.product(lst1, lst2)
		if len(set(a).intersection(set(b))) != 0]
	
	lst3.extend([x] for x in temp1.symmetric_difference(temp2))
	
	return lst3
		
# Driver code
lst1 = [[5, 9], [8, 2, 6], [3, 4]]
lst2 = [[9, 5, 8], [2, 6], [3, 4, 1]]
print(GCI(lst1, lst2))
