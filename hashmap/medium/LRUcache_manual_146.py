class Node:
    def __init__(self, key:int, value:int):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity:int):
        self.capacity = capacity
        self.cache = {}
        self.size = 0
        self.head = None
        self.tail = None

    def _remove(self, node:Node):
        if node.prev:
            node.prev.next = node.next
        else:
            self.head = node.next

        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev

    def _insert_front(self, node:Node):
        node.prev = None
        node.next = self.head

        if self.head:
            self.head.prev = node
        self.head = node

        if not self.tail:
            self.tail = node

    def get(self, key:int)->int:
        if key not in self.cache:
            return -1
        node = self.cache[key]

        self._remove(node)
        self._insert_front(node)
        return node.value

    def put(self, key:int, value:int)->None:
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self._remove(node)
            self._insert_front(node)
            return

        if self.size == self.capacity:
            lru = self.tail
            self._remove(lru)
            del self.cache[lru.key]
            self.size -= 1

        new_node = Node(key,value)
        self._insert_front(new_node)
        self.cache[key] = new_node
        self.size += 1







