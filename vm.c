


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int eop = 1
int bp = 499;
int sp = 500;
int pc = 10;
const int ARRAY_SIZE = 500;
int Stack[ARRAY_SIZE];
int IR[3];
int PAS[ARRAY_SIZE];
FILE *inputfile = fopen("input", "r");

  // Lets us know if there is a problem retrieving file ( will remove later )
if(inputfile==NULL){
    printf("no file ");
}

  
// inserts instructions from file to pas array
while(fscanf(inputfile, "%d", &placeholder )){
     PAS[i] =placeholder;
        i++;

}


}



  
  while(eop){
  switch{
  



    
  }
  }











}
