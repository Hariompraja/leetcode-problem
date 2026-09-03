class Solution(object):
    def topKFrequent(self, nums, k):
        freq = {}

        for x in nums:
            freq[x] = freq.get(x,0)+1

        arr = []

        for x in freq:
            arr.append((freq[x], x))

        arr.sort(reverse = True)

        ans = []

        for i in range(k):
            ans.append(arr[i][1])

        return ans
        