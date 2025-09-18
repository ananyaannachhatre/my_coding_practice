import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        # Step 1: Count frequency of each character
        freq = Counter(s)

        # Step 2: Check if reorganization is possible
        max_freq = max(freq.values())
        if max_freq > (len(s) + 1) // 2:
            return ""

        # Step 3: Build a max-heap (Python's heapq is min-heap, so we use negative counts)
        max_heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(max_heap)

        result = []
        prev_count, prev_char = 0, ''

        # Step 4: Greedily build the result string
        while max_heap:
            count, char = heapq.heappop(max_heap)
            result.append(char)

            # Push back the previous character if it still has remaining count
            if prev_count < 0:
                heapq.heappush(max_heap, (prev_count, prev_char))

            # Prepare for the next iteration
            prev_count = count + 1  # since count is negative, we add 1
            prev_char = char

        return ''.join(result)