# Hello
## Getting Started
Recall that Visual Studio Code (aka VS Code) is a popular “integrated development environment” (IDE) via which you can write code. So that you don’t have to download, install, and configure your own copy of VS Code, we’ll use a cloud-based version instead that has everything you’ll need pre-installed.

Log into [code.cs50.io](https://code.cs50.io/) using your GitHub account. Once your “codespace” loads, you should see that, by default, VS Code is divided into three regions. Toward the top of VS Code is your “text editor”, where you’ll write all of your programs. Toward the bottom of is a “terminal window”, a command-line interface (CLI) that allows you to explore your codespace’s files and directories (aka folders), compile code, and run programs. And on the left is your file “explorer,” a graphical user interface (GUI) via which you can also explore your codespace’s files and directories.

## Getting User Input
Suffice it to say, no matter how you compile or execute this program, it only ever prints `hello, world`. Let’s personalize it a bit, just as we did in class.  

Modify this program in such a way that it first prompts the user for their name and then prints `hello, so-and-so`, where `so-and-so` is their actual name.

As before, be sure to compile your program with:
```
make hello
```
And be sure to execute your program, testing it a few times with different inputs, with:
```
./hello
```

### Hints
**Don’t recall how to prompt the user for their name?**

Recall that you can use get_string as follows, storing its return value in a variable called name of type string.
```c
string name = get_string("What's your name? ");
```

**Don’t recall how to format a string?**

Don’t recall how to join (i.e., concatenate) the user’s name with a greeting? Recall that you can use `printf` not only to print but to format a string (hence, the `f` in `printf`), a la the below, wherein name is a string.
```c
printf("hello, %s\n", name);
```

**Use of undeclared identifier?**
```
Seeing the below, perhaps atop other errors?
```
error: use of undeclared identifier 'string'; did you mean 'stdin'?
Recall that, to use `get_string`, you need to include `cs50.h` (in which `get_string` is declared) atop a file, as with:
```
#include <cs50.h>
```

## How to Test Your Code
Execute the below to evaluate the correctness of your code using `check50`, a command-line program that will output happy faces whenever your code passes CS50’s automated tests and sad faces whenever it doesn’t! But be sure to compile and test it yourself as well!  
```
check50 cs50/problems/2022/x/hello
```
Execute the below to evaluate the style of your code using `style50`, a command-line program that will output additions (in green) and deletions (in red) that you should make to your program in order to improve its style. If you have trouble seeing those colors, `style50` supports other [modes](https://cs50.readthedocs.io/style50/) too!  
```
style50 hello.c
```

## How to Submit
In your terminal, execute the below to submit your work.  
```
submit50 cs50/problems/2022/x/hello
```
-check50
- [x] :) hello.c exists
- [x] :) hello.c compiles
- [x] :) responds to name Emma
- [x] :) responds to name Rodrigo

-style50
- [x] Looks good!
