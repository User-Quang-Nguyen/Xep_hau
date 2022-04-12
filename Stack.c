#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node{
    char c;
    struct Node* next;
}Node;

Node* first ;

int empty(Node*h){
    return h == NULL;
}

Node* makenode(char c){
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = c;
    p->next = NULL;
    return p;
}

Node* push(char c,Node* h){
    Node* p = makenode(c);
    if(h == NULL){
        h = p;
    }
    else{
    p->next = h;
    h = p;
    }
    return h;
}

char pop(Node* h){
    Node* p = h;
    char x = p->c;
    if(p == NULL) return p->c;
    h = p->next;
    free(p);
    return x;
}

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '{' && b == '}') return 1;
    if(a == '[' && b == ']') return 1;
    return 0;
}
void print(Node* h){
    if(h == NULL) printf("ERROR");
    while(h!=NULL){
        printf("%c",h->c);
        h = h->next;
    }
}
int solve(char* x,int n,Node* h){
    for(int i = 0 ; i < n ; i++){
        if(x[i] == '{' || x[i] == '[' || x[i] == '(') { printf("%c",x[i]);
            push(x[i],h);
        }
        else{
            char c;
            if(empty(h)) return 0;
            printf("2");
            c = pop(h);
            if(match(x[i],c) == 0) return 0;
        }
    }
    if(!empty(h)) return 0;
    return 1;
}

int main()
{
    int n = 8;
    char x[10] = "[({})]()";
    int a ;
//    a = solve(x,n,first);
    push('a',first);
    push('b',first);
    push('c',first);
    print(first);
    printf("\n%d",a);
    // day la dong them vao
}
