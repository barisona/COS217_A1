/*------------------------------------------------------------*/
/* decomment.c */ 
/* Author: Bob Dondero */ 
/*------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
enum Statetype {NORMAL, START_SLASH, COMMENT, END_STAR, STR_LITERAL, 
CHAR_LITERAL, STR_ESCAPE, CHAR_ESCAPE};

/*----------------------------------------------------------*/
/* Implement the NORMAL state of the DFA. c is the current
   DFA character. Write c or its uppercase equivalent to
   stdout, as specified by the DFA. Return the next state. */
enum Statetype handleNormalState(int c){
    enum Statetype state;
    if (c == '\'') {
        putchar(c);
        state = CHAR_LITERAL;
    } 
    else if (c == '"') {
        putchar(c);
        state = STR_LITERAL;
    }
    else if (c == '/'){
        putchar(c);
        state = START_SLASH;
    }
    else{
        putchar(c);
        state = NORMAL;
    }

    return state;
}

enum Statetype handleStartSlashState(int c){
    enum Statetype state;
    if (c == '\'') {
        putchar(c);
        state = CHAR_LITERAL;
    }
    else if (c == '*'){
        putchar(c);
        state = COMMENT;
    }
    else if (c == '"') {
        putchar(c);
        state = STR_LITERAL;
    }
    else if (c == '/'){
        putchar(c);
        state = START_SLASH;
    }
    else{
        putchar(c);
        state = NORMAL;
    }

    return state;
}

enum Statetype handleCommentState(int c){
    enum Statetype state;
    if (c == '*') {
        state = END_STAR;
    } 
    else{
        state = COMMENT;
    }
    return state;
}

enum Statetype handleEndStarState(int c){
    enum Statetype state;
    if (c == '/'){
        putchar(' ');
        state = NORMAL;
    }
    else{
        state = COMMENT;
    }

    return state;
}

enum Statetype handleCharLiteralState(int c){
    enum Statetype state;
    if (c == '\\') {
        putchar(c);
        state = CHAR_ESCAPE;
    } 
    else if (c == '\'') {
        putchar(c);
        state = NORMAL;
    }
    else{
        putchar(c);
        state = CHAR_LITERAL;
    }

    return state;
}

enum Statetype handleStrLiteralState(int c){
    enum Statetype state;
    if (c == '\\') {
        putchar(c);
        state = STR_ESCAPE;
    } 
    else if (c == '"') {
        putchar(c);
        state = NORMAL;
    }
    else{
        putchar(c);
        state = STR_LITERAL;
    }

    return state;
}

enum Statetype handleCharEscapeState(int c){
    enum Statetype state;
    if (c) {
        putchar(c);
        state = CHAR_LITERAL;
    } 
    
    return state;
}

enum Statetype handleStrEscapeState(int c){
    enum Statetype state;
    if (c) {
        putchar(c);
        state = STR_LITERAL;
    } 
    
    return state;
}


/*----------------------------------------------------------*/
/* Read text from stdin. Convert the first character of each
   "word" to uppercase, where a word is a sequence of
   letters. Write the result to stdout. Return 0. */
int main(void){
    int c;
    /* Use a DFA approach.  state indicates the DFA state. */
    enum Statetype state = NORMAL;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case NORMAL:
                state = handleNormalState(c);
                break;
            case START_SLASH:
                state = handleStartSlashState(c);
                break;
            case COMMENT:
                state = handleCommentState(c);
                break;
            case END_STAR:
                state = handleEndStarState(c);
                break;
            case CHAR_LITERAL:
                state = handleCharLiteralState(c);
                break;
            case STR_LITERAL:
                state = handleStrLiteralState(c);
                break;
            case CHAR_ESCAPE:
                state = handleCharEscapeState(c);
                break;
            case STR_ESCAPE:
                state = handleStrEscapeState(c);
                break;
        }
    }

    switch(state) {
            case NORMAL:
            case START_SLASH:
            case CHAR_LITERAL:
            case STR_LITERAL:
            case CHAR_ESCAPE:
            case STR_ESCAPE:
                return EXIT_SUCCESS;
            case COMMENT:
            case END_STAR:
                return EXIT_FAILURE;


    }
}