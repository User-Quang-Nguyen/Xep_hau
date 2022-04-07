#include<stdio.h>
int x[100];
int check(int v, int k){
    for(int i = 1;i<=k-1;i++){
            if(x[i] == v) return 0;
            if(x[i]+i == v+k) return 0;
            if(x[i]-i == v-k) return 0;
        }
    return 1;
}

void print(){
    for(int i=1;i<=4;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}

void try(int k){
    for(int i = 1;i<=4;i++){
        if(check(i,k)){
            x[k] = i;
            if(k == 4) print();
            else try(k+1);
        }
    }
}

int main()
{
    try(1);
    return 0;
}