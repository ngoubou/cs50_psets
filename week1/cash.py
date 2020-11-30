# i'm implementing cs50 problem set 1 'cash' in python
# this problem is also named the coin change problem

# prompt the user to enter a number
# in python (3), input is a string so i convert it to float
dollars = float(input("How much:"))
# to handle float imprecision i convert it to an integer and round it
change = round(dollars * 100)
# i initialize a ariable that will keep track of 
# the number of times the loop is executed
# this number represents the minimum of coins for change
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
