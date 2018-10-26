#include <stdio.h>
#include "linked_list.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int op=1;
  int e = 0;
  int i = 0;
  int ele = 0;
  LkList *l = NULL;
  LkList L[10];
  for(int j = 0; j<10; j++){
      L[j].elem = -1;
  }
  l = L;
  while(op){
	system("clear");
    printf("\n\n");
	printf("      Menu for Linear Table On List Structure \n");
	printf("------------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty      10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem        12. ListTraverse\n");
	printf("    	  0. Exit           13. LoadFile\n");
	printf("          15. ChangeList    14. SaveFile\n");
	printf("------------------------------------------------------\n");
    printf("   Please choose your operation[0~14]:");
	scanf("%d",&op);
	if(l->elem == -1 && op != 1 && op != 0){
		printf("You must initialize it!");
		getchar();
		getchar();
		continue;
	}
    switch(op){
	   case 1:
		 if(InitaList(l) == SUCCESS){
			 printf("Initializing succeed!\n");
		 }
		 else{
			 printf("Initializing fail!\n");
		 }
		 getchar();getchar();
		 break;
	   case 2:
		 if(DestroyList(l) == SUCCESS){
			 printf("Destroying succeed\n");
		 }
		 else{
			 printf("Destroying fail\n");
		 }     
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(l) == SUCCESS){
			 printf("Clearing succeed\n");
		 }
		 else{
			 printf("Clearing failed\n");
		 }   
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(l) == TRUE){
			printf("The linear list is empty\n");
		 }
		 else{
			 printf("The linear list is not empty\n");
		 }
		 getchar();getchar();
		 break;
	   case 5:
		 printf("%d\n", ListLength(l));  
		 getchar();getchar();
		 break;
	   case 6:
		 printf("please enter the inidex of element:\n");
		 scanf("%d", &i);
		 if(GetElem(l, i, &e) == 0){
			printf("index is wrong or the list is empty");
		 }
		 else{
			printf("%d\n", e);
		 }
		 getchar();getchar();
		 break;
	   case 7:
		 printf("please enter the element\n");
		 scanf("%d", &i);
		 if(LocateElem(l, i, compare) == 0){
			 printf("No such element or the list is empty");
		 }
		 else{
			 printf("%d", LocateElem(l, i, compare));
		 }     
		 getchar();getchar();
		 break;
	   case 8:
		 printf("please enter the element\n");
		 scanf("%d", &i);
		 if(PriorElem(l, i, &e) == FAILURE){
			 printf("The index is wrong or the list is empty");
		 }
		 else{
			 printf("%d", e);
		 }     
		 getchar();getchar();
		 break;
	   case 9:
	     printf("please enter the element\n");
		 scanf("%d", &i);
		 if(NextElem(l, i, &e) == FAILURE){
			 printf("The index is wrong or the list is empty");
		 }
		 else{
			 printf("%d", e);
		 } 
		 getchar();getchar();
		 break;
	   case 10:
	     printf("please enter the index and the element\n");
		 scanf("%d%d", &i, &ele);
		 if(ListInsert(l, i, ele) == FAILURE){
			 printf("The index is wrong");
		 }
		 else{
			 printf("Success!");
		 }  
		 getchar();getchar();
		 break;
	   case 11:
		 printf("Please enter the index you want to delete\n");
		 scanf("%d", &i);
		 if(ListDelete(l, i, &e) == FALSE){
			 printf("The index is wrong!");
		 }
		 else{
			 printf("Success, and the element is %d", e);
		 }
		 getchar();getchar();
		 break;
	   case 12:
		 ListTraverse(l);
		 getchar();getchar();
		 break;
	   case 13:
		 LoadFile(l);
		 getchar();getchar();
		 break;
	   case 14:
	     SaveFile(l);
		 getchar();getchar();
		 break;
       case 15:
         printf("Please enter the index of list\n");
         int num;
         scanf("%d", &num);
         if(num > 10){
            printf("The index is wrong");
            getchar();getchar();
            break;
         }
         l = L + (num - 1);
         getchar();getchar();
         break;
         
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("Welcome to use the system again\n");
  return 0;
}//end of main()


int InitaList(LkList *l){
    l->next = NULL;
    l->elem = 1;
    return 1;
}

