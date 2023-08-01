#include<stdio.h>
#include<math.h>

int main(){
int i,num,sqrtnum;
int c,max;
int pcount = 0;
int increment = 1000000;
int progress = increment;

FILE *fp = fopen ("config.txt","r");
    fscanf(fp,"%d", &max);
    fclose(fp);

FILE *fpointer = fopen ("Primes.txt","w");
for(num=2;pcount<max;num++){
    c = 0;
    sqrtnum = sqrt(num);
    for(i=2;i<=sqrtnum;i++){
        if(num % i == 0){
            c++;
            break;
        }
    }
    if(c==0){
        pcount++;
        fprintf(fpointer,"%d -> %d\n",pcount,num);
        if(pcount == progress){
            printf("%d/%d\n",pcount,max);
            progress=progress+increment;
        }
    }
}
fclose(fpointer);
return 0;
}