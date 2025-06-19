Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

class SparseVector:
    def __init__(self, nums: List[int]):
        self.data = {index: num for index,num in enumerate(nums) if num != 0}

    def dotProduct(self, vec: 'SparseVector') -> int:

        if len(self.data) > len(vec.data):
            return vec.dotProduct(self)

        res = 0

        for index, num in self.data.items():
            if index in vec.data:
                res+=(num * vec.data[index])

        return res

