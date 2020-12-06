# I'm implementing CS50 problem set 1 'cash' in python.
# This problem is also named the coin change problem

# Function to dreplace the dots in input numbers
# so i can test if it is a valid number
def rreplace(s, old, new, occurrence):
    li = s.rsplit(old, occurrence)
    return new.join(li)


# Prompt the user to enter a number.
# If input is negative or not a number, keep asking
while True:
    dollars = input("How much: ")
    temp = rreplace(dollars, '.', '', dollars.count('.'))
    if not temp.isdigit() or float(dollars) < 0:
        continue
    
    else:
        break
    
# In python 3, input is a string so i convert it to float
# To handle float imprecision i round it to the 100th
change = round(float(dollars) * 100)

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

