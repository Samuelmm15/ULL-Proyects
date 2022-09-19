==============================================
==============ViewNet=========================
==============================================

This is a program use to send a text message into a socket, and recieve it and writting into the screen.

To \compile\ the program is neccesary to use de makefile added with the code text. To use it is neccesary to open a terminal, and write:
    make all    ** To compile all the code text and generate the excutables **
    make clean  ** To clean the object files that generates the executables **

Another way to compile the code text:

g++ ViewNetReceive.cc Socket.cc File.cc -o ViewNetReceive   ** To compile the Recieve executable **
g++ ViewNetSend.cc Socket.cc File.cc -o ViewNetSend     ** To compile the Send executable **

To \execute\ the program is neccesary to:
    1) Open two terminal, the first one to the recieve executable and the second one to the send executable.
    2) In the first terminal, execute the recieve executable.
    3) In the second terminal, execute the send executable.
    4) Return to the first terminal, to see the result.
