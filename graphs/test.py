#TEST SCRIPT FOR CS182 HOMEWORK3
#usage: python3 test.py
#assumes executable graph_test exists

import os
import sys
import subprocess

def dotest(description, testnum):
    print(description)
    result = subprocess.call([graph_test, testnum], cwd=cur)
    if result >= 0:
        print("points: ", result)
        return result
    else:
        print("crashed with error ", result)
        print("points: 0")
        return 0

if __name__ == "__main__":

    points = 0

    cur = os.path.expanduser('~/graphs/')

    graph_test = cur + 'graph_test'

    print("curremt directory for the python script is ", cur)

    print("testing graph g1 with 1 vertex - LIST")

    points = dotest("g1 makeGraph + numVerts", "0")

    points += dotest("g1 addEdge with invalid target", "1")

    points += dotest("testing g1 edge with invalid target", "2")

    points += dotest("testing g1 successors", "3")

    points += dotest("testing g1 predecessors", "4")

    points += dotest("testing g1 disposeGraph (doesn't crash)", "5")    

    print("testing graph g2 - complete graph with 4 vertices - MATRIX")

    points += dotest("testing g2 makeGraph + numVerts", "6")

    points += dotest("testing g2 addEdge + edge", "7")

    points += dotest("testing g2 vertex 0 successors", "8")

    points += dotest("testing g2 vertex 1 successors", "9")

    points += dotest("testing g2 vertex 2 successors", "10")

    points += dotest("testing g2 vertex 3 successors", "11")
    
    points += dotest("testing g2 vertex 0 predecessors", "12")

    points += dotest("testing g2 vertex 1 predecessors", "13")

    points += dotest("testing g2 vertex 2 predecessors", "14")

    points += dotest("testing g2 vertex 3 predecessors", "15")

    points += dotest("testing g2 delEdge + edge", "16")

    print("testing graph g3 with 5 vertices - LIST")
    
    points += dotest("testing g3 makeGraph + numVerts", "17")

    points += dotest("testing g3 addEdge + edge", "18")

    points += dotest("testing g3 delEdge", "19")

    points += dotest("testing g3 delEdge edge doesn't exist", "20")

    points += dotest("testing g3 vertex 0 successors", "21")
    
    points += dotest("testing g3 vertex 1 successors", "22")

    points += dotest("testing g3 vertex 2 successors", "23")

    points += dotest("testing g3 vertex 3 successors", "24")

    points += dotest("testing g3 vertex 4 successors", "25")

    points += dotest("testing g3 vertex 0 predecessors", "26")

    points += dotest("testing g3 vertex 1 predecessors", "27")

    points += dotest("testing g3 vertex 2 predecessors", "28")

    points += dotest("testing g3 vertex 3 predecessors", "29")
     
    points += dotest("testing g3 vertex 4 predecessors", "30")

    points += dotest("testing g2 clone as list", "31")

    points += dotest("testing g2 clone as list", "32")
    
    points += dotest("testing g3 clone as matrix", "33")

    points += dotest("testing g3 clone as matrix", "34")
        
    print("score: ", points)

    print("max score: ", 45)

    print("+5 points for compilation, conventions, pledge, etc.")

    
