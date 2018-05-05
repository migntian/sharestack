#include <stdio.h>
#include "sharestack.h"

void sharestack1init(sharestack *s)
{
    if(s == NULL)
    {
        return;//非法输入
    }
    s->stack1 = 0;
}
void sharestack2init(sharestack *s)
{
    if(s == NULL)
    {
        return;//非法输入
    }
    s->stack2 = MAXSIZE;
}
void print1(sharestack *s)
{
    if(s == NULL)
    {
        return;
    }
    if(s->stack1 == 0 || s->stack2 == 0)
    {
        return;//栈1 空
    }
    size_t i = 0;
    for(i = 0;i < s->stack1;i++)
    {
        printf("[%c] ",s->data[i]);
    }
    printf("\n");
}
void print2(sharestack *s)
{
    if(s == NULL)
    {
        return;
    }
    if(s->stack1 == MAXSIZE || s->stack2 == MAXSIZE)
    {
        return;//栈2 空
    }
    size_t i = MAXSIZE-1;
    for(;i >= s->stack2;i--)
    {
        printf("[%c] ",s->data[i]);
    }
    printf("\n");
}
void sharestack1push(sharestack *s,stacktype value)
{
    if(s == NULL)
    {
        return;
    }
    if(s->stack1 >= s->stack2 || s->stack1 == MAXSIZE)
    {
        return;
    }
    s->data[s->stack1++] = value;
}
void sharestack2push(sharestack *s,stacktype value)
{
    if(s == NULL)
    {
        return;
    }
    if(s->stack2 <= s->stack1 || s->stack2 == 0)
    {
        return;
    }
    s->data[--s->stack2] = value;
}

void sharestack1pop(sharestack *s)
{
    if(s == NULL)
    {
        return;
    }
    if(s->stack1 ==0 || s->stack2 == 0)
    {
        return;//空栈
    }
    --s->stack1;


}
void sharestack2pop(sharestack *s)
{
    if(s == NULL)
    {
        return;
    }
    if(s->stack1 == MAXSIZE || s->stack2 == MAXSIZE)
    {
        return;
    }
    ++s->stack2;
}
int sharestack1top(sharestack *s,stacktype *top)
{
    if(s == NULL || top == NULL)
    {
        return 0;
    }
    if(s->stack1 == 0 || s->stack2 == 0)
    {
        return 0;
    }
    *top = s->data[s->stack1-1];
    return 1;
}
int sharestack2top(sharestack *s,stacktype *top)
{
    if(s == NULL || top == NULL)
    {
        return 0;
    }
    if(s->stack2 == MAXSIZE || s->stack1 == MAXSIZE)
    {
        return 0;
    }
    *top = s->data[s->stack2];
    return 1;
}
void sharestack1destroy(sharestack *s)
{
    if(s == NULL)
    {
        return;
    }
    s->stack1 = 0;
}
void sharestack2destroy(sharestack *s)
{
    if(s == NULL)
    {
        return;
    }
    s->stack2 = MAXSIZE;

}

///////////////////
//测试
///////////////////


void test()
{
    HEADER;
    sharestack s;
    sharestack1init(&s);
    sharestack2init(&s);
    sharestack1push(&s,'a');
    sharestack1push(&s,'b');
    sharestack1push(&s,'c');
    sharestack1push(&s,'d');
    print1(&s);
    stacktype top1;
    int ret1 = sharestack1top(&s,&top1);
    printf("except is 1,actul is %d\n",ret1);
    printf("except is d,actul is %c\n",top1);
    sharestack2push(&s,'q');
    sharestack2push(&s,'w');
    sharestack2push(&s,'e');
    sharestack2push(&s,'r');
    print2(&s);
    stacktype top2;
    int ret2 = sharestack2top(&s,&top2);
    printf("except is 1,actul is %d\n",ret2);
    printf("except is r,actul is %c\n",top2);
}

int main()
{
    test();
    return 0;
}
