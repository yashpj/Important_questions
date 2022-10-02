class Solution(object):
    def find132pattern(self, nums):
        smallest = float('inf')
        stack = []
        for i in nums:
            while stack and i >= stack[-1][-1]:
                stack.pop()
            if stack and i > stack[-1][0]:
                return True
            stack.append((smallest,i)) 
            smallest = min(smallest,i)
        return False
            
            