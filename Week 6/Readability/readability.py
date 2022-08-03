# TODO
from cs50 import get_string

W = 0
S = 0
length = 0
text = get_string("Text: ")

for i in range(len(text)):

    # check if that is a spcae
    if text[i] == ' ':
        W += 1
        continue

    # check if that is a "." or "!" or "?"
    if text[i] in ['.', '?', '!']:
        S += 1
        continue

    # check if that is a alphabet
    if text[i].isupper() or text[i].islower():
        length += 1

W += 1

# calculate the score
index = 0.0588 * (length / W * 100) - 0.296 * (S / W * 100) - 15.8

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    index = int(round(index))
    print(f"Grade {index}")