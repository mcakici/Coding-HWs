#CMPE-325 _ HW-2 _ MÇ 19244710068
#This program trying to find 'the shortest path' from the ending point to the starting point by calculating distance. If it is not impossible.
#There are no special algorithms or 3rd party libraries are used.

#if you want to see how it is work u should enable debug mod
#debug mod will show process of each path and visited points also comments. 1:on, 0:off
debug = 1

# M A P D A T A _ T E S T _ C A S E S
map_information = {(0,1) : "W", (3,1) : "W", (3,3) : "W", (3,4) : "W", "information" : {"rows":5,"columns":5, "start":(0,4), "end":(4,2)}} #From HW Document
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,7) : "W", (5,6) : "W", "information" : {"rows":6,"columns":8, "start":(2,1), "end":(0,7)} } #From HW Document

#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,7) : "W", (5,6) : "W", "information" : {"rows":6,"columns":8, "start":(1,2), "end":(4,7)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,7) : "W", (5,6) : "W", (3,4) : "W", "information" : {"rows":6,"columns":8, "start":(5,1), "end":(3,5)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,7) : "W", (5,6) : "W", (3,4) : "W", "information" : {"rows":6,"columns":8, "start":(0,7), "end":(3,3)} }
#map_information = {(0,1) : "W", (3,1) : "W", (3,3) : "W", (3,4) : "W", (1,4) : "W", "information" : {"rows":6,"columns":8, "start":(4,6), "end":(1,2)}}
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,6) : "W", (1,0) : "W", "information" : {"rows":6,"columns":8, "start":(0,4), "end":(5,4)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,6) : "W", (1,0) : "W", "information" : {"rows":6,"columns":8, "start":(5,0), "end":(0,7)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,6) : "W", (1,0) : "W", "information" : {"rows":6,"columns":8, "start":(2,0), "end":(2,6)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,6) : "W", (0,0) : "W", "information" : {"rows":6,"columns":8, "start":(1,0), "end":(1,7)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,6) : "W", (1,0) : "W", "information" : {"rows":6,"columns":8, "start":(5,7), "end":(0,1)} } #Exception
#map_information = {(1,1) : "W", (1,2) : "W", (2,2) : "W", (3,2) : "W",(3,1) : "W", (4,1) : "W", (5,6) : "W", "information" : {"rows":6,"columns":8, "start":(5,7), "end":(2,1)} }
#map_information = {(1,1) : "W", (2,3) : "W", (0,5) : "W", (4,3) : "W",(2,7) : "W", (5,7) : "W", (5,6) : "W", (0,6) : "W", "information" : {"rows":6,"columns":8, "start":(2,1), "end":(0,7)} }
#map_information = {(4,1) : "W", (4,2) : "W", (4,3) : "W", (4,4) : "W",(4,5) : "W", (4,6) : "W", (5,6) : "W", (0,6) : "W", "information" : {"rows":6,"columns":8, "start":(2,1), "end":(5,4)} }
#map_information = {(1,3) : "W", (2,3) : "W", (3,3) : "W", (4,3) : "W", "information" : {"rows":6,"columns":8, "start":(3,1), "end":(1,4)} } #Long One
#map_information = {(1,3) : "W", (1,3) : "W", (2,4) : "W", (3,4) : "W", (4,4) : "W", (5,4) : "W", (5,6) : "W", "information" : {"rows":6,"columns":8, "start":(3,1), "end":(4,6)} } #15.12
#map_information = {(1,3) : "W", (1,3) : "W", (2,4) : "W", (3,7) : "W", (4,4) : "W", (5,4) : "W", (5,6) : "W", "information" : {"rows":6,"columns":8, "start":(5,1), "end":(4,6)} } #15.12
#map_information = {(1,3) : "W", (2,3) : "W", (3,3) : "W", (4,3) : "W", (4,4) : "W",(4,5) : "W", (4,6) : "W", (5,6) : "W", (0,6) : "W", (2,7) : "W", (5,7) : "W", (3,4) : "W", (10,7) : "W", (9,10) : "W", (9,2) : "W", (10,8) : "W", "information" : {"rows":12,"columns":16, "start":(3,1), "end":(10,9)} }

#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#
startPosition = list(map_information["information"]["start"])
finalPosition = list(map_information["information"]["end"])
print('Start:',startPosition, 'End:', finalPosition, 'Rows:', map_information["information"]["rows"], 'Columns:', map_information["information"]["columns"])
print("--------------------------------------------------------")
output = []
mincellDistance = 0
availablepaths = []
visited = []
failed = 0
lastPoint = []


availablepaths2 = []



#checking walls
def checkwall(x,y):
	try:
		b = map_information[ tuple([x,y]) ]
		if(b == "W" or b == "w"):
			return 1
		else:
			return 0 #can be incorrect map information		
	except:
		return 0 #there is no wall
	
