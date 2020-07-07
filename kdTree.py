import os
import statistics
import math
import numpy as np

class Node:
    def __init__(self, point=[], left=None, right=None, splitaxis=None,median=None):
        self.left = left
        self.right = right
        self.point =point
        self.splitaxis = splitaxis
        self.median = median

class kdTree:
    def __init__(self, dimension):
        self.dimension = dimension
        self.root = None

    def insert(self, points):
        self.root = self.__buildKdTree(points, 0)

    def __buildKdTree(self, points, depth):
        if not len(points):
            return None

        splittingaxis = depth % self.dimension
        if len(points) == 1:
            return Node(points[0])
        elif len(points) != 0 and len(points) != 1:
            points.sort(key=lambda point: point[splittingaxis])
            splittingList = [point[splittingaxis] for point in points]
            median = statistics.median(splittingList)
            P1 = [point for point in points if point[splittingaxis] <= median ]
            P2 = [point for point in points if point[splittingaxis] > median]
            left = self.__buildKdTree(P1,depth+1)
            right = self.__buildKdTree(P2,depth+1)
            newNode = Node([],left,right,splittingaxis,median)
            return newNode

    def getNNP(self, testPoint):
        self.nearestDistance = math.inf
        self.nearestPoint = None
        self.__searchNNP(self.root, testPoint)
        return self.nearestPoint

    def __searchNNP(self, treeNode, testPoint ):
        if treeNode:
            if not treeNode.left and not treeNode.right:
                point_a = np.array(testPoint)
                point_b = np.array(treeNode.point)
                distance = np.linalg.norm(point_a-point_b)
                if distance < self.nearestDistance:
                    self.nearestDistance = distance
                    self.nearestPoint = point_b
            else:
                if testPoint[treeNode.splitaxis] - self.nearestDistance <= treeNode.median:
                    first_left = True
                else:
                    first_left = False

                if first_left:
                    if testPoint[treeNode.splitaxis] - self.nearestDistance <= treeNode.median:
                        self.__searchNNP(treeNode.left, testPoint)
                    if testPoint[treeNode.splitaxis] + self.nearestDistance > treeNode.median:
                        self.__searchNNP(treeNode.right, testPoint)
                else:
                    if testPoint[treeNode.splitaxis] + self.nearestDistance > treeNode.median:
                        self.__searchNNP(treeNode.right, testPoint)
                    if testPoint[treeNode.splitaxis] - self.nearestDistance <= treeNode.median:
                        self.__searchNNP(treeNode.left, testPoint)
                
def testKdTree():
    reader = open('UnitSquare1000.txt', 'r')
    fileData = list(reader)
    points = [line.split(' ') for line in fileData]
    points = [[ float(coord) for coord in point ] for point in points ]
    tree = kdTree(2)
    tree.insert(points)
    nearestPoint = tree.getNNP([0.5,0.7])
    print(nearestPoint)

testKdTree()