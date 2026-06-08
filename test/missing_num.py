nums = [3, 0, 1]

n = len(nums)

expected_sum = n * (n + 1) // 2
actual_sum = sum(nums)

missing = expected_sum - actual_sum
print("The missing number is:", missing)