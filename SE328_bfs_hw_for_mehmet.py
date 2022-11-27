# SE328 - HW-1 - 19244710068 - Mustafa ÇAKICI
#debug mod for seeing all results and process (1:on,0:off)
debug = 1
import math
location = {
	0: ("Cinema", (256.6, 92.3)),
	1: ("Sport Center", (120.5, 5.5)),
	2: ("Restaurant", (350.0, 165.5)),
	3: ("Cafe", (102.3, 10.26)),
	4: ("Bowling", (40.8, 72.35)),
	5: ("Clothes Store", (92.5, 86.4)),
	6: ("Toy Store", (90.5, 302.1)),
}
print("###################### P L A C E S #####################")
for i in range(7):
	print(i,"=>",location[i][0])
print("--------------------------------------------------------")
startPosition=int(input("Please enter your STARTING position (0-6): "))
endPosition=int(input("Please enter your ENDING position (0-6): "))
print("########################################################")

finalpath = []
routes = []
matrix = [
		[1,2], #from cinema to
		[1,3], #from sport center
		[0,3], #from restaurant
		[1,2,4,5,6], #from cafe
		[3,5], #from bowling
		[3,4,6], # from clothes store
		[3,5] #from toy store
		]


# BFS Algorithm
def find_all_paths():
	global matrix, startPosition, endPosition, finalpath
	q = []
	path = [startPosition]
	q.append(path)

	while len(q) > 0:
		path = q[0] #get first list item to path variable
		q.pop(0) #delete first element from list
		#print("ilk eleman çıkartıldı",q,"çıkarılan:",path)
		last = path[-1] # get last item from list
		#print(">>last:",last)
		
		#print("!>> checking ending point: ", last,"endPosition:",endPosition)
		#if the last element of the list equals to end position then add that list to finalpath list
		if(last == endPosition):
			finalpath.append(path)
		
		#check all list items (connected points) and push them into list as a new path
		for i in range(len(matrix[last])):
			#print(matrix[last][i])
			#print("Bakılacak:",matrix[last][i],"Neyde:",path)
			if(matrix[last][i] not in path):
				newpath = list(path)
				newpath.append(matrix[last][i])
				#print("newpath is ==",newpath,item)
				q.append(list(newpath))
				#print("QUEUE:",q)

			
#Calling main function here
find_all_paths()

if(debug):
	print("All available paths:",finalpath,"\n")

#This part calculates all distances for each point
for points in finalpath:
	if(debug):
		print("#### Points:",points)
	waypoints = []
	totalDistance = 0
	currentPos = startPosition
	#calculate all places in a path
	for i in range(len(points)):
		#math formula for calculate distance between two coordinate points		
		dist = int(math.sqrt((math.pow(location[points[i]][1][0]-location[currentPos][1][0],2) + math.pow(location[points[i]][1][1]-location[currentPos][1][1],2))))
		totalDistance += dist
		if(debug):
			print(points[i],location[points[i]],"Dist:",dist)
		currentPos = points[i]
		waypoints.append(location[points[i]][0])
	routes.append([totalDistance,waypoints])
	if(debug):
		print(">>> Total distance:",totalDistance)
		print("########################################################")
		
	

#searching route for the smallest distance
minIndex = 0
minDist = routes[0]
for i in range(len(routes)):
	if routes[i] < minDist:
		minDist = routes[i]
		minIndex = i
print("###################### F I N A L #######################")
print("########################################################")
print("Minimum distance is",routes[minIndex][0])

print("Shortest route for your destination:")
print(routes[minIndex][1])
print('--------------------------------------------------------',
	  '\nThe program is ended')
