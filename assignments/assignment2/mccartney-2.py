# https://www.tutorialspoint.com/python_data_structure/python_linked_lists.htm
import random

class Node:
    def __init__(self, node, value):
        self.node = node
        self.nextNode = None
        value = random.randint(0,50)
        self.nodeValue = value
    def createNode(self):
        newNode = Node(self.node, self.nodeValue)
        return newNode

class Buffer:
    def __init__(self):
        self.headNode = None
        self.tailNode = None

    def nodeBuffer(self):
        node = self.headNode
        print("node: "+ node)
        while node is not None:
            print(node)
            node = node.nextNode

    def newHeadNode(self, newNode):
        NextHeadNode = Node(newNode)
        self.headNode = NextHeadNode

    def removeTailNode(self, nodeList):
        emptyNode = self.node
        nodeList.remove(emptyNode)


def consumer(totalNodes):
    oldNode = Buffer.removeTailNode
    totalNodes -= 1
    return totalNodes

def producer(totalNodes):
    newNode = Node.createNode()
    addedNode = Buffer.newHeadNode(newNode)
    totalNodes += 1
    return totalNodes, addedNode

def main():
    buffer = Buffer()
    buffer.headNode = Node('1')
    nextNode = Node('2')
    buffer.tailNode = nextNode
    
    buffer.tailNode = Node('3')

    newHead = buffer.headNode.nextNode

    n = buffer.newHeadNode('4')

    print(n)