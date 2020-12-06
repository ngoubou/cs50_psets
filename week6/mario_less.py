# Program to recreate the Super Mario right-aligned pyramid.

# Replace dots in input numbers
# so i can test if it is a valid number
def rreplace(s, old, new, occurrence):
    li = s.rsplit(old, occurrence)
    return new.join(li)
    
    
# Get user input
while True:
    height = input("Height: ")
    
    temp = rreplace(height, '.', '', height.count('.'))
    if not temp.isdigit() or int(height) < 1 or int(height) > 8:
        continue
    else:
        break
    
height = int(height)    

for i in range(height):
    
    for j in list(range(height - 1 - i, 0, -1)):
        print(' ', end='')
        
    for k in range(i + 1, 0, -1):
        print("#", end='')
    
    print('\n', end='')
