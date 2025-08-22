class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for num in nums:
            freq[num] += 1
        
        min_heap = []

        for num, frequency in freq.items():
            if len(min_heap) < k:
                heapq.heappush(min_heap, (frequency, num))
            elif frequency > min_heap[0][0]:
                heapq.heapreplace(min_heap, (frequency, num))
        return [num for frequency, num in min_heap]
