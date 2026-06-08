nums = [3,2,3]
target = 6

hash_map = {}   # val, index

for index, val in enumerate(nums):
    diff = target - val

    if diff in hash_map:
        print([index, hash_map[diff]])
    
    hash_map[val] = index