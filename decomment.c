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
        putchar('/');
        putchar(c);
        state = CHAR_LITERAL;
    }
    else if (c == '*'){
        putchar(' ');
        state = COMMENT;
    }
    else if (c == '"') {
        putchar('/');
        putchar(c);
        state = STR_LITERAL;
    }
    else if (c == '/'){
        putchar(c);
        state = START_SLASH;
    }
    else{
        putchar('/');
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
        state = NORMAL;
    }
    else if (c == '*'){
        state = END_STAR;
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
    putchar(c);
    return CHAR_LITERAL;
}

enum Statetype handleStrEscapeState(int c){
    putchar(c);
    return STR_LITERAL;
}

/*----------------------------------------------------------*/
/* Read text from stdin. Convert the first character of each
   "word" to uppercase, where a word is a sequence of
   letters. Write the result to stdout. Return 0. */
int main(void){
    /* Use a DFA approach.  state indicates the DFA state. */
    enum Statetype state = NORMAL;
    int iChar;
    int iLineCount;
    int iLineCountInComment;
    
    iLineCount = 0;
    iLineCountInComment = 0;

    while ((iChar = getchar()) != EOF) {
        if(iChar == '\n'){
            if(state == COMMENT || state == END_STAR){
                iLineCountInComment++;
                putchar(iChar);
            }
            iLineCount++;
        }
        switch (state) {
            case NORMAL:
                state = handleNormalState(iChar);
                break;
            case START_SLASH:
                state = handleStartSlashState(iChar);
                break;
            case COMMENT:
                state = handleCommentState(iChar);
                break;
            case END_STAR:
                state = handleEndStarState(iChar);
                break;
            case CHAR_LITERAL:
                state = handleCharLiteralState(iChar);
                break;
            case STR_LITERAL:
                state = handleStrLiteralState(iChar);
                break;
            case CHAR_ESCAPE:
                state = handleCharEscapeState(iChar);
                break;
            case STR_ESCAPE:
                state = handleStrEscapeState(iChar);
                break;
        }
    }

    if (state == START_SLASH){
        putchar('/');
    }
    
    if (state == COMMENT || state == END_STAR){
        fprintf( stderr, "Error: line %d: unterminated comment", iLineCount - iLineCountInComment);
        return EXIT_FAILURE;
    } 
    else{
        return EXIT_SUCCESS;
    }
}