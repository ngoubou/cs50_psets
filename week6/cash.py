# I'm implementing CS50 problem set 1 'cash' in python.
# This problem is also named the coin change problem

# Prompt the user to enter a number.
# In python 3, input is a string so i convert it to float
dollars = float(input("How much: "))

# To handle float imprecision i convert it to an integer and round it
change = round(dollars * 100)

# I initialize a variable that will keep track of
# the number of times the loop is executed.
# This number represents the minimum of coins for change
coins = 0

# Create an array that'll store the coins face values
array = [25, 10, 5, 1]

# Iterate through the array and subtract the biggest value
# As long as the change is greater or equaled to the largest coin
for i in range(len(array)):
    while change >= array[i]:
        change = change - array[i]
        coins = coins + 1

print("number of coins is " + str(coins))

