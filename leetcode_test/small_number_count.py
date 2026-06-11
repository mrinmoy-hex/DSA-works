# nums = [8, 1, 2, 2, 3]
nums = [7, 7, 7, 7]

arr = []

end = len(nums)

for i in range(end):
    counter = 0
    
    for j in range(end):
        if j != i:
            if nums[j] < nums[i]:
                counter += 1        # count everything first
    
    # after counting smaller append it to arr
    arr.append(counter)

print(arr)