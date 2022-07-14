# Mario
## World 1-1
Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend right-aligned pyramid of blocks, a la the below.  
![image](https://user-images.githubusercontent.com/70191060/178885461-a3dcd3fb-c47a-48f6-9b4b-1df137da6e89.png)  
Let’s recreate that pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself will also be taller than it is wide.  
```
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```
The program we’ll write will be called `mario`. And let’s allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs `8` when prompted:
```
$ ./mario
Height: 8
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```

Here’s how the program might work if the user inputs `4` when prompted:
```
$ ./mario
Height: 4
   #
  ##
 ###
####
```

Here’s how the program might work if the user inputs `2` when prompted:
```
$ ./mario
Height: 2
 #
##
```

And here’s how the program might work if the user inputs `1` when prompted:
```
$ ./mario
Height: 1
#
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:
```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #
  ##
 ###
####
```

## Pseudocode
execute
```
code pseudocode.txt
```
to open the file called `pseudocode.txt` inside that directory.

Write in `pseudocode.txt` some pseudocode that implements this program, even if not (yet!) sure how to write it in code. There’s no one right way to write pseudocode, but short English sentences suffice. Recall how we wrote [pseudocode for finding someone in a phone book](https://docs.google.com/presentation/d/1X3AMSenwZGSE6WxGpzoALAfMg2hmh1LYIJp3N2a1EYI/edit#slide=id.g41907da2bc_0_265). Odds are your pseudocode will use (or imply using!) one or more functions, conditionals, Boolean expressions, loops, and/or variables.

## How to Test Your Code
Does your code work as prescribed when you input

- -1 (or other negative numbers)?
- 0?
- 1 through 8?
- 9 or other positive numbers?
- letters or words?
- no input at all, when you only hit Enter?

Execute the below to evaluate the correctness of your code using `check50`. But be sure to compile and test it yourself as well!
```
check50 cs50/problems/2022/x/mario/less
```
Execute the below to evaluate the style of your code using `style50`.
```
style50 mario.c
```

## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/problems/2022/x/mario/less
```
