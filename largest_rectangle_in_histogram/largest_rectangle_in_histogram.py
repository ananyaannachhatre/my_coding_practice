class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0
        i = 0
        n = len(heights)
        
        while i < n:
            if not stack or heights[i] >= heights[stack[-1]]:
                stack.append(i)
                i += 1
            else:
                top = stack.pop()
                if not stack:
                    max_area = max(max_area, heights[top] * i)
                else:
                    max_area = max(max_area, heights[top] * (i - stack[-1] - 1))
        
        while stack:
            top = stack.pop()
            if not stack:
                max_area = max(max_area, heights[top] * i)
            else:
                max_area = max(max_area, heights[top] * (i - stack[-1] - 1))
        
        return max_area
        