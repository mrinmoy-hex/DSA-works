nums = [4, 3, 2, 7, 8, 2, 3, 1]

n = len(nums)

missing_arr = list(set(range(1, n + 1)) - set(nums))

print("Input:", nums)
print("Output:", missing_arr)