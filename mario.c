#include <stdio.h>
#include <cs50.h>

void draw_segment(int length, char x);    //prototype for helper function for drawing each segment of spaces or brinks
int get_int_1to8(void);                    //prototype for getting postive intger between 1 - 8

int main(void)
{
    int height = get_int_1to8();    

    for (int i = 0; i < height; i++)
    {
        //declaring variables and constants
        int seg_length = i + 1;                        // number of brick to draw
        int seg_offset = height - seg_length;          // offset for spaces before the bricks
        string DIVIDER = "  ";                         // divider, set to two space
        char SHARP = '#';
        char SPACE = ' ';
            
        // execution flow 1. Draw space offset 2. Draw briks 3, Draw divider, 4. draw second set of bricks
        draw_segment(seg_offset, SPACE);
        draw_segment(seg_length, SHARP);
        printf("%s", DIVIDER);
        draw_segment(seg_length, SHARP);
        printf("\n");                                  // Advance to new line for next row.
    }
}

void draw_segment(int length, char x)
{
    for (int j = 0; j < length; j++)
    {
        printf("%c", x);
    }    
}

int get_int_1to8(void)
{
    int i = 0;
    while (i < 1 || i > 8)                            // only accept intsubmit50 cs50/problems/2020/x/mario/more between 1 to 8
    {
        i = get_int("Height: ");
    }
    return i;
}
    