int DestroyList(LkList *l){
    LkList *p = l;
    LkList *q = NULL;
    p = p->next;
    while(p->next != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    free(q);
    l->elem = -1;
    return SUCCESS;
}

int ClearList(LkList *l){
    LkList *p = l;
    LkList *q = NULL;
    p = p->next;
    while(p->next != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    free(p);
    l->next = NULL;
    return SUCCESS;
}

int ListEmpty(LkList *l){
    if(l->next == NULL){
        return TRUE;
    }
    return FALSE;
}

int ListLength(LkList *l){
    int i = 0;
    LkList *p = l;
    while(p->next != NULL){
        i = i + 1;
        p = p->next;
    }
    return i;
}

int GetElem(LkList *l, int i, int *e){
    if(1 <= i && i <= ListLength(l)){
        int k = i;
        LkList *p = l;
        for(k = i; k > 0; k--){
            p = p->next;
        }
        *e = p->elem; 
        return *e;
    }
    return FAILURE;
}

int LocateElem(LkList * l, int e, int (* compare) (int a, int b)){
    LkList *p = l;
    int i = 0;
    while(p->next != NULL){
        p = p->next;
        i += 1;
        if(compare(p->elem, e) == TRUE){
           return i;  
        }
    }
    return FAILURE;
}

int PriorElem(LkList * l, int cur_e, int * pre_e){
    LkList *p = l;
    LkList *q = NULL;
    int  i = 0;
    while(p->next != NULL){
        q = p;
        p = p->next;
        if(compare(p->elem, cur_e) == TRUE && i != 0){
            *pre_e = q->elem;
            return *pre_e;
        }
        i += 1;
    }
    return FAILURE;
}

int NextElem(LkList *l, int cur_e, int * next_e){
    int i = LocateElem(l, cur_e, compare);
    LkList *p = l;
    if(i != 0 && i < ListLength(l)){
        for(int k = i; k > 0; k--){
            p = p->next;
        }
        p = p->next;
        *next_e = p->elem;
        return *next_e;
    }
    return FAILURE;
}

int ListInsert(LkList *l, int i, int e){
    LkList *p = l;
    LkList *q = NULL;
    LkList *z = NULL;
    if(1 <= i && i <= ListLength(l) + 1){
        for(int k = i; k > 1; k--){
            p = p->next;
            printf("1");
        }
        if(p->next == NULL){
            z = (LkList *)malloc(sizeof(LkList));
            z->elem = e;
            z->next = NULL;
            p->next = z;
        }
        else{
            q = p;
            z = (LkList *)malloc(sizeof(LkList));
            p = p->next;
            z->elem = e;
            z->next = p;
            q->next = z;
        }
        return SUCCESS;
    }
    return FAILURE;
}

int ListDelete(LkList *l, int i, int *e){
    LkList *p = l;
    LkList *q = NULL;
    LkList *z = NULL;
    if(i >= 1 && i <= ListLength(l)){
        for(int k = i; k > 1; k--){
            p = p->next;
        }
        q = p;
        p = p->next;
        z = p->next;
        q->next = z;
        *e = p->elem;
        free(p);
        return SUCCESS;
    }
    return FAILURE;
}

int ListTraverse(LkList * l){
    LkList *p = l;
    while(p->next != NULL){
        p = p->next;
        printf("%d  ", p->elem);
    }
}

int LoadFile(LkList *l){
    LkList *p = l;
    LkList *z = (LkList *)malloc(sizeof(LkList));
    z->next = NULL;
    p->next = z;
    p = p->next;
	if(!l->elem){
		return FAILURE;
	}
	FILE *fp;
    char filename[30];
    printf("input file name:");
    scanf("%s", filename);
    //read the file
    if ((fp=fopen(filename,"r"))==NULL)
	{
	    printf("File open erroe\n ");
	    return 1;
	}
    while(fread(p,sizeof(int),1,fp)){
        z = (LkList *)malloc(sizeof(LkList));
        z->next = NULL;
        p->next = z;
        p = p->next;
    }
    int e = 0;
    ListDelete(l, ListLength(l), &e);
	fclose(fp);
	return SUCCESS;
}

int SaveFile(LkList *l){
    LkList *p = l;
	//写文件
	FILE *fp;
	char filename[30];
	printf("input file name:");
	scanf("%s", filename);
  	fp=fopen(filename,"w");
    while(p->next != NULL){
        p = p->next;
        fwrite(p, sizeof(int), 1, fp);
    }
	fclose(fp);
	return SUCCESS;
}




