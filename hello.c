//importing required libraries
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompting for use input
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}