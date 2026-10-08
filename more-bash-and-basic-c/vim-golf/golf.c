/* SEGMENT 5 - VIM GOLF
 *
 * This file has 3 mistakes. Fix them with as few keystrokes as you can.
 * You may NOT use the arrow keys.
 *
 * You win when this compiles clean:   gcc -Wall -o golf 50-golf.c
 *
 *   move:   h j k l        left down up right
 *           w  b           forward / back one word
 *           0  $           start / end of line
 *           %              jump to the matching ) } ]
 *           gg  G          top / bottom of file
 *
 *   edit:   i  a           insert before / after the cursor
 *           I  A           insert at START / END of the line 
 *           o  O           open a new line below / above
 *           dd             delete the whole line
 *           x              delete one character
 *           v              visual select, then d to delete
 *           u              undo        Ctrl-r  redo
 */

include <stdio.h>

int main(void) {
    int cans = 99;

    this line is garbage and should not be here

    printf("%d cans of monster energy on the wall\n", cans)

    printf("take one down, %d left\n", cans - 1);
	cans--;


    return 0;
}
