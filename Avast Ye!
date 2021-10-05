#You are a part of a pirate ship that survives by looting islands. Your crew has the
#responsibility of devising a plan to efficiently rob the islands where each island is divided
#into smaller land parts due to the river flowing through it. Each land part is joined to another
#land part by a bridge. (i.e. one land part can be directly connected to another land part by
#using almost 1 bridge). After thorough discussion, the crew came to a conclusion that the
#only way to carry out the loot successfully is to loot only those islands in which all the
#bridges are covered only once. Given the topology of the island, your job is to analyze the
#island and tell whether the pirates should loot the given island or not.

#INPUT:
#The first line of the input asks for the ‘Number of Islands’
#Second line asks for the number of land parts (nodes)
#And based on the number of land parts (nodes) each subsequent line gives the details
#about the number of degrees of those land parts

#OUTPUT:
#"island can be looted" or "island cannot be looted"

#SAMPLE INPUT :
##1 - 2
##2 - 3
##3 - 2 2 3
##4 - 2 1 3
##5 - 2 1 2
##6 - 1
##7 - 0

##1 denotes the ‘number of islands’
##2 denotes the ‘ number of land parts/nodes'
##3 first digit, in this case ‘2’ denotes the degrees of the ‘first’ land part and following digits,
#‘2’ & ‘3’ denote the land parts, first land part is connected to
##4 first digit, in this case ‘2’ denotes the degrees of the ‘second’ land part and following
#digits, ‘1’ & ‘3’ denote the land parts, second land part is connected to
##5 first digit, in this case ‘2’ denotes the degrees of the ‘second’ land part and following
#digits, ‘1’ & ‘2’ denote the land parts, third land part is connected to
##6 is the number of land parts for the second island because we chose ‘2’ as an input in #1
##7 in this case, second island has only one land part/node therefore it’s degree can’t be
#more than (degree-1) i.e. ‘0’.

#SAMPLE OUTPUT:
#"island can be looted"



# Python program to check if a given island can be looted
or not
# Complexity: O(V+E)
from collections import defaultdict
# This class represents a undirected graph using
adjacency list representation
class island:
 def __init__(self, vertices):
 self.V = vertices # No. of vertices
 self.island = defaultdict(list) # default
dictionary to store graph
 # function to add an edge to graph
 def addEdge(self, u, v):
 self.island[u].append(v)
 self.island[v].append(u)
 # A function used by isConnected
 def DFSUtil(self, v, visited):
 # Mark the current node as visited
 visited[v] = True
 # Recur for all the vertices adjacent to this
vertex
 for i in self.island[v]:
 if visited[i] == False:
 self.DFSUtil(i, visited)
 '''Method to check if all non-zero degree vertices are
 connected. It mainly does DFS traversal starting from
 node with non-zero degree'''
 def isConnected(self):
 # Mark all the vertices as not visited
 visited = [False] * (self.V)
 # Find a vertex with non-zero degree
 for i in range(self.V):
 if len(self.island[i]) > 1:
 break
 # If there are no edges in the graph, return true
 if i == self.V - 1:
 return True
 # Start DFS traversal from a vertex with non-zero
degree
 self.DFSUtil(i, visited)
 # Check if all non-zero degree vertices are
visited
 for i in range(self.V):
 if visited[i] == False and len(self.island[i])
> 0:
 return False
 return True
 '''The function returns one of the following values
 0 --> If grpah is not Eulerian
 1 --> If graph has an Euler path (Semi-Eulerian)
 2 --> If graph has an Euler Circuit (Eulerian) '''
 def canLoot(self):
 # Check if all non-zero degree vertices are
connected
 if self.isConnected() == False:
 return 0
 else:
 # Count vertices with odd degree
 odd = 0
 for i in range(self.V):
 if len(self.island[i]) % 2 != 0:
 odd += 1
 '''If odd count is 2, then semi-eulerian.
 If odd count is 0, then eulerian
 If count is more than 2, then graph is not
Eulerian
 Note that odd count can never be 1 for
undirected graph'''
 if odd == 0:
 return 2
 elif odd == 2:
 return 1
 elif odd > 2:
 return 0
 # Function to run test cases
 def test(self):
 res = self.canLoot()
 if res == 0:
 print("island cannot be looted")
 elif res == 1:
 print("island can be looted")
 else:
 print("island can be looted")
# # Let us create and test graphs shown in above figures
# THESE COMMENTS ARE FOR REFERRAL, SO THAT EITHER ME
ANYONE ELSE CAN GET A PROPER UNCDERSTANDING OF WHAT THIS
CODE ACTUALLY DOES
# g1 = Graph(5)
# g1.addEdge(1, 0)
# g1.addEdge(0, 2)
# g1.addEdge(2, 1)
# g1.addEdge(0, 3)
# g1.addEdge(3, 4)
# g1.test()
#
# g2 = Graph(5)
# g2.addEdge(1, 0)
# g2.addEdge(0, 2)
# g2.addEdge(2, 1)
# g2.addEdge(0, 3)
# g2.addEdge(3, 4)
# g2.addEdge(4, 0)
# g2.test()
#
# g3 = Graph(5)
# g3.addEdge(1, 0)
# g3.addEdge(0, 2)
# g3.addEdge(2, 1)
# g3.addEdge(0, 3)
# g3.addEdge(3, 4)
# g3.addEdge(1, 3)
# g3.test()
#
# # Let us create a graph with 3 vertices
# # connected in the form of cycle
# g4 = Graph(3)
# g4.addEdge(0, 1)
# g4.addEdge(1, 2)
# g4.addEdge(2, 0)
# g4.test()
# # Let us create a graph with all veritces
# # with zero degree
# g5 = Graph(3)
# g5.test()
# Automation of the input process
print("start")
num_island = int(input())
island_lst = [None]*num_island
for num in range(num_island):
 num_nodes = int(input())
 island_lst[num] = island(num_nodes)
 for node_i in range(num_nodes):
 land_part_lst = input().split(" ")
 degree = int(land_part_lst[0])
 for j in range(1,degree):
 land_part_num = int(land_part_lst[j])
 island_lst[num].addEdge(node_i,land_part_num)
 island_lst[num].test()
