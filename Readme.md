# About
Extreme password generator is a program for generating effective passwords of
different lengths. The program's operability was tested only on Unix, but the
project used platform-independent code and problems with should not be compiled
on other operating systems.

# Required
To build a project you need CMake version 2.8 or older.

This program uses the FLTK library "https://www.fltk.org/".

# How to compile:
Go to the directory where you want to place a copy of the project directory and
execute the following commands in the terminal:
> git clone https://github.com/Exerros/Extreme-password-generator

> mkdir build

> cd build

> cmake ..

> cmake --build .

> ./extreme_password_generator

# How to use:
To generate a password you need:
1. Write a seed generation from which a password will be generated. **Using 
seed is optional**. If you use seed, remember that the program will generate
the same password if the same seed was used. If you don't use seed then
the current time will be used as seed.

2. Specify the number of characters in your new password. **Specify the
number of characters is required!**

3. Specify what types of characters the generator should use when creating
your new password. **Specify character types is required!**


**If you do not specify the necessary rules for generating a password, you will
get password of appropriate quality - *qwerty***
