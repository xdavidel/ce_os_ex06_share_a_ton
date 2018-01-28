# Share a Ton

## Introduction

A hotel is an establishment that provides paid lodging on a short-term basis. Different facilities are
provided to the users, some are shared, some are really private. In the following exercise we will
focus on both, and.. we’ll use GB for measurement instead of tons..

## Share a ton
Along with the exercise, a simple Python script random_file.py is attached, it receives as the first
argument the output file path and writes 1GB of random content to it.
Run the script file, this output file is going to be your program’s input!
What we want to create is a program that loads the file to the process’ memory, but thinking about
others - it will give them the option to access it, instead of loading it by themselves!

We will use the same program for both cases, the program will first check if the given input file is
loaded in memory, if not - it will load it, running another instance of the program should already
read the file from memory.
The program should print out the address for the file content beginning, and exit on a key press.

With your code, also answer the following questions:
* Is there a reason to share the file in a special manner? What if all processes would just open the
file by themselves?
* How do handles relate to the first question? And which handles can we expect in your solution?
* What is the (theoretical) limit of instances of our program we can run?

## Remarks
* Only usage of WinAPI is allowed. You can use C-library for input/output only.
* Code should be organized, and API should be picked wisely, and used carefully as needed.
* You can investigate the memory and program state while running different instances of the
program (using VMMap and other SysInternals tools) - to get ideas for answering the questions.

## Your Submission
Please submit the necessary code files, well-documented (and not the whole solution) along with
answers to the given questions.
Hotels are fun, code is even more enjoyable!
References
* Your previous lesson.
* MSDN