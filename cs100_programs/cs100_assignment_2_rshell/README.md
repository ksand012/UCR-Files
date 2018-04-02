# Assignment 2 - ARRR SHELL

Installation
------------
Please run these commands in your terminal to run our ARRR SHELL on your computer

```Install Process
$ git clone https://github.com/cs100/cs100-assignment-2-REMOVED.git

$ cd cs100-assignment-2-REMOVED

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

Authors
------------
REMOVED: https://github.com/REMOVED

REMOVED: https://github.com/REMOVED
