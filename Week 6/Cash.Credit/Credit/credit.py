# TODO
from cs50 import get_int

temp = 0
digits = [0] * 16
number = get_int("Number: ")

for i in range(len(digits)):

    # store every digits into array "digits"
    digits[i] = number % 10
    number = int(number / 10)

for i in range(8):

    # calculate every other digit
    digitTimesTwo = digits[i * 2 + 1] * 2

    # if the result have 2 digit, then I break it down
    if digitTimesTwo / 10 != 0:
        temp += int(digitTimesTwo / 10)
        temp += digitTimesTwo % 10
    else:
        # simply add the result to "temp"
        temp += digitTimesTwo

for i in range(8):

    # add the digits that weren’t multiplied by 2
    temp += digits[i * 2]

# check if the last digit if 0 or not
if temp % 10 == 0:

    # check if it is AMEX
    if digits[14] == 3 and digits[13] in [4, 7]:
        print("AMEX")

    # check if it is MASTERCARD
    elif digits[15] == 5 and digits[14] in [1, 2, 3, 4, 5]:
        print("MASTERCARD")

    # check if it is VISA
    elif 4 in [digits[15], digits[12]]:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
