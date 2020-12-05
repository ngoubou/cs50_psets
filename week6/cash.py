# I'm implementing CS50 problem set 1 'cash' in python.
# This problem is also named the coin change problem

# Prompt the user to enter a number.
# In python 3, input is a string so i convert it to float
dollars = float(input("How much:"))

# To handle float imprecision i convert it to an integer and round it
change = round(dollars * 100)

# I initialize a variable that will keep track of 
# the number of times the loop is executed.
# This number represents the minimum of coins for change
coins = 0

while change >= 25:
    change = change - 25
    coins = coins + 1
    
while change >= 10:
    change = change - 10
    coins = coins + 1
    
while change >= 5:
    change = change - 5
    coins = coins + 1
    
while change >= 1:
    change = change - 1
    coins = coins + 1    

print("number of coins is " + str(coins))

