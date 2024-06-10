#include <stdio.h>
#include <termios.h>
#include <unistd.h>


char _getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);          
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    ch = getchar();                          
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}

char _getche() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);          
    newt = oldt;
    newt.c_lflag &= ~(ICANON);               
    newt.c_lflag |= ECHO;                    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    ch = getchar();                          
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}
