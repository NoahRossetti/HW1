/********************************************************
Overall TODO
- need to fix case 9 [done]
- fix up ALU		[done] (check it tho)
- check 3 and 4 for sign issues
- run testcases
- make sure output perfect match

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
    printf(" %d ", pas[i]);
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
    case 1: //LIT - push constant value M onto the stack
      sp=sp-1;
      pas[sp]=ir[2];

    break;

    case 3:// LOD L,M  - load value to the top of the stack (or return from fucntion)
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
      //temporary solution
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
      sp=sp+1;
      continue;
      }

    break;

    case 9:
      if(ir[2]==1){
      printf("%d", pas[sp]);
      sp=sp+1;
      }
       else if(ir[2]==2){
        
        sp--;
	scanf("%c", stack[sp]);

	printf//debuggy
	
      }
      else if(ir[2]==3){
        eop=0;
      }



    break;

   //Arithmentic operations in case 02 and will vary based on L
	  
   case 2: //NGL idk what this is checking for
	   //but tbf I can see the hat man rn im so sleep deprived TODO
    if(ir[1]==0&&ir[2]==0){
      sp=bp+1;
      bp==pas[sp-2];
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

/*		// previous cases
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
      pas[sp+1]= pas[sp+1]>pas[sp];
      sp=sp+1;

      break;
      case 10:
      pas[sp+1]= pas[sp+1]>=pas[sp];
      sp=sp+1;

      break;
    }
    }
    //break;
  }

  */

  pc=pc+3;
  i++;
  if(i==50) break;
  }











}

/****************************************************
	case 1: //ADD
		pas[sp + 1] = pas[sp + 1] + pas[sp];
	 	sp++;
	  	break;
	   
	case 2: //SUB
		pas[sp + 1] = pas[sp + 1] - pas[sp];
	 	sp++;
	  	break;
	   
	case3: //MUL
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
*******************************************************/
