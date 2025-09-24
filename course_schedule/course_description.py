class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        for dest, src in prerequisites:
            graph[src].append(dest)
        
        result = []
        
        # 0 -> unvisited, 1 -> visiting, 2 -> visited
        visited = [0] * numCourses
        
        def dfs(course):
            if visited[course] == 1:  
                return False
            if visited[course] == 2:  
                return True
            
            visited[course] = 1
        
            for next_course in graph[course]:
                if not dfs(next_course):
                    return False
            
            visited[course] = 2
            result.append(course)
            return True
        
        for course in range(numCourses):
            if visited[course] == 0:  
                if not dfs(course):
                    return []  
        
        return result[::-1]
        