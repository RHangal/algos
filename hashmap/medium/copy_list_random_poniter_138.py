A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Solution: 2 pass hash table approach, first pass will create all the nodes and store in a map from original->copy. The second pass will assign the next and random for each copied node using the map.

The resulting time and space complexity will be O(n).

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        table = {}

        #First pass: clone all node
        curr = head
        while curr:
            table[curr] = Node(curr.val)
            curr = curr.next

        #Second pass: assign next and random pointers
        curr = head
        while curr:
            copy = table[curr]
            copy.next = table.get(curr.next)
            copy.random = table.get(curr.random)
            curr = curr.next

        return table[head]

