#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//colon :  semicolon ;  comma ,
//tokens
#define PROGRAM 8
#define SEMICOLON 9
#define POINT  10
#define NUMBER  11
#define PROCEDURE  17
#define FUNCTION  25
#define COLON  26
#define END 29
#define ARRAY  34
#define OF  36
#define LPARENTHESES  37
#define RPARENTHESES  38
#define LBRACKET  39
#define RBRACKET 40
#define COMMA  41
#define IF 43
#define THEN 47
#define BEGIN 52
#define ELSE 55
#define WHILE 60
#define DO 62
#define SMALLER 63
#define GREATER 64
#define SMALLEREQ 65
#define GREATEREQ 66
#define MINUS 67
#define PLUS 68
#define NOT 72
#define DOTDOT 73
#define ATRIBUTION 74
#define ID 75
#define VAR 78
#define ASTERIX 79
#define EQUAL 80
#define DIFFERENT 81
#define COMMENTPAR 82,
#define COMENTEBRACKET 83
#define OR 84
#define AND 85
#define DIV 87  

//estados do analisador lexico
enum ESTADOSLEXICO{ NORMAL, COMENTARIOCHAVE, COMENTARIOPAREN};

//matriz
int estados[][89]={    /* .  ,  :  ;  =  +  -  *  (  )  [  ]  0  1  2  3  4  5  6  7  8  9  <  >  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  x  w  y  z  _  {  }*/
        /*state 0*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*state 1*/     {10,41,26, 9,80,68,67,79,37,38,39,40,11,11,11,11,11,11,11,11,11,11,63,64,30,48,75,61,27,18,75,75,42,75,75,75,75,70,35, 2,75,75,75,44,75,76,75,56,75,75,75,83, 0},//INICIAL
        /*state 2*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 3,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 3*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 4,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 4*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,12,75,75,75, 5,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 5*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 6,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 6*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0, 7,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 7*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,8,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 8*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//PROGRAM
        /*state 9*/     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//SEMICOLON
        /*state 10*/    {73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//POINT
        /*state 11*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11,11,11,11,11,11,11,11,11,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//NUMBER
        /*state 12*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,13,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 13*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,14,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 14*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,15,75,75,75,75,75,75, 0, 0},
        /*state 15*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,16,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 16*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,17,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 17*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//PROCEDURE
        /*state 18*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,19,75,75,75,75,75,75, 0, 0},
        /*state 19*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,20,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 20*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,21,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 21*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,22,75,75,75,75,75,75,75, 0, 0},
        /*state 22*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,23,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 23*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,24,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 24*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,25,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 25*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//FUNCTION
        /*state 26*/    { 0, 0, 0, 0,74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//COLON
        /*state 27*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,53,75,28,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 28*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,29,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 29*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//END
        /*state 30*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,69,75,75,75,31,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 31*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,32,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 32*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,33,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 33*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,34,75,75, 0, 0},
        /*state 34*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//ARRAY
        /*state 35*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,36,75,75,75,75,75,75,75,75,75,75,75,84,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 36*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//OF
        /*state 37*/    { 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//LPARENTHESES
                       /* .  ,  :  ;  =  +  -  *  (  )  [  ]  0  1  2  3  4  5  6  7  8  9  <  >  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  x  w  y  z*/
        /*state 38*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//RPARENTHESES
        /*state 39*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//LBRACKETS
        /*state 40*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//RBRACKETS
        /*state 41*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//COMMA
        /*state 42*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,43,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 43*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//IF
        /*state 44*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,45,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 45*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,46,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 46*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,47,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 47*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//THEN
        /*state 48*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,49,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 49*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,50,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 50*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,51,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 51*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,52,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 52*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//BEGIN
        /*state 53*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,54,75,75,75,75,75,75,75,75, 0, 0},
        /*state 54*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,55,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 55*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//ELSE
        /*state 56*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,57,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 57*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,58,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 58*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,59,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 59*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,60,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 60*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//WHILE       
        /*state 61*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,86,75,75,75,75,75,62,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 62*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//DO
        /*state 63*/    { 0, 0, 0, 0,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//SMALLER
        /*state 64*/    { 0, 0, 0, 0,66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//GREATER
        /*state 65*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//SMALLER_EQ
        /*state 66*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//GREATER_EQ
        /*state 67*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//MINUS
        /*state 68*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//PLUS
        /*state 69*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       /* .  ,  :  ;  =  +  -  *  (  )  [  ]  0  1  2  3  4  5  6  7  8  9  <  >  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  x  w  y  z  _  {  }*/
        /*state 70*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,71,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 71*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,72,75,75,75,75,75,75,75, 0, 0},
        /*state 72*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75,75, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//NOT
        /*state 73*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//DOTDOT
        /*state 74*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//ATRIBUTION
        /*state 75*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//ID
        /*state 76*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,77,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 77*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,78,75,75,75,75,75,75,75,75,75, 0, 0},
        /*state 78*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//VAR
        /*state 79*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//ARTERIX
        /*state 80*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//EQUAL
        /*state 81*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//DIFFERENT
        /*state 82*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//COMMENTPAR
        /*state 83*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//COMMENTBRACKET
        /*state 84*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//OR
        /*state 85*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//AND
        /*state 86*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,87,75,75,75,75,75, 0, 0},
        /*state 87*/    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,75,75,75,75,75,75,75,75,75,75, 0, 0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75, 0, 0},//DIV
        
    };
    
    //caractere lido
    char simbolo;

    char letras[]=".,:;=+-*()[]0123456789<>abcdefghijklmnopqrstuvxwyz_{}";

    int token, linha=1, coluna=1, total=0;
               /*0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88*/
    int final[]={0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    // id(coluna), proximo estado, ultimo estado reconhecido
    int ultimoEstadoFinal=1;
    
    //cursor que fica no inicio, cursos da ultima cadeia a ceita, cursos da posicao atual
    int cursorInicial = 0,cursorCadeiaAceita = 0,cursorAtual = 0;

    int auxCursorInicial, auxCursorCadeiaAceita;

    //estado atual do automato
    int estadoAtual = 1;
    
    int codeAccept=0;

void S(); void E(); void B();
void B1(); void B2(); void B3();
void Z(); void Z1();
void Z2(); void Z4(); void T();
void T1(); void T2();
void C(); void C1();
void O(); void O1();
void O2();
void P(); void P1();
void P2(); void P3();
void R(); void R1();
void W(); void X();
void X1(); void K(); void K1();
void I(); void U(); void U1();

void imprimiErro(){
    int i;
    fseek(stdin,auxCursorInicial-1,SEEK_SET);
    printf("\"");
    //printf("%d %d",auxCursorInicial,cursorCadeiaAceita);
    for(i=auxCursorInicial;i<cursorCadeiaAceita;i++){
        fscanf(stdin,"%c",&simbolo);
        if(simbolo!= ' ' && simbolo!= '\n'){printf("%c",simbolo);}
    }
    printf("\"");
    
}

int verifyState(int state){
        int i;
        int states[]={8,9,10,11,17,25,26,29,34,36,37,38,39,40,41,43,47,52,55,60,62,63,64,65,66,67,68,72,73,74,75,78,79,81,82,83,84,85,87};
        
        for(i=0;i<38;i++){
        
            if(state==states[i]){
        
                return state;
        
            }
        }
        return 75;
}

//retorna a posicao de uma letra dentro de uma string
int indexOf(char str[],char letra){
    
    int i=0;
    
    while(str[i]!='\0'){
    
        if(str[i]==letra){
    
            return i;
    
        }
    
        i++;
    
    }
    
    return -1;
}

int getToken(){
    
    int prox, i;

    int id;

    int estadoLexico = NORMAL;
    
    //pega caractere
    while(fscanf(stdin,"%c",&simbolo) != EOF){
            //printf("¨%c¨ linha: %d coluna:%d\n",simbolo,linha , coluna);
            if(simbolo < 91 && simbolo > 64){

                simbolo += 32;
            
            }
            
            //pega o index(numero da coluna da matriz)
            id = indexOf(letras,simbolo);
            
            //++ no cursor atual de leitura
            cursorAtual ++;
            
            if(simbolo=='\n'){
                total=total+coluna;
                linha++;
                coluna=1;
            }else{
                coluna++;
            }

            //se encontra id entra para o procesamento
            if(id != - 1 && estadoLexico == NORMAL){
        
                //pega o proximo estado 
                prox = estados[estadoAtual][id];

                //printf("[%d][%d]=%d %s cursorAtual %d \n",estadoAtual,id,prox,final[prox]?"final":"n final",cursorAtual);
        
                //se o proximo estado for != de erro (0) continua
                if(prox != 0 && prox != 83 && prox != 82 ){
        
                    //estado atual recebe o proximo
                    estadoAtual = prox;
        
                    //testa se o proximo é final 
                    if(final[prox]){
        
                        //cursor de cadeia aceita até o momento recebe cursor atual
                        cursorCadeiaAceita = cursorAtual;
                        //printf("estado atual - %d prox %d \n",estadoAtual,prox);
                        //ultimo estado aceito recebe o proximo
                        ultimoEstadoFinal = prox;
        
                    }
                }else if(prox == 83 ){

                    estadoLexico = COMENTARIOCHAVE;
                
                }else if(prox == 82){

                    estadoLexico = COMENTARIOPAREN;

                }else{
                    
                    estadoAtual = 1;

                    auxCursorInicial=cursorInicial;

                    cursorInicial = cursorCadeiaAceita;
                    
                    cursorAtual=cursorCadeiaAceita;
                    coluna=coluna-1;
                    coluna=coluna-(cursorAtual-cursorCadeiaAceita);

                    fseek(stdin,cursorInicial-1,SEEK_SET);
                    //printf("%d ",verifyState(ultimoEstadoFinal));
                    return verifyState( ultimoEstadoFinal);
                }
        
            }else if (estadoLexico == COMENTARIOCHAVE){

                while (fscanf(stdin,"%c",&simbolo) != EOF){

                    cursorAtual ++;
                    if(indexOf(letras,simbolo) == indexOf(letras,'}')){

                        estadoLexico = NORMAL;
                        estadoAtual = 1;
                        
                        cursorInicial = cursorAtual;
                        break;
                    }
                }

                if(simbolo == EOF){

                    return -1;

                }
                
            }else if(estadoLexico == COMENTARIOPAREN){

                while (fscanf(stdin,"%c",&simbolo) != EOF){

                    cursorAtual ++;
                    if(indexOf(letras,simbolo) == indexOf(letras,'*')){
                        fscanf(stdin,"%c",&simbolo);
                        if( simbolo != EOF && simbolo == ')'){

                            estadoLexico = NORMAL;
                            estadoAtual = 1;
                            cursorInicial = cursorAtual;
                            break;
                        }
                        
                    }
                }

                if(simbolo == EOF){

                    return -1;

                }

            //id nao aceito testa se o simbolo é igual a Line Feed(10)
            }else if(simbolo == 9 || simbolo == 10 || simbolo == 32){
                
                //testa se o estado atual nao é final
                if(estadoAtual != 1){
        
                    //prints de debug
                    //printf("Inicial %d,Aceita %d,Atual %d, prox %d\n",cursorInicial,cursorCadeiaAceita,cursorAtual,prox);
                            
                    //reinicia o automato com estado 1
                    estadoAtual=1;
                    auxCursorInicial=cursorInicial;
                    cursorInicial=cursorCadeiaAceita;
                    //coluna=cursorAtual-cursorCadeiaAceita;
                    //volta o cursor até o ultimo token aceito
                    fseek(stdin,cursorInicial,SEEK_SET);
                    //printf("%d ",verifyState(ultimoEstadoFinal));
                    return verifyState( ultimoEstadoFinal);

                }else{
                    //prints de debug
                    //printf(">>Inicial %d,Aceita %d,Atual %d, prox %d estado atual %d\n",cursorInicial,cursorCadeiaAceita,cursorAtual,prox,estadoAtual);
                }
        
            //se simbolo nao tem id e é diferente de 10     
            }else if(simbolo!=10){
                
                printf("ERRO LEXICO. Linha: %d Coluna: %d -> %c",linha,coluna,simbolo);
                return -1;
            }  
    }
        return -1;
      
}

void advance(){
    token=getToken();
}

void eat(int t){
    //printf("=======================token: %d t: %d",token,t);
    if(token == t){
        advance();
    }else{
        
    }
}

void erro(char *e){
    printf("%s \t",e);
    printf("ERRO DE SINTAXE. Linha: %d -> ",linha);
    
    imprimiErro();
    codeAccept=1;
    exit(1);
}

int main(){
    int i=0;
    // while(1){
    //     token = getToken();
    //     if(token==-1){
    //         break;
    //     }
    // }
        token = getToken();
        S();
        if(codeAccept==0){
            printf("PROGRAMA CORRETO.");
        }
        
    return 1;
}

/*inicial*/
void S(){
    switch(token){
        case PROGRAM: E(); break;
        default: erro("S"); break;
    }

}

/*Programa*/
void E(){
    switch(token){
        case PROGRAM: eat(PROGRAM); eat(ID); eat(SEMICOLON); B(); eat(POINT); break;
        default:erro("E");break;
    }
    
}

/*Bloco*/
void B(){
    switch(token){
        case BEGIN: B1(); B2(); eat(BEGIN); C(); C1(); eat(END); break;
        case VAR: B1(); B2(); eat(BEGIN); C(); C1(); eat(END); break;
        case PROCEDURE: B1(); B2(); eat(BEGIN); C(); C1(); eat(END); break;
        case FUNCTION: B1(); B2(); eat(BEGIN); C(); C1(); eat(END); break;
        default: erro("B"); break;
    }
    
}

void B1(){
    switch(token){
        case BEGIN: break;
        case VAR: eat(VAR); B3();break;
        case PROCEDURE: break;
        case FUNCTION: break;
        default:erro("B1");break;    
    }
    
}

void B2(){
    switch(token){
        case BEGIN: break;
        case PROCEDURE:eat(PROCEDURE);eat(ID);P();eat(SEMICOLON);B();eat(SEMICOLON);B2();break;
        case FUNCTION: eat(FUNCTION); eat(ID);P();eat(COLON); eat(ID);eat(SEMICOLON);B(); eat(SEMICOLON);B2(); break;
        default:erro("B2");break;        
    }
    
}

void B3(){
    switch(token){
        case ID: eat(ID); I();eat(COLON); T(); eat(SEMICOLON); B3();break;
        case BEGIN: break;
        case PROCEDURE: break;
        case FUNCTION: break;
        default:erro("B3"); break;
    }
}

/*Expressao simples*/
void Z(){
    switch(token){
        case ID: Z1(); R(); Z2(); break;
        case LPARENTHESES: Z1(); R(); Z2(); break;
        case NUMBER: Z1(); R(); Z2(); break;
        case PLUS: Z1(); R(); Z2(); break;
        case MINUS: Z1(); R(); Z2(); break;
        case NOT: Z1(); R(); Z2(); break;
        default:erro("Z");break;
    }
}

void Z1(){
    switch(token){
        case ID: break;
        case LPARENTHESES: break;
        case NUMBER: break;
        case PLUS: eat(PLUS); break;
        case MINUS: eat(MINUS); break;
        case NOT: break;
        default:erro("Z1");break;
    }
}

void Z2(){
    switch(token){
        case SEMICOLON: break;
        case END: break;
        case RPARENTHESES: break;
        case COMMA: break;
        case RBRACKET: break;
        case EQUAL: break;
        case DIFFERENT: break;
        case SMALLER: break;
        case SMALLEREQ: break;
        case GREATEREQ: break;
        case GREATER: break;
        case PLUS: K1(); R(); Z2(); break;
        case MINUS: K1(); R(); Z2(); break;
        case OR: K1(); R(); Z2(); break;
        case THEN: break;
        case DO: break;
        default:erro("Z2");break;
    }
}

void K1(){
    switch (token){
    case PLUS: eat(PLUS); break;
    case MINUS: eat(MINUS); break;
    case OR: eat(OR); break;
    default:erro("K1");break;
    }
}

void Z4(){
    switch(token){
        case RPARENTHESES: break;
        case COMMA: eat(COMMA); X(); Z4(); break;
        case RBRACKET: break;
        default: erro("Z4"); break;
    }
}

/* Tipo*/
void T(){
    switch(token){
        case ID: eat(ID); T2(); break;
        case NUMBER: Z1(); eat(NUMBER);eat(DOTDOT);K(); break;
        case ARRAY: eat(ARRAY); eat(LBRACKET); T(); T1(); eat(RBRACKET); eat(OF); T(); break;
        case PLUS: Z1();eat(NUMBER); eat(DOTDOT);K(); break;
        case MINUS: Z1(); eat(NUMBER); eat(DOTDOT);K();break;
        default: erro("T"); break;
    }

}

void T1(){
    switch(token){
        case COMMA: eat(COMMA); T(); T1(); break;
        case RBRACKET: break;
        default:erro("T1");break;
    }
}

void T2(){
    switch(token){
        case SEMICOLON: break;
        case COMMA: break;
        case DOTDOT: eat(DOTDOT); K(); break;
        case RBRACKET: break;
        default:erro("T2"); break;
    }
}

/*  Comando */
void C(){
    switch(token){
        case ID: eat(ID); U(); break;
        case SEMICOLON: break;
        case BEGIN: eat(BEGIN); C(); C1(); eat(END); break;
        case END: break;
        case IF: eat(IF);X();eat(THEN);eat(BEGIN);C();C1();eat(END);U1();break;
        case WHILE: eat(WHILE); X(); eat(DO); C(); break;
        default:erro("C");break;
    }
}

void C1(){
    switch(token){
        case SEMICOLON: eat(SEMICOLON); C();C1(); break;
        case END:break; 
        default:erro("C1");break;
    }
}

void U(){
    switch(token){
        case SEMICOLON: break;
        case END: break;
        case LPARENTHESES: eat(LPARENTHESES); O2(); eat(RPARENTHESES); break;
        case LBRACKET: W(); eat(ATRIBUTION); X(); break;
        case ATRIBUTION: W(); eat(ATRIBUTION); X();break;
        default: erro("U"); break;
    }
}

void U1(){
    switch(token){
        case SEMICOLON: break;
        case END: break;
        case ELSE: eat(ELSE); eat(BEGIN); C(); C1(); eat(END); break;
        default:erro("U1");break;
    }
}

/*Fator*/
void O(){
    switch(token){
        case ID: eat(ID); O1(); break;
        case LPARENTHESES: eat(LPARENTHESES); X(); eat(RPARENTHESES); break;
        case NUMBER: eat(NUMBER); break;
        case NOT: eat(NOT); O(); break;
        default: erro("O"); break;
    }
}

void O1(){
    switch(token){
        case SEMICOLON: W(); break;
        case END: W(); break;
        case LPARENTHESES:  eat(LPARENTHESES); O2(); eat(RPARENTHESES); break;
        case RPARENTHESES:W(); break;
        case COMMA: W(); break;
        case LBRACKET: W(); break;
        case RBRACKET: W(); break;
        case EQUAL: W(); break;
        case DIFFERENT: W(); break;
        case SMALLER: W(); break;
        case SMALLEREQ: W(); break;
        case GREATEREQ: W(); break;
        case GREATER: W(); break;
        case PLUS: W(); break;
        case MINUS: W(); break;
        case OR: W(); break;
        case ASTERIX: W(); break;
        case DIV: W(); break;
        case AND: W(); break;
        case THEN: W(); break;
        case DO: W(); break;
        default:erro("O1");break;
    }
}

void O2(){
    switch(token){ 
        case ID: X(); Z4(); break;
        case LPARENTHESES: X(); Z4(); break;
        case RPARENTHESES: break;
        case NUMBER: X(); Z4(); break;
        case RBRACKET: break;
        case PLUS:X(); Z4(); break;
        case MINUS: X(); Z4(); break;
        case NOT: X(); Z4(); break;
        default:erro("O2");break;
    }
}

/*Parametros formais*/
void P(){
    switch(token){
        case SEMICOLON: break;
        case COLON: break;
        case LPARENTHESES: eat(LPARENTHESES); P1(); eat(RPARENTHESES); P(); break;
        default: erro("P");break;
    }
}

void P1(){
    switch(token){
        case ID: P2(); eat(ID); I(); eat(COLON); eat(ID); P3(); break;
        case VAR: P2(); eat(ID); I(); eat(COLON);eat(ID); P3(); break;
        default:erro("P1");break;
    }
}

void P2(){
  switch(token){
    case ID: break;
    case VAR: eat(VAR); break;
    default:erro("P2");break;
  }  
}

void P3(){
   switch(token){
       case SEMICOLON: eat(SEMICOLON); P1(); break;
        case RPARENTHESES: break;
        default: erro("P3"); break;
   } 
}

/* Termo*/
void R(){
    switch(token){
        case ID: O(); R1(); break;
        case LPARENTHESES: O(); R1(); break;
        case NUMBER: O(); R1();break;
        case NOT: O(); R1(); break;
        default: erro("R"); break; 
    }
}

void R1(){
    switch(token){
        case SEMICOLON:break;
        case END: break;
        case RPARENTHESES: break;
        case COMMA: break;
        case RBRACKET: break;
        case EQUAL: break;
        case DIFFERENT: break;
        case SMALLER: break;
        case SMALLEREQ: break;
        case GREATEREQ: break;
        case GREATER: break;
        case PLUS: break;
        case MINUS:break;
        case OR: break;
        case ASTERIX:eat(ASTERIX);O();R1();break;
        case DIV:eat(DIV);O();R1();break;
        case AND:eat(AND);O();R1();break;
        case THEN: break;
        case DO: break;
        default:erro("R1");break;

    }
}

void X(){
    switch(token){
        case ID: Z(); X1(); break;
        case LPARENTHESES: Z(); X1(); break;
        case NUMBER: Z(); X1(); break;
        case PLUS: Z(); X1(); break;
        case MINUS: Z(); X1(); break;
        case NOT: Z(); X1(); break;
        default: erro("X"); break;
    }
}

void X1(){
    switch(token){
        case SEMICOLON: break;
        case END: break;
        case RPARENTHESES: break;
        case COMMA: break;
        case RBRACKET: break;
        case EQUAL: eat(EQUAL); Z(); break;
        case DIFFERENT: eat(DIFFERENT); Z(); break;
        case SMALLER: eat(SMALLER); Z(); break;
        case SMALLEREQ: eat(SMALLEREQ); Z();
        case GREATEREQ: eat(GREATEREQ); Z(); break;
        case GREATER: eat(GREATER); Z(); break;
        case THEN: break;
        case DO: break;
        default:erro("X1");break;
    }
}

void K(){
    switch(token){
        case ID: eat(ID); break;
        case NUMBER: Z1(); eat(NUMBER); break;
        case PLUS: Z1(); eat(NUMBER); break;
        case MINUS: Z1(); eat(NUMBER);break;
        default:
           erro("K");
          break;
    }
}

void I(){
    switch(token){
        case COLON:break;
        case COMMA: eat(COMMA); eat(ID); I(); break;
        default: erro("I"); break;
    }
}

void W(){
    switch(token){
        case SEMICOLON: break;
        case END: break;
        case RPARENTHESES: break;
        case COMMA:break;
        case LBRACKET: eat(LBRACKET); O2(); eat(RBRACKET); W(); break;
        case RBRACKET: break;
        case EQUAL: break;
        case DIFFERENT:break;
        case SMALLER: break;
        case SMALLEREQ: break;
        case GREATEREQ: break;
        case GREATER: break;
        case PLUS: break;
        case MINUS: break;
        case OR: break;
        case ASTERIX: break;
        case DIV: break;
        case AND: break;
        case ATRIBUTION: break;
        case THEN: break;
        case DO: break;
        default: erro("W"); break;
    }
}