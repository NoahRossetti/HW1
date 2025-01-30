#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ARRAY_SIZE = 500;

int pas[500]={0};

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



int ir[3]={0};

FILE *inputfile = fopen("input", "r");

  // Lets us know if there is a problem retrieving file ( will remove later )
if(inputfile==NULL){
    printf("no file ");

	return 0;
}


// inserts instructions from file to pas array
while(fscanf(inputfile, "%d", &placeholder )){
     pas[i] = placeholder;
        i++;

}



printf("initial values %d\t%d\t%d", pc, bp, sp);

i=0;
  //This is where the execution steps will take place
  while(eop){

        //printf("we loopin ");
        printf(" %d %d %d %d %d %d\n", ir[0],ir[1],ir[2],pc,bp,sp);
    //Places instructions from pas into the instruction register
    ir[0]=pas[pc];
    ir[1]=pas[pc+1];
    ir[2]=pas[pc+2];
    op = ir[0];
  switch(op){
    case 1:
      sp=sp-1;
      pas[sp]=ir[2];

    break;



    case 3:
      sp=sp-1;
      //might need to flip signs
      pas[sp]=pas[base(bp,ir[1])]-ir[2];

    break;

    case 4:
      //might need to flip signs for directly below
      pas[base(bp,ir[1])-ir[2]]=pas[sp];
      sp=sp+1;

    break;

    case 5:
      pas[sp-1]=base(bp,ir[1]);
      pas[sp-2]=bp;
      pas[sp-3]=pc;
      bp=sp-1;
      pc=ir[2];
    continue;
    break;

    case 6:
      sp=sp-ir[2];

    break;

    case 7:
      pc=ir[2];
      continue;

    break;

    case 8:
      if(pas[sp]==0){
      pc=ir[2];
      }
      sp=sp-1;
    break;

    case 9:
      if(ir[2]==1){
      printf("%d", pas[sp]);
      sp=sp+1;
      }
       else if(ir[2]==2){
         //not sure what to do here

      }
      else if(ir[2]==3){
        eop=0;
      }



    break;

    //Arithmentic operations will go in case 0 and will vary based on l
   case 2:
    if(ir[1]==0&&ir[2]==0){
      sp=bp+1;
      bp==pas[sp-2];
      pc=pas[sp-3];
     break;
    }
    else{
    switch(ir[1]){
      case 1:
      pas[sp+1]=pas[sp+1]+pas[sp];
      sp=sp+1;

      break;
      case 2:
      pas[sp+1]=pas[sp+1] - pas[sp];
      sp=sp+1;

      break;
      case 3:
      pas[sp+1]= pas[sp+1]*pas[sp];
      sp=sp+1;

      break;
      case 4:
      pas[sp+1]= pas[sp+1]/pas[sp];
      sp=sp+1;

      break;
      case 5:
      pas[sp+1]= pas[sp+1]==pas[sp];
      sp=sp+1;

      break;
      case 6:
      pas[sp+1]= pas[sp+1]!=pas[sp];
      sp=sp+1;

      break;
      case 7:
      pas[sp+1]= pas[sp+1]<pas[sp];
      sp=sp+1;

      break;
      case 8:

      pas[sp+1]= pas[sp+1]<=pas[sp];

      sp=sp+1;

      break;
      case 9:
      pas[sp-+1]= pas[sp+1]>pas[sp];
      sp=sp+1;

      break;
      case 10:
      pas[sp+1]= pas[sp-+1]>=pas[sp];
      sp=sp+1;

      break;
    }
    }
    //break;
  }

  pc=pc+3;
  i++;
  if(i==50) break;
  }











}

