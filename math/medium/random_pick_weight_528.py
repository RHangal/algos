You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

import bisect
import random

class Solution:

    def __init__(self, w: List[int]):
        self.prefixmap = []
        prefixsum = 0
        for weight in w:
            prefixsum+=weight
            self.prefixmap.append(prefixsum)
        self.total = prefixsum
        

    def pickIndex(self) -> int:
        target = random.randint(1,self.total)

        return bisect.bisect_left(self.prefixmap, target)
