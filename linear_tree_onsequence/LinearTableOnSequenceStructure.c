/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "linear_list_interface.h"

/*--------------------page 10 on textbook ----------------------------------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status; 
typedef int ElemType;

/*--------------------page 22 on textbook ----------------------------------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
/*--------------------page 19 on textbook ----------------------------------*/
//status Initalist(SqList & L);
//status DestroyList(SqList & L);
//status ClearList(SqList &L);
//status ListEmpty(SqList L);
//int ListLength(SqList L);
//status GetElem(SqList L,int i,ElemType & e);
//status LocateElem(SqList L,ElemType e); 
//status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
//status NextElem(SqList L,ElemType cur,ElemType & next_e);
//status ListInsert(SqList & L,int i,ElemType e);
//status ListDelete(SqList & L,int i,ElemType & e);
//status ListTrabverse(SqList L);  
/*------------------------------------------------------*/
int main(void){
  SqList L;
  L.elem = NULL;
  int op=1;
  int e = 0;
  int i = 0;
  int ele = 0;
  while(op){
	system("clear");
    printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("------------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty      10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem        12. ListTraverse\n");
	printf("    	  0. Exit           13. LoadFile\n");
	printf("                            14. SaveFile\n");
	printf("------------------------------------------------------\n");
    printf("   请选择你的操作[0~14]:");
	scanf("%d",&op);
	if(!L.elem && op != 1){
		printf("You must initialize it!");
		getchar();
		getchar();
		continue;
	}
    switch(op){
	   case 1:
		 if(InitaList(&L) == OK){
			 printf("线性表创建成功\n");
		 }
		 else{
			 printf("线性表创建失败\n");
		 }
		 getchar();getchar();
		 break;
	   case 2:
		 if(DestroyList(&L) == OK){
			 printf("线性表破坏成功\n");
		 }
		 else{
			 printf("线性表破坏失败\n");
		 }     
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(&L) == OK){
			 printf("清空线性表成功\n");
		 }
		 else{
			 printf("线性表清空失败\n");
		 }   
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(&L) == TRUE){
			printf("线性表为空\n");
		 }
		 else if(ListEmpty(&L) == OVERFLOW){
			printf("线性表不存在\n");
		 }
		 else{
			 printf("线性表不为空\n");
		 }
		 getchar();getchar();
		 break;
	   case 5:
		 printf("%d\n", ListLength(&L));  
		 getchar();getchar();
		 break;
	   case 6:
		 printf("please enter the inidex of element:\n");
		 scanf("%d", &i);
		 if(GetElem(&L, i, &e) == 0){
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
		 if(LocateElem(&L, i, compare) == 0){
			 printf("No such element or the list is empty");
		 }
		 else{
			 printf("%d", LocateElem(&L, i, compare));
		 }     
		 getchar();getchar();
		 break;
	   case 8:
		 printf("please enter the index\n");
		 scanf("%d", &i);
		 if(PriorElem(&L, i, &e) == ERROR){
			 printf("The index is wrong or the list is empty");
		 }
		 else{
			 printf("%d", e);
		 }     
		 getchar();getchar();
		 break;
	   case 9:
	     printf("please enter the index\n");
		 scanf("%d", &i);
		 if(NextElem(&L, i, &e) == ERROR){
			 printf("The index is wrong or the list is empty");
		 }
		 else{
			 printf("%d", e);
		 }
		 printf("\n----NextElem功能待实现\n");     
		 getchar();getchar();
		 break;
	   case 10:
	     printf("please enter the index and the element\n");
		 scanf("%d%d", &i, &ele);
		 if(ListInsert_Sq(&L, i, ele) == ERROR){
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
		 if(ListDelete_Sq(&L, i, &e) == ERROR){
			 printf("The index is wrong!");
		 }
		 else{
			 printf("Success, and the element is %d", e);
		 }
		 getchar();getchar();
		 break;
	   case 12:
		 ListTraverse(&L);
		 getchar();getchar();
		 break;
	   case 13:
		 LoadFile(&L);
		 getchar();getchar();
		 break;
	   case 14:
	     SaveFile(&L);
		 getchar();getchar();
		 break;
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次使用本系统！\n");
  return 0;
}//end of main()

/*--------------------page 23 on textbook ----------------------------------*/
int InitaList(SqList * L){
	L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L->elem) exit(OVERFLOW);
	L->length=0;
    L->listsize=LIST_INIT_SIZE;
	return OK;
}


int  ListTraverse(SqList *L){
   if(!L->elem){
		return ERROR;
	}
   int i;
   printf("\n-------------------- all elements ------------------------------\n");
   for(i=0;i<L->length;i++) printf("%d ",L->elem[i]);
   printf("\n------------------------- end ----------------------------------\n");
   return L->length;
}

int DestroyList(SqList *L){
    if(L->elem){
        free(L->elem);
		L->elem = NULL;
    }
	else{
		return ERROR;
	}
    return OK;
}

int ClearList(SqList * L){
	if(!L->elem){
		return ERROR;
	}
    L->length = 0;
    return OK;
}

int ListEmpty(SqList * L){
	if(!L->elem){
		return OVERFLOW;
	}
    if(L->length == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

status ListLength(SqList *L){
    if(L->elem){
        return L->length;
    }
    else{
        return ERROR;
    }
}

int GetElem(SqList *L, int i, int *e){
	if(!L->elem){
		return ERROR;
	}
    if(i < 1 || i > L->length ){
        return ERROR;
    }
    ElemType *q = L->elem + i - 1;
	*e = *q;
    return SUCCESS;
}

int LocateElem(SqList *L, int e, int (*compare)(int a, int b)){
	if(!L->elem){
		return ERROR;
	}
	for(int i = 1; i <= L->length; i++){
		ElemType *q = L->elem + i - 1;
		if(compare(e, *q) != 0){
			return i;
		}
	}
	return FALSE;
}

int PriorElem(SqList * L, int cur_e, int * pre_e){
	if(!L->elem){
		return ERROR;
	}
	else{
		int i = LocateElem(L, cur_e, compare);
		if(i >= 2){
			*pre_e = *(L->elem + i - 2);
			return SUCCESS;
		}
		else{
			return ERROR;
		}
	}
}

int NextElem(SqList * L, int cur_e, int * next_e){
	if(!L->elem){
		return ERROR;
	}
	else{
		int i = LocateElem(L, cur_e, compare);
		if(i >= 1 && i < L->length){
			*next_e = *(L->elem + i);
			return SUCCESS;
		}
		else{
			return ERROR;
		}
	}
}

int ListInsert_Sq(SqList *L, int i, ElemType e){       /*Insert the new element before the location i*/
    if(!L->elem){
		return ERROR;
	}
	if(i < 1 || i > L->length + 1) return ERROR;
    if((L->length) * sizeof(ElemType) >= L->listsize){
        ElemType *newbase = (ElemType *)malloc((LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
        if(! newbase) exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType *q = L->elem + i - 1;
    for(ElemType *p = L->elem + L->length - 1; p >= q; --p){
        *(p + 1) = *p;
    }
    *q = e;
    ++L->length;
    return OK;
}

int ListDelete_Sq(SqList *L, int i,  int *e){
	if(!L->elem){
		return ERROR;
	}
    if((i < 1) || (i > L->length)) return ERROR;
    ElemType *q = L->elem + i - 1;
	*e = *q;
    for(ElemType *p = L->elem + i - 1; p < L->elem + L->length - 1; ++p){
        *p = *(p + 1);
    }
    --L->length;
    return OK;
}

int LoadFile(SqList *L){
	if(!L->elem){
		return ERROR;
	}
	FILE *fp;
    char filename[30];
    printf("input file name:");
    scanf("%s", filename);
    //读文件的方法 
    L->length=0;
    if ((fp=fopen(filename,"r"))==NULL)
	{
	    printf("File open erroe\n ");
	    return 1;
	}
    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
       L->length++;
    //这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读//取的数据元素恢复内存中的物理结构。
	fclose(fp);
	return OK;
}

int SaveFile(SqList *L){
	if(!L->elem){
		return ERROR;
	}
	//写文件
	FILE *fp;
	char filename[30];
	printf("input file name:");
	scanf("%s", filename);
  	fp=fopen(filename,"w");
    fwrite(L->elem,sizeof(ElemType),L->length,fp);
    //这里是1次性写入，对于其它物理结构，可通过遍历，逐个访问数据元素
    //并写入到文件中
	fclose(fp);
	return OK;
}

