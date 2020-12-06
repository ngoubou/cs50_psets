
# Coleman-Liau index implementation :
# Compute the approximate grade level needed to comprehend some text

# I define 3 functions that i'll use in the index formula

def count_letters(text):
    length = len(text)
    letters = 0

    for i in range(length):
        if not text[i].isspace() and text[i].isalnum():
            letters += 1

    return letters


def count_words(text):
    length = len(text)
    words = 0

    for i in range(length):
        if text[i].isspace() and not text[i].isalnum():
            words += 1

    return words + 1


def count_sentences(text):
    length = len(text)
    sent = 0

    for i in range(length):
        if text[i] == '.' or text[i] == '?' or text[i] == '!':
            sent += 1

    return sent


# Prompt user to enter a text
text = input("Text: ")

# Letters and sentences per 100 words
l = (100 * count_letters(text)) / count_words(text)
s = (100 * count_sentences(text)) / count_words(text)

# Coleman-Liau index formula
index = round(0.0588 * l - 0.296 * s - 15.8)

if index >= 16:
    print("Grade 16+")

elif index < 1:
    print("Before Grade 1")

else:
    print("Grade " + str(index))