#for change output array order
def reverse_array(arr):
	tmp = []
	for i in reversed(arr):
		tmp.append(i)
		
	return tmp

#find all available cells
def findCells():
	global availablepaths,availablepaths2
	for x in range(map_information["information"]["rows"]):
		for y in range(map_information["information"]["columns"]):
			if(checkwall(x,y) == 0):
				#index 0 is X position, index 1 is Y position, index 2 is distance to start point, index 3 cells to move
				availablepaths.append([x, y, (abs(startPosition[0] - x) + abs(startPosition[1] - y)), getNextMovement([x,y])])
				#print("path: ",[x,y,abs(startPosition[0] - x) + abs(startPosition[1] - y), getNextMovement([x,y])])
			elif((x == startPosition[0] and y == startPosition[1]) or (x == finalPosition[0] and y == finalPosition[1])):
				print("There is an error in 'map_information'. The starting point or ending point cant be the same as wall cells.\n\nThe program is terminated.")
				quit()
				
def findCells2():
	global availablepaths,availablepaths2
	for x in range(map_information["information"]["rows"]):
		for y in range(map_information["information"]["columns"]):
			if(checkwall(x,y) == 0):
				#index 0 is X position, index 1 is Y position, index 2 is distance to start point, index 3 cells to move
				availablepaths2.append([x, y])
				#print("path: ",[x,y,abs(startPosition[0] - x) + abs(startPosition[1] - y), getNextMovement([x,y])])
			else:
				availablepaths2.append(None)
	
#get cell coordinates which can move there
def getNextMovement(arr):
	temp = []
	if(arr[1]+1 < map_information["information"]["columns"] and checkwall(arr[0],arr[1]+1) == 0 and arr[1] != arr[1]+1):
		temp.append([arr[0],arr[1]+1, abs(startPosition[0] - arr[0]) + abs(startPosition[1] - (arr[1]+1)) ])
	if(arr[1]-1 >= 0 and checkwall(arr[0],arr[1]-1) == 0 and arr[1] != arr[1]-1):
		temp.append([arr[0],arr[1]-1,abs(startPosition[0] - arr[0]) + abs(startPosition[1] - (arr[1]-1)) ])
	if(arr[0]+1 < map_information["information"]["rows"] and checkwall(arr[0]+1,arr[1]) == 0 and arr[0] != arr[0]+1):
		temp.append([arr[0]+1,arr[1], abs(startPosition[0] - (arr[0]+1)) + abs(startPosition[1] - arr[1]) ])
	if(arr[0]-1 >= 0 and checkwall(arr[0]-1,arr[1]) == 0 and arr[0] != arr[0]-1):
		temp.append([arr[0]-1,arr[1], abs(startPosition[0] - (arr[0]-1)) + abs(startPosition[1] - arr[1]) ])
	return temp

def findMinDistance(arr):
	#find min distance value
	minDistance = 9999999999
	for j in range(len(arr)):
		if(minDistance > arr[j][2]):
			minDistance = arr[j][2]

	return minDistance


def reconstruct_path():
	path = [finalPosition]
	end_row, end_column = finalPosition
	current_cell = finalPosition
	while current_cell != None:
		print("Current cell",current_cell)
		path.append(current_cell)
		end_row, end_column = current_cell
		print([end_row,end_column],availablepaths2)
		if([end_row,end_column] in availablepaths2):
			current_cell = [end_row,end_column]
		print("Next Current cell",current_cell)
		#print(path)
	return path

#get new path to move
def getMinDistancePath(arr,minDistance):
	#print("getMinDistancePath",arr,minDistance)
	for r in range(len(arr)):
		if(minDistance == arr[r][2] and [arr[r][0],arr[r][1]] not in visited):
			return arr[r]
		
	if(debug):
		print(">>> Trying to enter an alternate path!")
	#if there is no suitable distance then just compare positions
	if(startPosition[0] < lastPoint[0] and startPosition[1] > lastPoint[1]):
		if([lastPoint[0]-1,lastPoint[1]] not in visited and getRealNode([lastPoint[0]-1,lastPoint[1]]) in availablepaths):
			return getRealNode([lastPoint[0]-1,lastPoint[1]])
		elif([lastPoint[0],lastPoint[1]+1] not in visited and getRealNode([lastPoint[0],lastPoint[1]+1]) in availablepaths):
			return getRealNode([lastPoint[0],lastPoint[1]+1])
		elif([lastPoint[0]+1,lastPoint[1]] not in visited and getRealNode([lastPoint[0]+1,lastPoint[1]]) in availablepaths):
			return getRealNode([lastPoint[0]+1,lastPoint[1]])
		elif([lastPoint[0],lastPoint[1]-1] not in visited and getRealNode([lastPoint[0],lastPoint[1]-1]) in availablepaths):
			return getRealNode([lastPoint[0],lastPoint[1]-1])
		
	elif(startPosition[0] > lastPoint[0] and startPosition[1] < lastPoint[1]): # test 4
		if([lastPoint[0]-1,lastPoint[1]] not in visited and getRealNode([lastPoint[0]-1,lastPoint[1]]) in availablepaths):
			return getRealNode([lastPoint[0]-1,lastPoint[1]])
		elif([lastPoint[0],lastPoint[1]-1] not in visited and getRealNode([lastPoint[0],lastPoint[1]-1]) in availablepaths):
			return getRealNode([lastPoint[0],lastPoint[1]-1])
		elif([lastPoint[0],lastPoint[1]+1] not in visited and getRealNode([lastPoint[0],lastPoint[1]+1]) in availablepaths):
			return getRealNode([lastPoint[0],lastPoint[1]+1])
		elif([lastPoint[0]+1,lastPoint[1]] not in visited and getRealNode([lastPoint[0]+1,lastPoint[1]]) in availablepaths):
			return getRealNode([lastPoint[0]+1,lastPoint[1]])
		
	else: #just go somewhere which is available
		for r in range(len(arr)):
			if([arr[r][0],arr[r][1]] not in visited):
				return arr[r]
			
	if(debug):
		print("> An alternate path could not found!")
		

