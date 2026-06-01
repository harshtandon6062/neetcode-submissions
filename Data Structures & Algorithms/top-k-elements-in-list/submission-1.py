class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for num in nums:
            freq[num] += 1
        n = len(freq)
        res = []
        keys = list(freq.keys())
        values = list(freq.values())
        for i in range(k):
            res.append((values[i],keys[i]))
        heapq.heapify(res)
        for i in range(k,n):
            if values[i] > res[0][0]:
                heapq.heappop(res)
                heapq.heappush(res,(values[i],keys[i]))
        return [x[1] for x in res]


        