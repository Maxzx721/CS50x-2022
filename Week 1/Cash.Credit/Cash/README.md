# Cash
## Implementation Details
In `cash.c`, we’ve implemented most (but not all!) of a program that prompts the user for the number of cents that a customer is owed and then prints the smallest number of coins with which that change can be made. Indeed, `main` is already implemented for you. But notice how `main` calls several functions that aren’t yet implemented! One of those functions, `get_cents`, takes no arguments (as indicated by `void`) and returns an `int`. The rest of the functions all take one argument, an `int`, and also return an `int`. All of them currently return `0` so that the code will compile. But you’ll want to replace every `TODO` and `return 0`; with your own code. Specifically, complete the implementation of those functions as follows:

- Implement `get_cents` in such a way that the function prompts the user for a number of cents using `get_int` and then returns that number as an `int`. If the user inputs a negative `int`, your code should prompt the user again. (But you don’t need to worry about the user inputting, e.g., a string, as get_int will take care of that for you.) Odds are you’ll find a `do while` loop of help, as in [mario.c](https://cdn.cs50.net/2021/fall/lectures/1/src1/coins2.c)!
- Implement `calculate_quarters` in such a way that the function calculates (and returns as an `int`) how many quarters a customer should be given if they’re owed some number of `cents`. For instance, if cents is `25`, then `calculate_quarters` should return `1`. If `cents` is `26` or `49` (or anything in between, then `calculate_quarters` should also return `1`. If `cents` is `50` or `74` (or anything in between), then `calculate_quarters` should return `2`. And so forth.
- Implement `calculate_dimes` in such a way that the function calculates the same for dimes.
- Implement `calculate_nickels` in such a way that the function calculates the same for nickels.
- Implement `calculate_pennies` in such a way that the function calculates the same for pennies.

Note that, unlike functions that only have side effects, functions that return a value should do so explicitly with `return`! Take care not to modify the distribution code itself, only replace the given `TODO`s and the subsequent `return` value!  
Note too that, recalling the idea of abstraction, each of your calculate functions should accept any value of `cents` , not just those values that the greedy algorithm might suggest. If `cents` is 85, for example, `calculate_dimes` should return 8.

<details>
<summary>Hint</summary>

  - Recall that there are several sample programs in Week 1’s [Source Code](https://cdn.cs50.net/2021/fall/lectures/1/src1/) that illustrate how functions can return a value. You might find [discount1.c](https://cdn.cs50.net/2021/fall/lectures/1/src1/discount1.c) and [discount2.c](https://cdn.cs50.net/2021/fall/lectures/1/src1/discount2.c) insightful.
</details>

Your program should behave per the examples below.  
```
$ ./cash
Change owed: 41
4
```
```
$ ./cash
Change owed: -41
Change owed: foo
Change owed: 41
4
```

## How to Test Your Code
For this program, try testing your code manually–it’s good practice:

- If you input `-1`, does your program prompts you again?
- If you input `0`, does your program output `0?
- If you input `1`, does your program output `1` (i.e., one penny)?
- If you input `4`, does your program output `4` (i.e., four pennies)?
- If you input `5`, does your program output `1` (i.e., one nickel)?
- If you input `24`, does your program output `6` (i.e., two dimes and four pennies)?
- If you input `25`, does your program output `1` (i.e., one quarter)?
- If you input `26`, does your program output `2` (i.e., one quarter and one penny)?
- If you input `99`, does your program output `9` (i.e., three quarters, two dimes, and four pennies)?

You can also execute the below to evaluate the correctness of your code using `check50`. But be sure to compile and test it yourself as well!
```
check50 cs50/problems/2022/x/cash
```

<details>
<summary>Is check50 failing to compile your code?</summary>

  CS50x 2022’s version of Cash is quite different than CS50x 2021’s version. Last year’s version will **fail to compile** when checked by `check50` (but not necessarily if you run it yourself, assuming your file consists of legal C code) due to the fact that in this new version you must implement five functions which the testing suite will test independently, beyond just checking for the final answer (as last year’s version did).
</details>

And execute the below to evaluate the style of your code using `style50`.
```
style50 cash.c
```

## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/problems/2022/x/cash
```

-check50
- [x] :) cash.c exists
- [x] :) cash.c compiles
- [x] :) get_cents returns integer number of cents
- [x] :) get_cents rejects negative input
- [x] :) get_cents rejects a non-numeric input of "foo"
- [x] :) calculate_quarters returns 2 when input is 50
- [x] :) calculate_quarters returns 1 when input is 42
- [x] :) calculate_dimes returns 1 when input is 10
- [x] :) calculate_dimes returns 1 when input is 15
- [x] :) calculate_dimes returns 7 when input is 73
- [x] :) calculate_nickels returns 1 when input is 5
- [x] :) calculate_nickels returns 5 when input is 28
- [x] :) calculate_pennies returns 4 when input is 4
- [x] :) input of 41 cents yields output of 4 coins
- [x] :) input of 160 cents yields output of 7 coins

-style50
- [x] Looks good!
