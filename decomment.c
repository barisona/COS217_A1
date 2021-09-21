/*------------------------------------------------------------*/
/* decomment.c */ 
/* Author: Baris Onat */ 
/*------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* A global variable Statetype for storing the current state to use in
   the DFA */
enum Statetype {NORMAL, START_SLASH, COMMENT, END_STAR, STR_LITERAL, 
CHAR_LITERAL, STR_ESCAPE, CHAR_ESCAPE};

/*----------------------------------------------------------*/
/* Implement the NORMAL state of the DFA. c is the current
   DFA character. Decide what to write depending on the DFA 
   instructions. Return the next state. */
/*----------------------------------------------------------*/ 
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
        /* c should not be written if a star follows the slash. */
        state = START_SLASH;
    }
    else{
        putchar(c);
        state = NORMAL;
    }
    return state;
}

/*----------------------------------------------------------*/
/* Implement the START_SLASH state of the DFA. c is the 
   current DFA character. Decide what to write depending on 
   the DFA instructions. Return the next state. */
/*----------------------------------------------------------*/ 
enum Statetype handleStartSlashState(int c){
    enum Statetype state;
    if (c == '*'){
        putchar(' '); /* replace the comment with a space */
        state = COMMENT;
    }

    /* If a star does not follow the slash character, we should write
       the slash character. */
    else if (c == '\'') {
        putchar('/');
        putchar(c);
        state = CHAR_LITERAL;
    }
    else if (c == '"') {
        putchar('/');
        putchar(c);
        state = STR_LITERAL;
    }
    else if (c == '/'){
        putchar('/');
        state = START_SLASH;
    }
    else{
        putchar('/');
        putchar(c);
        state = NORMAL;
    }
    return state;
}

/*----------------------------------------------------------*/
/* Implement the COMMENT state of the DFA. c is the current 
   DFA character. Decide what to write depending on the DFA
   instructions. Return the next state. */
/*----------------------------------------------------------*/ 
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

/*----------------------------------------------------------*/
/* Implement the END_STAR state of the DFA. c is the current
   DFA character. Decide what to write depending on the DFA
   instructions. Return the next state. */
/*----------------------------------------------------------*/ 
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

/*----------------------------------------------------------*/
/* Implement the CHAR_LITERAL state of the DFA. c is the 
   current DFA character. Decide what to write depending on 
   the DFA instructions. Return the next state. */
/*----------------------------------------------------------*/ 
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

/*----------------------------------------------------------*/
/* Implement the STR_LITERAL state of the DFA. c is the 
   current DFA character. Decide what to write depending on 
   the DFA instructions. Return the next state. */
/*----------------------------------------------------------*/ 
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

/*----------------------------------------------------------*/
/* Implement the CHAR_ESCAPE state of the DFA. c is the 
   current DFA character. Decide what to write depending on 
   the DFA instructions. Return the next state. */
/*----------------------------------------------------------*/ 
enum Statetype handleCharEscapeState(int c){
    putchar(c);
    return CHAR_LITERAL;
}

/*----------------------------------------------------------*/
/* Implement the STR_ESCAPE state of the DFA. c is the 
   current DFA character. Decide what to write depending on 
   the DFA instructions. Return the next state. */
/*----------------------------------------------------------*/ 
enum Statetype handleStrEscapeState(int c){
    putchar(c);
    return STR_LITERAL;
}

/*----------------------------------------------------------*/
/* Read text from stdin. Decomment the program (remove 
   comments defined in C90 standards). Return EXIT_SUCCESS
   if the program doesn't contain an unterminated comment.
   If it does, return EXIT_FAILURE and write stderr at what
   line the unterminated comment starts. */
/*----------------------------------------------------------*/
int main(void){
    /* State indicates the current DFA state. */
    enum Statetype state = NORMAL;
    int c; /* the current char */
    int lineCount; /* the number of new line characters in the text */
    /* the number of new line characters in the most recent comment */
    int lineCountInComment; 
    
    lineCount = 1;
    lineCountInComment = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n'){
            if (state == COMMENT || state == END_STAR){
                lineCountInComment++;
                putchar(c);
            }
            else{
                /* The lineCountInComment counts the number of new
                   line characters observed in the most recent comment
                   in case there is an unterminated comment. But the
                   fact that the program is in the else statement shows
                   that the text is out of the comment. */
                lineCountInComment = 0;
            }
            lineCount++;
        }
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

    /* If the last character is a slash character, the DFA will not
       print a slash due to its nature. It should print it here. */
    if (state == START_SLASH){
        putchar('/');
    }
    
    if (state == COMMENT || state == END_STAR){
        fprintf( stderr, "Error: line %d: unterminated comment\n", 
        lineCount - lineCountInComment);
        return EXIT_FAILURE;
    } 
    else{
        return EXIT_SUCCESS;
    }
}