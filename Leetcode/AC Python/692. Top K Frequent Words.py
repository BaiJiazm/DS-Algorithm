class Solution:
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        coll = collections.Counter(words)
        heap = [(-freq, word) for word, freq in coll.items()]
        heapq.heapify(heap)
        return [heapq.heappop(heap)[1] for _ in range(k)]