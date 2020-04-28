#CMPE-325 _ HW-3 _ MÇ 19244710068
# All outputs seem true
from functools import reduce
from itertools import combinations
import pickle

#if there is no tuple exist then we can simply make those a tuple
def concatenation(a1,a2):
	output = [a1,a2]
	return tuple(output)

#for tuple sets
def concatenation2(a1,a2):
	newout = list(a1)
	output = []
	#print("A1:",a1,"A2:",a2)
	for x in range(len(a1)):
		for y in range(len(a2)):
			#print("Checking:",a2,a1[x][-1],a1[x])
			#check if new element has greater index point from current
			if(a2[y] not in a1[x] and y > getIndex(a2,a1[x][-1])):
				#print("what happen:",a2[y]," not inside ",a1[x])
				#creating new list
				newThing = list(newout[x])
				newThing.append(a2[y])
				output.append(tuple(newThing))
	return output
	
#to see is the element index greater than current one.
def getIndex(arr,elem):
	#print("getINDEX:",arr,elem)
	for x in range(len(list(arr))):
		if(arr[x] == elem):
			return x
			
#calling map function in this function
def create_frequency_sets(arr1, arr2):
	flist = []
	#at first run check if it is not tuple set
	if(len(arr1) == len(arr2) and isinstance(arr2[-1], tuple) == 0):
		for i in range(len(arr1)-1):
			x = list(map(concatenation,[arr2[i]]*len(arr1),arr1[i+1:]))
			#print(x)
			for n in range(len(x)):
				flist.append(x[n])			
	else:
	#if this is a tuple set then use concatenation2 function
		#print(">>> arr1:",arr1,"arr2:",arr2)
		x = list(map(concatenation2,[arr2],[arr1]))
		#print("FINAL X:",x)
		for i in range(len(x)):
			for n in range(len(x[i])):
				flist.append(tuple(x[i][n]))
	return flist

def countOccurrences(m1,m2):
	output = {}
	#print("Currently m1:",m1,"\nm2: ",m2,"\n\n")
	#at first pass, m1 is not dictionary
	if(isinstance(m1, tuple) or isinstance(m1, list)):
		output[tuple(m1)] = 1
		#at first run, we have to count M1 items #FIX 1
		for m1item in m1:
			if(m1item not in list(output.keys())):
				output[tuple([m1item])] = 1
	else:
		output = m1 #get and set dictionary to output dictionary
	
	#if m2 is just a char array (string) such as kola, make it whole #FIX 2
	if isinstance(m2,str):
		m2 = [m2]
	
	#all m2 list combinations
	m2combinations = [tuple(map(tuple, combinations(m2, i))) for i in range(len(m2) + 1)]
	for i in m2combinations:
		for j in i:
			if(j):
				#print("J value:",j)
				if(j in list(output.keys())):
					output[j] += 1
				else:
					output[j] = 1
		
	#passing or returning dictionary
	return output
	
def calculate_occurences(thelist):
	#using reduce function and sending all values to countOccurrences function
	finalOut = reduce(countOccurrences, thelist)
	print("-------------------------------","\nTotal:",len(finalOut),"item(s)\nOccurrences => ",finalOut,"\n\n########################################\n")
	return finalOut

#my main function
def runforestgump(item_list):
	main_list = [] #list (this one will use for calculating occurrences.)

	#insert initial values
	for i in range(len(item_list)):
		main_list.append([item_list[i]])
	
	#set starting/initial list
	current = item_list
	#print initial list
	print(">",1,"element subset => ",current,"\n")
	
	#go and get frequency sets for multiple times
	for m in range(len(item_list)-1):
		current = create_frequency_sets(item_list,current)
		print(">",m+2,"element subset => ",current,"\n")
		#final_list.append(current)
		#add new contents to Final List
		for i in range(len(current)):
			main_list.append(current[i])
	
	
	#calculating occurences in the list
	dataOut = calculate_occurences(main_list)
	#saving file pickle format ??
	'''
	with open('test.txt', 'wb') as handle:
		pickle.dump(dataOut, handle, protocol=pickle.HIGHEST_PROTOCOL)
	'''
	
	
####################################################################
####################################################################
# Running for both example in HW document
item_list = [('A'), ('B'), ('C'), ('D')]
runforestgump(item_list)

item_list = [('kola'), ('fıstık'), ('su'), ('ayran'), ('gazoz'), ('fanta')]
runforestgump(item_list)

# HW PART - 2
receipt_list = [ ("kola", "su", "fanta"), ("kola", "fıstık"), ("kola","su","gazoz","fanta"), ("kola","fanta"), ("kola","gazoz"), ("kola","su"), ("kola","fıstık","su"), ("kola","fıstık"), ("fıstık","su","gazoz"), ("ayran","gazoz"),("fıstık","gazoz"),("fıstık","ayran", "gazoz"), ("su"),("su","fanta"),("su","gazoz"),("gazoz"),("gazoz","fanta"),("fıstık","ayran","fanta"), ("kola","ayran","fanta"),("fanta"),("su","fanta"),("gazoz"),("su","gazoz"),("fıstık","su","gazoz"), ("kola","su"),("fıstık","su","ayran","gazoz","fanta"),("kola","su","ayran","fanta"), ("fıstık","ayran","gazoz","fanta"),("kola","su","ayran","gazoz","fanta"), ("kola","fıstık","su","ayran","gazoz","fanta")]
print("========================================\n======> HW Part 2 - Receipt List <======\n========================================\n",receipt_list)
dataOut = calculate_occurences(receipt_list)
with open('receiptList.pickle', 'wb') as f:
	pickle.dump(dataOut, f, pickle.HIGHEST_PROTOCOL)
	print('Receipt occurrences list available in a pickle format. Open \'receiptList.pickle\' file.')
'''
with open('receiptList.pickle', 'rb') as f:
	dataDict = pickle.load(f)
'''
#################################################
####################################################################