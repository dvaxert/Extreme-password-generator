# About
Extreme password generator is a program for generating effective passwords of
 any length using symbols from the following categories:  
1. Lower case letters;  
2. Uppercase letters;  
3. Numbers;  
4. Special characters.  

There is also a functionality for generating passwords from "seed" which always
ы creates the same password from the same input value.  

# Required
To build a project you need CMake version 2.8 or older.  
This program uses the FLTK library "https://www.fltk.org/".

# How to compile:
Go to the directory where you want to place a copy of the project directory and
execute the following commands in the terminal:  
> git clone https://github.com/Exerros/Extreme-password-generator  
> cd Extreme-password-generator  
> git submodule init  
> git submodule update  
> mkdir build  
> cd build  
> cmake ..  
> cmake --build .  
> ./epg  
  
You can install the application with the command:  
> make install  

this may require administrator privileges or the use of sudo. 
You can also use the scripts in the **Extreme-password-generator/scripts**
 directory for the above actions  
After installation you will be able to start the program from the application
 menu or with the command:  
> epg  


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
