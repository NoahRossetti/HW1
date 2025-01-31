/********************************************************
Overall TODO
- need to fix case 9 [done]
- fix up ALU		[done] (check it tho)
- check 3 and 4 for sign issues [done]
- run testcases[done (without printing all the activation records)
- make sure output perfect match(same as previous)

- ctrl f and remove TODO and other temporary comments
*********************************************************/






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

int ar_tracking[500];

int ir[3]={0};

FILE *inputfile = fopen("input", "r");

  // Lets us know if there is a problem retrieving file ( will remove later )
if(inputfile==NULL){
    printf("no file ");

	return 0;
}


// inserts instructions from file to pas array
while(fscanf(inputfile, "%d", &placeholder )==1){
     pas[i] = placeholder;
    //temporary printf(" %d ", pas[i]);
        i++;

}


printf("                 PC      BP      SP      stack");
printf("\ninitial values   %d     %d     %d", pc, bp, sp);

i=0;

  //This is where the execution steps will take place
  while(eop){


        //printf("\n %d %d %d %d %d %d\t", ir[0],ir[1],ir[2],pc,bp,sp);

       //printing out the pas

      // for(i=499; i>=sp; i--){
           // if(ar_tracking[i]==-1)
             //   printf("|");
            //printf(" %d ", pas[i]);


       //}


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
        //dont subtract ir[2]
      pas[sp]=pas[base(bp,ir[1])-ir[2]];

    break;

    case 4:

      pas[base(bp,ir[1])-ir[2]]=pas[sp];
      sp=sp+1;

    break;

    case 5:
        // one of the functions where ar is updated
      pas[sp-1]=base(bp,ir[1]);
      pas[sp-2]=bp;
      pas[sp-3]=pc;
      bp=sp-1;
        ar_tracking[bp]=-1;

      pc=ir[2];
        printf("\n");
    switch(ir[0]){

    case 1:
    printf("LIT");
    break;



    case 3:
     printf("LOD");
    break;

    case 4:
     printf("STO");
    break;

    case 5:
     printf("CAL");
    break;

    case 6:
     printf("INC");
    break;

    case 7:
     printf("JMP");
    break;

    case 8:
     printf("JPC");
    break;

    case 9:
     printf("SYS");
    break;



    case 2:
        switch(ir[2]) {

    case 0:
     printf("RTN");
    break;
    case 1:
     printf("ADD");
    break;

    case 2:
     printf("SUB");
    break;


    case 3:
     printf("MUL");
    break;

    case 4:
     printf("DIV");
    break;

    case 5:
     printf("EQL");
    break;

    case 6:
     printf("NEQ");
    break;

    case 7:
     printf("LSS");
    break;

    case 8:
     printf("LEQ");
    break;

    case 9:
     printf("GTR");
    break;

    case 10:
     printf("GEQ");
    break;




        }

    break;



    }
       printf("   %d %d \t %d\t%d\t%d    ", ir[0],ir[1],ir[2],pc,bp,sp);

       //printing out the pas

        for(i=499; i>=sp; i--){
            if(ar_tracking[i]==-1)
                printf("|");
            printf(" %d ", pas[i]);


        }

    continue;
    break;

    case 6:
      sp=sp-ir[2];

    break;

    case 7:
      pc=ir[2];
        printf("\n");
    switch(ir[0]){

    case 1:
    printf("LIT");
    break;



    case 3:
     printf("LOD");
    break;

    case 4:
     printf("STO");
    break;

    case 5:
     printf("CAL");
    break;

    case 6:
     printf("INC");
    break;

    case 7:
     printf("JMP");
    break;

    case 8:
     printf("JPC");
    break;

    case 9:
     printf("SYS");
    break;



    case 2:
        switch(ir[2]) {

    case 0:
     printf("RTN");
    break;
    case 1:
     printf("ADD");
    break;

    case 2:
     printf("SUB");
    break;


    case 3:
     printf("MUL");
    break;

    case 4:
     printf("DIV");
    break;

    case 5:
     printf("EQL");
    break;

    case 6:
     printf("NEQ");
    break;

    case 7:
     printf("LSS");
    break;

    case 8:
     printf("LEQ");
    break;

    case 9:
     printf("GTR");
    break;

    case 10:
     printf("GEQ");
    break;




        }

    break;



    }
       printf("   %d %d \t %d\t%d\t%d\t",ir[1],ir[2],pc,bp,sp);

       //printing out the pas

        for(i=499; i>=sp; i--){
            if(ar_tracking[i]==-1)
                printf("|");
            printf(" %d ", pas[i]);


        }

      continue;

    break;

    case 8:
      if(pas[sp]==0){
      pc=ir[2];
      sp=sp+1;
        printf("\n");
    switch(ir[0]){

    case 1:
    printf("LIT");
    break;



    case 3:
     printf("LOD");
    break;

    case 4:
     printf("STO");
    break;

    case 5:
     printf("CAL");
    break;

    case 6:
     printf("INC");
    break;

    case 7:
     printf("JMP");
    break;

    case 8:
     printf("JPC");
    break;

    case 9:
     printf("SYS");
    break;



    case 2:
        switch(ir[2]) {

    case 0:
     printf("RTN");
    break;
    case 1:
     printf("ADD");
    break;

    case 2:
     printf("SUB");
    break;


    case 3:
     printf("MUL");
    break;

    case 4:
     printf("DIV");
    break;

    case 5:
     printf("EQL");
    break;

    case 6:
     printf("NEQ");
    break;

    case 7:
     printf("LSS");
    break;

    case 8:
     printf("LEQ");
    break;

    case 9:
     printf("GTR");
    break;

    case 10:
     printf("GEQ");
    break;




        }

    break;



    }
       printf("   %d %d  \t %d\t%d\t%d\t",ir[1],ir[2],pc,bp,sp);

       //printing out the pas

        for(i=499; i>=sp; i--){
            if(ar_tracking[i]==-1)
                printf("|");
            printf(" %d ", pas[i]);


        }

      continue;
      }

    break;

    case 9:
      if(ir[2]==1){
      printf("\nOutput result is: %d", pas[sp]);
      sp=sp+1;
      }
       else if(ir[2]==2){

        sp--;
        printf("\nPlease Enter an Integer: ");
	scanf(" %d", &pas[sp]);

	//printf("");//debuggy

      }
      else if(ir[2]==3){
        eop=0;
      }



    break;

   //Arithmentic operations in case 02 and will vary based on L

   case 2:
       //one of the functions where ar is updated
    if(ir[1]==0&&ir[2]==0){
      sp=bp+1;
      bp=pas[sp-2];
      pc=pas[sp-3];

     break;
    }
    else{

    switch(ir[2]){

		case 1: //ADD
			pas[sp + 1] = pas[sp + 1] + pas[sp];
	 		sp++;
	  		break;

	case 2: //SUB
			pas[sp + 1] = pas[sp + 1] - pas[sp];
	 		sp++;
	  		break;

	case 3: //MUL
			pas[sp + 1] = pas[sp + 1] * pas[sp];
	 		sp++;
	  		break;

	case 4: //DIV
			pas[sp + 1] = pas[sp + 1] / pas[sp];
	 		sp++;
	  		break;

	case 5: //EQL
			if(pas[sp + 1] == pas[sp])
	 		{
	  			pas[sp + 1] = 1; // im assuming 1 for "is equal" and 0 for "not equal" TODO
		  	}
			else pas[sp + 1] = 0;

			sp++;
	     	break;

	case 6: //NEQ
			if(pas[sp + 1] != pas[sp])
	 		{
	  			pas[sp + 1] = 1; // im assuming 1 for "not equal" and 0 for "equal" TODO
	  		}
			else pas[sp + 1] = 0;

	   		sp++;
	   		break;

	case 7: //LSS
		if(pas[sp + 1] < pas[sp])
	 	{
	  		pas[sp + 1] = 1; // im assuming 1 for "less" and 0 for "greater" TODO
	  	}
		else pas[sp + 1] = 0;

	   sp++;

	   break;

	case 8: //LEQ
			if(pas[sp + 1] <= pas[sp])
	 		{
	  			pas[sp + 1] = 1; // im assuming 1 for "less than or equal" and 0 for "not that" TODO
	  		}
			else pas[sp + 1] = 0;

	   		sp++;
			break;

	case 9: //GTR
			if(pas[sp + 1] > pas[sp])
	 		{
	  			pas[sp + 1] = 1; // im assuming 1 for "greater" and 0 for "not that" TODO
	  		}
			else pas[sp + 1] = 0;

	   		sp++;
	   		break;

	case 10: //GEQ
			if(pas[sp + 1] >= pas[sp])
	 		{
	  			pas[sp + 1] = 1; // im assuming 1 for "greater" and 0 for "not that" TODO
		  	}
			else pas[sp + 1] = 0;

	   		sp++;
			break;


    }
    
  }
    printf("\n");
    switch(ir[0]){

    case 1:
    printf("LIT");
    break;



    case 3:
     printf("LOD");
    break;

    case 4:
     printf("STO");
    break;

    case 5:
     printf("CAL");
    break;

    case 6:
     printf("INC");
    break;

    case 7:
     printf("JMP");
    break;

    case 8:
     printf("JPC");
    break;

    case 9:
     printf("SYS");
    break;



    case 2:
        switch(ir[2]) {

    case 0:
     printf("RTN");
    break;
    case 1:
     printf("ADD");
    break;

    case 2:
     printf("SUB");
    break;


    case 3:
     printf("MUL");
    break;

    case 4:
     printf("DIV");
    break;

    case 5:
     printf("EQL");
    break;

    case 6:
     printf("NEQ");
    break;

    case 7:
     printf("LSS");
    break;

    case 8:
     printf("LEQ");
    break;

    case 9:
     printf("GTR");
    break;

    case 10:
     printf("GEQ");
    break;




        }

    break;



    }

     printf("   %d %d \t %d \t%d \t%d\t",ir[1],ir[2],pc,bp,sp);

       //printing out the pas

        for(i=499; i>=sp; i--){
            if(ar_tracking[i]==-1)
                printf("|");
            printf(" %d ", pas[i]);


        }

  pc=pc+3;

  }











}


