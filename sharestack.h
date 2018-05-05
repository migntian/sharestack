#pragma once
#include <stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define MAXSIZE 10000
#define HEADER printf("\n===========%s===========\n",__FUNCTION__)
typedef char stacktype;
typedef struct sharestack{
    stacktype data[MAXSIZE];
    size_t stack1;
    size_t stack2;
}sharestack;
void sharestack1init(sharestack *s);
void sharestack2init(sharestack *s);
void sharestack1destroy(sharestack *s);
void sharestack2destroy(sharestack *s);
void sharestack1push(sharestack *s,stacktype value);
void sharestack2push(sharestack *s,stacktype value);
void sharestack1pop(sharestack *s);
void sharestack2pop(sharestack *s);
int sharestack1top(sharestack *s,stacktype *value);
int sharestack2top(sharestack *s,stacktype *value);
