Large Number Calculator
=======================
Created by Murray Christopherson  
Updated April 2010

About the Program
-----------------
An interesting program, which alleviates the restrictions laid by the primative
data types in C. Theoretically, a number of infinite size can input, and thusly
added and/or multiplied. Due to constraints, I have chosen to not support
subtraction, division nor negative numbers (though they may appear in a later
version someday). The program was an exercise in keeping to standards, 
and working with numbers.  
It is recommended you read the source code to see exactly what the code is
doing.  
Please visit my portfolio at http://murraychristopherson.com

If you discover any bugs or unclear/inconsistent documentation, please contact me
at murraychristopherson@gmail.com with a description of what happened, and I
will try and have a fixed version up shortly.

Installation
------------
If you have the program 'make' installed on your computer, the executable is
easily creatable by running 'make' on the containing directory.

EXAMPLE:
```
$> make
```
To uninstall the file, the executable is easily removed with the 'make clean'
command.

EXAMPLE:
```
$> make clean
```
I recommend you open the 'makefile' to see which macros you can (in particular,
if you don't use 'cc' as your C compiler). 

Running the Program
-------------------
Using the numbered menu system, you can add or multiply two numbers. Please note
that there is a restriction set in the source code, so you can't input an
infinite number (due to c-string restrictions).