#get real path from availablepaths array		
def getRealNode(arr):
	#print("getRealNode",arr)
	for r in range(len(availablepaths)):
		if(arr[0] == availablepaths[r][0] and arr[1] == availablepaths[r][1]):
			return availablepaths[r]
	return 0

#it is like main function
def findRoute():
	global visited,output,failed,mincellDistance,lastPoint
	findCells()
	print("Total",(map_information["information"]["rows"]*map_information["information"]["columns"])-len(availablepaths),"cell(s) blocked by wall.")
	if(debug):
		#print("Available path data:",availablepaths)
		print("--------------------------------------------------------")

	for i in range(len(availablepaths)):
		if(finalPosition[0] == availablepaths[i][0] and finalPosition[1] == availablepaths[i][1]):
			lastPoint = availablepaths[i]
			mincellDistance = availablepaths[i][2]+1
			visited.append([lastPoint[0],lastPoint[1]])
			output.append([lastPoint[0],lastPoint[1]])
			break

	found = 0
	while(found == 0):
		#get min distance value
		minDistance = findMinDistance(lastPoint[3])
		if(debug):
			print("Current position:",[lastPoint[0],lastPoint[1]],"Search positions (possibilities): ",lastPoint[3])
			print("Min distance to search:",minDistance)
			print("Visited:",visited)
			
		#find min distance path element in the list
		pathFound = getMinDistancePath(lastPoint[3],minDistance)
		
		if(pathFound == None):
			if(debug):
				print("################################################")
				print(">>> Entered Wrong Pathway! <<< Failed:",failed+1)
				print("################################################")
				
			#try to change current path when path is not found.
			if(len(visited) > 4 and failed == 0):
				#go 3 previous point (if it stuck at between wall and corner) (at first stuck)
				output = output[:len(output)-3]
				lastPoint = getRealNode([visited[-4][0],visited[-4][1]])
			elif(failed > 10):
				print("////////////////////////////////////////////////////////")
				print(">>>>>>>>>>> The program entered a DEAD end. <<<<<<<<<<<<")
				print("////////////////////////////////////////////////////////")
				quit()	
			elif(failed == 1 or failed == 2 or (len(visited) < 4 and failed == 0)):
				#or start from beginning
				lastPoint = getRealNode([finalPosition[0],finalPosition[1]])
				output = []
				output.append([lastPoint[0],lastPoint[1]])
					
			failed = failed+1
			continue

		#get real path node
		lastPoint = getRealNode(pathFound)
		if(debug):
			print("New path point found: ",[lastPoint[0],lastPoint[1]])
			print("-------------------------")
		if(lastPoint == 0):
			print("////////////////////////////////////////////////////////")
			print("=============== New path not found! 404 ================")
			print(">>>>>>>> Something gone wrong in the program  <<<<<<<<<<")
			quit()
		
		visited.append([lastPoint[0],lastPoint[1]])
		output.append([lastPoint[0],lastPoint[1]])
		#when distance is equal to 0
		if(lastPoint[2] == 0):
			found=1
			if(debug):
				print("Visited points (final) => ",visited)
				print("--------------------------------------------------------")
	#findCells2()
	#newpath = reconstruct_path()
	#print("newpath",newpath)
	return

findRoute()
print("---------------------- F I N A L -----------------------")
print("Minimum cell distance is",mincellDistance,"(included start, end and wall points)")
print("--------------------------------------------------------")
print("Solution Length:",len(output), "(included start and end points)","\nSolution Paths: ")
print(reverse_array(output))
print('--------------------------------------------------------',
	  '\nThe program is ended')
#Possible Implementations: by saving history and choosing completely alternate path without distance checking OR moving middle point then going end point OR re-calculating all cell distances at each move OR try going start to end, end to start could make a difference
