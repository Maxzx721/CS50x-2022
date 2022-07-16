# Lab 2: Scrabble
## Background
In the game of [Scrabble](https://scrabble.hasbro.com/en-us/rules), players create words to score points, and the number of points is the sum of the point values of each letter in the word.

| A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |

For example, if we wanted to score the word `Code`, we would note that in general Scrabble rules, the `C` is worth `3` points, the `o` is worth `1` point, the `d` is worth `2` points, and the `e` is worth `1` point. Summing these, we get that `Code` is worth `3 + 1 + 2 + 1 = 7` points.

## Implementation Details
Complete the implementation of `scrabble.c`, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

- Notice that we’ve stored the point values of each letter of the alphabet in an integer array named `POINTS`.
- For example, `A` or `a` is worth 1 point (represented by `POINTS[0]`), `B` or `b` is worth 3 points (represented by `POINTS[1]`), etc.
- Notice that we’ve created a prototype for a helper function called `compute_score()` that takes a string as input and returns an `int`. Whenever we would like to assign point values to a particular word, we can call this function. Note that this prototype is required for C to know that `compute_score()` exists later in the program.
- In main(), the program prompts the two players for their words using the `get_string()` function. These values are stored inside variables named `word1` and `word2`.
- In `compute_score()`, your program should compute, using the `POINTS` array, and return the score for the string argument. Characters that are not letters should be given zero points, and uppercase and lowercase letters should be given the same point values.
  - For example, `!` is worth `0` points while `A` and `a` are both worth `1` point.
  - Though Scrabble rules normally require that a word be in the dictionary, no need to check for that in this problem!
- In main(), your program should print, depending on the players’ scores, `Player 1 wins!`, `Player 2 wins!`, or `Tie!`.
### Hints
- You may find the functions `isupper()` and `islower()` to be helpful to you. These functions take in a character as the argument and return a boolean.
- To find the value at the `n`th index of an array called `arr`, we can write `arr[n]`. We can apply this to strings as well, as strings are arrays of characters.
- Recall that computers represent characters using [ASCII](https://www.asciitable.com/), a standard that represents each character as a number.

<details>
<summary>Not sure how to solve?</summary>

  [Scrabble - Solution - CS50 Labs 2020](https://youtu.be/USiLkXuXJEg)
</details>

## How to Test Your Code
Your program should behave per the examples below.

```
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```

```
$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
```

```
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

```
$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
```

Execute the below to evaluate the correctness of your code using `check50`. But be sure to compile and test it yourself as well!
```
check50 cs50/labs/2022/x/scrabble
```
Execute the below to evaluate the style of your code using `style50`.
```
style50 scrabble.c
```

## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/labs/2022/x/scrabble
```

-check50
- [x] :) scrabble.c exists
- [x] :) scrabble.c compiles
- [x] :) handles letter cases correctly
- [x] :) handles punctuation correctly
- [x] :) correctly identifies 'Question?' and 'Question!' as a tie
- [x] :) correctly identifies 'drawing' and 'illustration' as a tie
- [x] :) correctly identifies 'hai!' as winner over 'Oh,'
- [x] :) correctly identifies 'COMPUTER' as winner over 'science'
- [x] :) correctly identifies 'Scrabble' as winner over 'wiNNeR'
- [x] :) correctly identifies 'pig' as winner over 'dog'
:) correctly identifies 'Skating!' as winner over 'figure?'

-sytle50
- [x] Looks good!