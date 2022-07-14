# Mario
## World 1-1
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.
![image](https://user-images.githubusercontent.com/70191060/178887122-7429ca25-2525-485b-a874-e52d90bb8d4d.png)

Let’s recreate those pyramids in C, albeit in text, using hashes (`#`) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves will also be taller than they are wide.
```
   #  #
  ##  ##
 ###  ###
####  ####
```
The program we’ll write will be called `mario`. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs `8` when prompted:
```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

```

Here’s how the program might work if the user inputs `4` when prompted:
```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

Here’s how the program might work if the user inputs `2` when prompted:
```
$ ./mario
Height: 2
 #  #
##  ##
```

And here’s how the program might work if the user inputs `1` when prompted:
```
$ ./mario
Height: 1
#  #
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:
```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

Open your `mario.c` file to implement this problem as described!

## How to Test Your Code
Does your code work as prescribed when you input

- -1 (or other negative numbers)?
- 0?
- 1 through 8?
- 9 or other positive numbers?
- letters or words?
- no input at all, when you only hit Enter?

You can also execute the below to evaluate the correctness of your code using `check50`. But be sure to compile and test it yourself as well!
```
check50 cs50/problems/2022/x/mario/more
```
Execute the below to evaluate the style of your code using `style50`.
```
style50 mario.c
```

## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/problems/2022/x/mario/more
```

-check50
- [x] :) mario.c exists
- [x] :) mario.c compiles
- [x] :) rejects a height of -1
- [x] :) rejects a height of 0
- [x] :) handles a height of 1 correctly
- [x] :) handles a height of 2 correctly
- [x] :) handles a height of 8 correctly
- [x] :) rejects a height of 9, and then accepts a height of 2
- [x] :) rejects a non-numeric height of "foo"
- [x] :) rejects a non-numeric height of ""

-style50
- [x] Looks good!
