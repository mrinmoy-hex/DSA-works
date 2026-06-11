nums = [3, 0, 1]
n = len(nums)

temp = [i for i in range(n+1)]
print(temp)

val:int = (set(temp) - set(nums)).pop()
print("The missing number is: ", val)