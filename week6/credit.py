
# Check if a credit card is valid using Luhn's algorithm

def rreplace(s, old, new, occurrence):
    li = s.rsplit(old, occurrence)
    return new.join(li)
    

while True:
    card = input("Number: ")
    temp = rreplace(card, '.', '', card.count('.'))
    if not temp.isdigit():
        continue
    else:
        break

card = int(card)
card_bis = card

prod_sum = 0
sum_last = 0

while card:
    last_digit = card % 10
    # I convert it to int so it doesnt produce floating point
    # that will change the algorithm behaviour
    card = int(card / 10)
    not_last = card % 10
    deux = not_last * 2
    sum_not_last = 0
    
    while deux > 0:
        digit = deux % 10
        deux = int(deux / 10)
        sum_not_last += digit
    
    card = int(card / 10)
    prod_sum += sum_not_last
    sum_last += last_digit
    
total_sum = sum_last + prod_sum  

# Convert total_sum to char
total_sum = str(total_sum)

# Convert input to char
card = str(card_bis)    
    
    
# VISA
if (len(card) == 13 or len(card) == 16) and card[0] == '4' and total_sum[1] == '0':
    
    print("VISA")
    
# AMEX
elif len(card) == 15 and ((card[0] == '3' and card[1] == '4') or 
                          (card[0] == '3' and card[1] == '7')) and total_sum[1] == '0':
    
    print("AMEX")

# MASTERCARD
elif len(card) == 16 and ((card[0] == '5' and card[1] == '1') or
                          (card[0] == '5' and card[1] == '2') or (card[0] == '5' and card[1] == '3') or
                          (card[0] == '5' and card[1] == '4') or (card[0] == '5' and card[1] == '5')) and total_sum[1] == '0':
    
    print("MASTERCARD")
    
else:
    print("INVALID")
    
