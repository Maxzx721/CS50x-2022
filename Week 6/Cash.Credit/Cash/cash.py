# TODO
from cs50 import get_float


def main():
    # Ask how many cents the customer is owed
    cents = get_cents() * 100

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


def get_cents():
    while True:
        # get user's input
        cents = get_float("Change owed: ")
        if cents >= 0:
            break
    return cents


def calculate_quarters(cents):
    # return the number of quarters
    return int(cents / 25)


def calculate_dimes(cents):
    # return the number of dimes
    return int(cents / 10)


def calculate_nickels(cents):
    # return the number of nickels
    return int(cents / 5)


def calculate_pennies(cents):
    # return the number of pennies
    return int(cents)


main()
