# ioc

> Welcome to Inversion Of Control Framework for C++11 **ioc**

This header file only implementation will allow you build application written in C++
to build application using the design pattern **IoC** a.k.a. *Inversion Of Control*

**This project is _work in progress_** 

I am adding functionality to support on-the-fly creation and injection of C++ objects
into your application.

Armed with pluggable architecture you will be able to assemble various applications
on demand in real time.

The main use case - receiving a request to solve a specific problem by assembling various
shared/dynamic libraries, satisfying their dependencies, running the program to fulfill the
request and disassemble.

A sibling project **iocContainer** (_work in progress_) will contain all the necessary tools to build a fully functional 
pluggable solution using this framework.
