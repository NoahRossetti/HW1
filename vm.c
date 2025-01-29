#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ARRAY_SIZE = 500;
int pas[ARRAY_SIZE]={0};

int base( int BP, int L)
{
int arb = BP; // arb = activation record base
while ( L > 0) //find base L levels down
{
arb = pas[arb];
L--;
}
return arb;
}


int main(){
int placeholder;
int op;
int eop = 1;
int bp = 499;
int sp = 500;
int pc = 10;
int i =10;



int ir[3];

FILE *inputfile = fopen("input", "r");

  // Lets us know if there is a problem retrieving file ( will remove later )
if(inputfile==NULL){
    printf("no file ");
}


// inserts instructions from file to pas array
while(fscanf(inputfile, "%d", &placeholder )){
     pas[i] = placeholder;
        i++;

}






  //This is where the execution steps will take place
  while(eop){
    //Places instructions from pas into the instruction register
    ir[0]=pas[pc];
    ir[1]=pas[pc+1];
    ir[2]=pas[pc+2];
    op = ir[0];
  switch(op){
    case 1:

    break;

    case 2:

    break;

    case 3:

    break;

    case 4:

    break;

    case 5:

    break;

    case 6:

    break;

    case 7:

    break;

    case 8:

    break;

    case 9:

    break;

  }
  }











}
