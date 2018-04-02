# Assignment 4 - ARRR SHELL

Installation
------------
Please run these commands in your terminal to run our ARRR SHELL on your computer

```Install Process
$ git clone https://github.com/cs100/cs100-assignments-REMOVED.git

$ cd cs100-assignments-REMOVED

$ make

$ bin/rshell
```

Overview of ARRR SHELL
------------
For this program we will read in user input, take the string they typed, and check for text flags (i.e. || && ;). Then we will separate
the string into smaller strings that are made up of the information separated by each flag. We finally will execute each of the smaller
sub-strings.

We will start by prompting the user for an input. Once the user input is received, the code will be read until a connector or null
character is reached. This segment will be separated into its own process, and the code will continue. If a connector was reached,
the code will continue reading the input for more commands. If a null character is reached, the input is over and the previous
commands will be executed. At any time, if the program reaches a pound sign, the rest of the input is ignored as a comment. Each
command of the input is checked for validity, then forked. The parent process is told to wait, while the code’s logic is run on the child.
The value of the child is returned and the child is killed, with the code continuing using the parent.

The user may also execute the "test" command and its symbolic equivalent, "[]," which is useful for combining with && and || to write more
complex bash command structures. "-e, -f, -d" flags may also be used to check whether a file system object exists and whether it is a 
directory or file. Users may also use parentheses to change the precedence of the commands on a single line.

The user is able to redirect input or output at their discretion.  Redirecting inputs can be accomplished using the < or << arrows.  Redirecting outputs can also be accomplished using the > or >> arrows.

Finally, the user is able to break up commands through piping in order to satisfy their use of the program.  They can use the | pipe symbol to do so in their command(s).

Authors
------------
REMOVED: https://github.com/REMOVED

REMOVED: https://github.com/REMOVED