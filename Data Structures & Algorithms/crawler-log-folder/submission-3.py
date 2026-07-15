class Solution:
    def minOperations(self, logs: List[str]) -> int:
        steps = 0
        for i in logs:
            if i == '../':
                steps = max(0, steps-1)
            elif i == './':
                pass
            else:
                steps = steps + 1

        return steps
