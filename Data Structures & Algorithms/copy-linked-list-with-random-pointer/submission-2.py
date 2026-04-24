"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        nodeMap = {}
        itr = head
        while(itr):
            nodeMap[itr] = Node(itr.val)
            itr = itr.next

        itr = head
        while(itr):
            
            nodeMap[itr].next = nodeMap.get(itr.next, None)
            nodeMap[itr].random = nodeMap.get(itr.random, None)
            itr = itr.next

        return nodeMap[head]
            
        