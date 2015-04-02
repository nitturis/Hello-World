#include <stdio.h>
#include <stdlib.h>

struct mypointers
{
int key;
struct mypointers *pNxt;
}*pHead,*pTailCache,*pNewHead;
#define free_mem(ph) printf("will implement free here\n")
#define MAX_ELEMENTS 10

printKeys(struct mypointers *pH)
{
  int j=0;
  struct mypointers *pTmp=pH;
  printf("--------------------\n ");
  while(pTmp){
    printf("%.4d : Keyvalue %.4d \n ",j++,pTmp->key);
    pTmp = pTmp->pNxt;
    
  }
  printf("--------------------\n ");
}

reverselist()
{ 
  
  struct mypointers *pCurr;
  int i=0; 	
  while(pHead){
     pCurr = pHead;
     pHead = pCurr->pNxt; //move head to next element
     //pNewHead   = pCurr; 
     if(0 == i++){
       pNewHead   = pCurr;
       pCurr->pNxt = NULL; //make this as last element..imp 
     } else{
       pCurr->pNxt = pNewHead;
       pNewHead  = pCurr; 
     }
  }
}

main()
{
  struct mypointers *pCurr; 	
  int i;
  //allocate 10 pointes and add to head
  for (i=0;i<MAX_ELEMENTS;i++) {
    pCurr = (struct mypointers *) malloc(sizeof(struct mypointers));
    if(NULL == pCurr){
       printf("there is no mem\n");
       free_mem(pHead);
       return -1; // there is error	
    }
    //init data
    pCurr->key = i*5;
    pCurr->pNxt=NULL;	
    //add to head
    if(i ==0){
      pHead = pCurr; //due to first element
      pTailCache = pCurr;
    }else{
      pTailCache->pNxt = pCurr;	
      pTailCache = pCurr;
    }
      
  }

  printKeys(pHead);	
  
  //reverse order
  reverselist();
   
  printKeys(pNewHead);	
  pCurr = pNewHead;
  while(pCurr){
     free(pCurr);
     pCurr = pCurr->pNxt ;
  }
}
