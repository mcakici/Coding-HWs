#CMPE-325 _ HW-1 _ MÇ 19244710068
#Rules: No Loops Allowed
def f1(arr,item,count):
	newarr = [item]*count + arr + [item]*count
	print(newarr,'\n')
	return

def f2(arr1,arr2,index):
	#I dont know how to determine if it is null or not ??
	try:
		testValue = arr1[index];
	except:
		print(arr1,' # ERROR - (Desired index not defined in the first array, nothing changed)','\n')
		return
	
	# Workflow --> beforeIndex_Elements + Array-2 + AfterIndex_Elements
	newarr = arr1[:index] + arr2 + arr1[index:]
	print(newarr,'\n')
	
def f3(arr,index,count):
	# Workflow --> beforeIndex_Elements + AfterIndex_Elements(Index+ItemCount)
	newarr = arr[:index] + arr[index+count:]
	print(newarr,'\n')
	return
	

print('---------------------------------------------\n',
	  '> Function -1- Insertion [array],item,count',
	  '\n---------------------------------------------')
f1([1,1,1],0,3)

print('---------------------------------------------\n',
	  '> Function -2- Merge [array],[array2],index',
	  '\n---------------------------------------------')
f2([2,4,5,7],[0,9],3)
f2([2,4,5,7],[0,9],6)
f2([2,4,5,7],[1,3,8],0)

print('---------------------------------------------\n',
	  '> Function -3- Delete Elements [array],index,count',
	  '\n---------------------------------------------')
f3([2,4,6,7,3,5,9],2,3)
f3([2,4,6,7,3,5,9],5,9)

print('---------------------------------------------',
	  '\nIf you can see this, all 3 function worked perfect and there is no syntax error! Have a nice day!')
