d = {"a": 3, "b": 1}

for k, v in d.items():   # k=key, v=value
    print(k, v)

d.keys()    # just keys
d.values()  # just values

nums = [3, 1, 2]
sorted(nums)   # returns [1, 2, 3] — nums still [3,1,2]
nums.sort()    # returns None — nums is now [1, 2, 3]