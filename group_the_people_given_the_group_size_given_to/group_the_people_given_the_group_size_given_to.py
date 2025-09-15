from typing import List

class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        group_map = {}
        
        for i, size in enumerate(groupSizes):
            if size not in group_map:
                group_map[size] = []
            group_map[size].append(i)
        
        result = []
        for size, people in group_map.items():
            for i in range(0, len(people), size):
                result.append(people[i:i+size])
        
        return result