# CMySQL: An easy to use C++ implementation of MySQL

### About:
CMySQL is a project aimed at making it dead easy to use MySQL in a C++ project. After scouring the Internet for a useable C++ implementation without success (although MySQL++ is making great progress) I decided to make my own one that is incredibly simple.


The problem I had with MySQL++ was that it wasnt multiple-query proof (i.e. you couldnt do any queries until the result from the previous query had been freed.) The only way around this was to buffer the entire result. This led me to develop this library. This is not a library as such. This is a class, with source, which you compile along with your other source files.


There are two classes; CMySQL (the main connection abstraction) and the CMySQLResult class. You can get more information on these in section 4 where I describe how to use this package.

### Instructions:
See "readme.htm"

### Info:
**Created:** 2004


**Operating System:** Windows 2000 or newer


**Compile with:** Microsoft Visual Studio 6 or Borland C++ Builder 6
