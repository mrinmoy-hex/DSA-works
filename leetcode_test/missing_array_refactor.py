nums = [4, 3, 2, 7, 8, 2, 3, 1]

set_nums = set(nums)

ret = []

for i in range(1, len(nums) + 1):
    if i not in set_nums:
        ret.append(i)

# ret = [i for i in range(1, len(nums) + 1) if i not in set_nums]

print(ret)