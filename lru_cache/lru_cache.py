class DLinkedNode:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}  # key -> node
        self.capacity = capacity
        self.size = 0

        # Dummy head and tail to avoid null checks
        self.head = DLinkedNode()
        self.tail = DLinkedNode()

        self.head.next = self.tail
        self.tail.prev = self.head

    # Add node right after head
    def _add_node(self, node):
        node.prev = self.head
        node.next = self.head.next

        self.head.next.prev = node
        self.head.next = node

    # Remove an existing node
    def _remove_node(self, node):
        prev = node.prev
        nxt = node.next

        prev.next = nxt
        nxt.prev = prev

    # Move a node to the head
    def _move_to_head(self, node):
        self._remove_node(node)
        self._add_node(node)

    # Pop the tail (LRU)
    def _pop_tail(self):
        lru = self.tail.prev
        self._remove_node(lru)
        return lru

    def get(self, key: int) -> int:
        node = self.cache.get(key)
        if not node:
            return -1
        # Move the accessed node to the front
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)

        if not node:
            # Create a new node
            newNode = DLinkedNode(key, value)
            self.cache[key] = newNode
            self._add_node(newNode)
            self.size += 1

            if self.size > self.capacity:
                # Remove the LRU
                tail = self._pop_tail()
                del self.cache[tail.key]
                self.size -= 1
        else:
            # Update the value and move to head
            node.value = value
            self._move_to_head(node)
