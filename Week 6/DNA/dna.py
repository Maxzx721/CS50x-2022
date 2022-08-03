import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    personDNA = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for person in reader:
            personDNA.append(person)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        personSequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    longestMatch = []
    if len(personDNA[0]) == 9:
        strx = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']
        for i in range(0, 8):
            longestMatch.append(str(longest_match(personSequence, strx[i])))
    else:
        strx = ['AGATC', 'AATG', 'TATC']
        for i in range(0, 3):
            longestMatch.append(str(longest_match(personSequence, strx[i])))

    # TODO: Check database for matching profiles
    flag = 0
    for i in range(len(personDNA)):
        if len(personDNA[0]) == 9:
            if personDNA[i]["AGATC"] == longestMatch[0] and personDNA[i]["TTTTTTCT"] == longestMatch[1] and personDNA[i]["AATG"] == longestMatch[2] and personDNA[i]["TCTAG"] == longestMatch[3] and personDNA[i]["GATA"] == longestMatch[4] and personDNA[i]["TATC"] == longestMatch[5] and personDNA[i]["GAAA"] == longestMatch[6] and personDNA[i]["TCTG"] == longestMatch[7]:
                print(personDNA[i]["name"])
                flag = 1
                break
        elif personDNA[i]["AGATC"] == longestMatch[0] and personDNA[i]["AATG"] == longestMatch[1] and personDNA[i]["TATC"] == longestMatch[2]:
            print(personDNA[i]["name"])
            flag = 1
            break

    if flag == 0:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
