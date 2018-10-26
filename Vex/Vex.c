#include <stdio.h>
#include "Vex.h"
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int op=1;
  int e = 0;
  int i = 0;
  int u, v;
  int index;
  LinkQueue T;
  LinkQueue * Q = &T;
  ALGraph *l = NULL;
  ALGraph L[10];
  for(int j = 0; j<10; j++){
      L[j].kind= -1;
  }
  l = L;
  while(op){
	system("clear");
    printf("\n\n");
	printf("          Menu for Vex On Adjacency list \n");
	printf("------------------------------------------------------\n");
	printf("    	  1. initGraph       7. FirstAdjVex\n");
	printf("    	  2. CreateGraph     8. NextAdjVex\n");
	printf("    	  3. DestroyGraph    9. InsertVex \n");
	printf("    	  4. LocateVex      10. DeleteVex\n");
	printf("    	  5. GetVex         11. InsertArc\n");
	printf("    	  6. PutVex         12. DeleteArc\n");
	printf("    	  0. Exit           13. DFSTraverse\n");
	printf("          15. ChangeList    14. BFSTraverse\n");
	printf("------------------------------------------------------\n");
    printf("   Please choose your operation[0~14]:");
	scanf("%d",&op);
	if(l->kind == -1 && op != 1 && op != 0){
		printf("You must initialize it!");
		getchar();
		getchar();
		continue;
	}
    switch(op){
	   case 1:
		 if(initGraph(l) == SUCCESS){
			 printf("Initializing succeed!\n");
		 }
		 else{
			 printf("Initializing fail!\n");
		 }
		 getchar();getchar();
		 break;
	   case 3:
		 if(DestroyGraph(l) == SUCCESS){
			 printf("Destroying succeed\n");
		 }
		 else{
			 printf("Destroying fail\n");
		 }     
		 getchar();getchar();
		 break;
	   case 2:
         printf("Please enter the number of node and the number of relation node\n");
         scanf("%d%d", &u, &v);
         int * V = (int *)malloc(sizeof(int));
         int (*VR)[2] = (int(*)[2])malloc(sizeof(int)*v * 2);
         for(int i = 0; i < u; i++){
             printf("Please enter the value of the node\n");
             scanf("%d", &V[i]);
         }
         for(int i = 0; i < v; i++){
             printf("Please enter the node which has realtions\n");
             scanf("%d%d",&VR[i][0], &VR[i][1]);
         }
		 if(CreateGraph(l, u, V, v, VR) == SUCCESS){
			 printf("Creating succeed\n");
		 }
		 else{
			 printf("Creating failed\n");
		 }   
		 getchar();getchar();
		 break;
	   case 4:
		 printf("Please enter the index of it\n");
         scanf("%d", &index);
         e = LocateVex(l, index);
         if(e == -1){
             printf("The index is wrong\n");
         }
         else{
             printf("%d", e);
         }

		 getchar();getchar();
		 break;
	   case 5:
         printf("Please enter the index of it\n");
         scanf("%d", &index);
		 e = GetVex(l, index);
         if(e == FALSE){
             printf("The index of it is wrong\n");
         }
         else{
             printf("%d", e);
         }
		 getchar();getchar();
		 break;
	   case 6:
		 printf("please enter the inidex of element and the value of it:\n");
		 scanf("%d%d", &u, &v);
		 if(PutVex(l, u, v) == FALSE){
			printf("index is wrong");
		 }
		 else{
            printf("SUCCESS!");
		 }
		 getchar();getchar();
		 break;
	   case 7:
		 printf("please enter the index\n");
		 scanf("%d", &index);
         e = FirstAdjVex(l, index);
		 if(e == FALSE){
			 printf("The index is wrong");
		 }
		 else{
			 printf("%d", e);
		 }     
		 getchar();getchar();
		 break;
	   case 8:
		 printf("please enter the index1 and the index2\n");
		 scanf("%d%d", &u, &v);
         e = NextAdjVex(l, u, v);
		 if(e == FALSE){
			 printf("The index is wrong");
		 }
		 else{
			 printf("%d", e);
		 }     
		 getchar();getchar();
		 break;
	   case 9:
	     printf("please enter the value\n");
		 scanf("%d", &u);
		 if(InsertVex(l, u) == SUCCESS){
             printf("SUCCESS!");
         }
		 getchar();getchar();
		 break;
	   case 10:
	     printf("please enter the index\n");
		 scanf("%d", &index);
         e = DeleteVex(l, index);
		 if(e == FALSE){
			 printf("The index is wrong");
		 }
		 else{
			 printf("Success!");
		 }  
		 getchar();getchar();
		 break;
	   case 11:
		 printf("Please enter the index of two\n");
		 scanf("%d%d", &u, &v);
		 if(InsertArc(l, u, v) == FALSE){
			 printf("failed!");
		 }
		 else{
			 printf("Success");
		 }
		 getchar();getchar();
		 break;
	   case 12:
         printf("Please enter the index of two");
         scanf("%d%d", &u, &v);
         if(DeleteArc(l, u, v) == TRUE){
             printf("the delete succeed");
         }
         else{
             printf("failed");
         }
		 getchar();getchar();
		 break;
	   case 13:
		 DFSTraverse(l, visit);
		 getchar();getchar();
		 break;
	   case 14:
	     BFSTraverse(l, Q, visit);
		 getchar();getchar();
		 break;
	   case 0:
         break;
       case 15:
         printf("Please enter the index of list\n");
         int num;
         scanf("%d", &num);
         if(num > 10 || num <= 0){
            printf("The index is wrong");
            getchar();getchar();
            break;
         }
         l = L + (num - 1);
         getchar();getchar();
         break;
	}//end of switch
  }//end of while
  printf("Welcome to use the system again\n");
  return 0;
}//end of main()

int initGraph(ALGraph * G){
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        (G->vertices + i)->data = -1;
        (G->vertices + i)->firstarc = NULL;
        (G->vertices + i)->index = -1;
    }
    G->arcnum = 0;
    G->vexnum = 0;
    G->kind = 0;
    return SUCCESS;
}
int CreateGraph(ALGraph * G, int length_Node, int * V, int rela_Node, int VR[][2]){
    G->vexnum = 0;
    G->arcnum = 0;
    int a = 0;
    int b = 0;
    for(int i = 0; i < length_Node; i++){
        (G->vertices + i)->data = *(V + i);
        (G->vertices + i)->index = i;
    }
    for(int i = 0; i < rela_Node; i++){
        a = VR[i][0];
        b = VR[i][1];
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = b;
        p->nextarc = NULL;
        if((G->vertices + a)->firstarc == NULL){
            (G->vertices + a)->firstarc = p;
        }
        else{
            ArcNode *temp = (G->vertices + a)->firstarc;
            while(temp->nextarc != NULL){
                temp = temp->nextarc;
            }
            temp->nextarc = p;
        }
    }
    G->vexnum = length_Node;
    G->arcnum = rela_Node;
    return SUCCESS;
}
int DestroyGraph(ALGraph * G){
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        ArcNode * p = (G->vertices + i)->firstarc;
        ArcNode * t = NULL;
        if(p == NULL){
        }
        else{
            t = p;
            while(t->nextarc != NULL){
                t = t->nextarc;
                p->nextarc = t->nextarc;
                free(t);
                t = p; 
            }
            free(p);
        }
    VNode * T = (G->vertices + i);
    T->data = -1;
    T->firstarc = NULL;
    T->index = -1;
    }
    G->kind = -1;
    return SUCCESS;
}
int LocateVex(ALGraph * G, int index){
    int p = 0;
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        if((G->vertices + i)->index == index){ 
            return i;
        }
    }
    return FALSE;
}
int compare(VNode * u, VNode * v){
    if(u->firstarc->adjvex == u->firstarc->adjvex){
        ArcNode * Q = u->firstarc;
        ArcNode * T = v->firstarc;
        while(Q->nextarc != NULL){
            Q = Q->nextarc;
            T = T->nextarc;
            if(Q->adjvex != T->adjvex){
                break;
            }
            if(Q->nextarc == NULL && T->nextarc == NULL){
                 return TRUE;
            }
        }
    }
    return FALSE;
}
int GetVex(ALGraph * G, int index){
    int i = LocateVex(G, index);
    if(i == -1){
       return FALSE; 
    }
    return (G->vertices + i)->data;
}
int PutVex(ALGraph * G, int index, int value){
    int i = LocateVex(G, index);
    if(i == -1){
        return FALSE;
    }
    (G->vertices + i)->data = value;
    return SUCCESS;
}
int FirstAdjVex(ALGraph * G, int index){
    int i = LocateVex(G, index);
    if((G->vertices + i)->firstarc == NULL){
        return FALSE;
    }
    return (G->vertices + (G->vertices + i)->firstarc->adjvex)->index;
}
int  NextAdjVex(ALGraph * G, int index1, int index2){
    int i = LocateVex(G, index1);
    ArcNode * p = (G->vertices + i)->firstarc;
    if(p == NULL){
        return FALSE;
    }
    if((G->vertices + p->adjvex)->index == index2){
        if(p->nextarc == NULL){
            return FALSE;
        }
        else{
            p = p->nextarc;
            return (G->vertices + p->adjvex)->index;
        }
    }
    else{
        while(p->nextarc != NULL){
            p = p->nextarc;
            if((G->vertices + p->adjvex)->index == index2){
                if(p->nextarc == NULL){
                    return FALSE;
                }
                else{
                    p = p->nextarc;
                    return (G->vertices + p->adjvex)->index;
                }
            }
        }
    }
    return FALSE;
}
VNode * createVNode(ALGraph * G, int value, int rela_Node, int VR[]){
    VNode * p = (VNode *)malloc(sizeof(VNode));
    ArcNode * T = NULL;
    p->firstarc = NULL;
    p->data = value;
    for(int i = 0; i < rela_Node; i++){
        ArcNode * Q = (ArcNode *)malloc(sizeof(ArcNode));
        Q->adjvex = VR[i];
        Q->nextarc = NULL;
        Q->info = 0;
        if(p->firstarc == NULL){
            p->firstarc = Q;
            T = p->firstarc;
        }
        else{
            T->nextarc = Q;
            T = T->nextarc;
        }
    }
    return p;
}
int InsertVex(ALGraph * G, int u){
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        if((G->vertices + i)->data == -1 && (G->vertices + i)->firstarc == NULL){
            (G->vertices + i)->data = u;
            (G->vertices + i)->index = i;
            for(int j = i + 1; j < MAX_VERTEX_NUM; j++){
                if((G->vertices + j)->data != -1){
                    (G->vertices + j)->index++;
                }
            }
            break;
        }
    }
    G->vexnum++;
    return SUCCESS;
}
int DeleteVex(ALGraph * G, int index){
    int i = LocateVex(G, index);
    if(i == FALSE){
        return FALSE;
    }
    ArcNode * p = (G->vertices + i)->firstarc;
    ArcNode * Q = p;
    ArcNode * H = p;
    (G->vertices + i)->data = -1;
    index = (G->vertices + i)->index;
    (G->vertices + i)->index = -1;
    for(int j = 0; j < MAX_VERTEX_NUM; j++){
        if((G->vertices + j)->index != -1 && (G->vertices + j)->index > index){
            (G->vertices + j)->index--;
        }
    }
    G->vexnum--;
    if(p == NULL){
        return TRUE;
    }
    else{
        while(Q != NULL){
            while(p->nextarc != NULL){
                H = p;
                p = p->nextarc;
            }
            if(p == Q){
                free(p);
                (G->vertices + i)->firstarc = NULL;
                G->arcnum--;
                break;
            }
            else{
                free(p);
                H->nextarc = NULL;
                p = Q;
                G->arcnum--;
            }
        }
        (G->vertices + i)->firstarc = NULL;
    }
    for(int j = 0; j < MAX_VERTEX_NUM; j++){
        ArcNode * H = NULL;
        ArcNode * P = NULL;
        if((G->vertices + j)->index != -1 && (G->vertices + j)->firstarc != NULL){
            H = (G->vertices + j)->firstarc;
            while(H->nextarc != NULL){
                P = H;
                H = H->nextarc;
                if(H->adjvex == i){
                    P->nextarc = H->nextarc;
                    free(H);
                }
            }
            H = (G->vertices + j)->firstarc;
            if(H->adjvex == i){
                (G->vertices + j)->firstarc = H->nextarc;
                free(H);
            }
        }
    }
    return TRUE;
}
int InsertArc(ALGraph * G, int u, int w){
    VNode * p = NULL;
    VNode * Q = NULL;
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        if((G->vertices + i)->index == -1 && (G->vertices + i)->firstarc == NULL){
            continue;
        }
        if((G->vertices + i)->index == u){
            p = G->vertices + i;
        }
        if((G->vertices + i)->index == w){
            Q = G->vertices + i;
        }
    }
    if(Q == NULL || p == NULL){
        return FALSE;
    }
    int j = LocateVex(G, Q->index);
    ArcNode * T = p->firstarc;
    ArcNode * Z = NULL;
    if(p->firstarc == NULL){
        T = (ArcNode *)malloc(sizeof(ArcNode));
        T->adjvex = j;
        T->info = 0;
        T->nextarc = NULL;
        p->firstarc = T;
    }
    else{
        while(T != NULL){
            Z = T;
            T = T->nextarc;
            if(T != NULL){
                if(T->adjvex == j){
                printf("The <u, w> has existed\n");
                return FALSE;
                }
            }
        }
        T = (ArcNode *)malloc(sizeof(ArcNode));
        T->adjvex = j;
        T->info = 0;
        T->nextarc = NULL;
        Z->nextarc = T;
    }
    G->arcnum++;
    return SUCCESS;
}
int DeleteArc(ALGraph * G, int u, int w){
    VNode * p = NULL;
    VNode * Q = NULL;
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        if((G->vertices + i)->data == -1 && (G->vertices + i)->firstarc == NULL){
            continue;
        }
        if((G->vertices + i)->data == u){
            p = G->vertices + i;
        }
        if((G->vertices + i)->data == w){
            Q = G->vertices + i;
        }
    }
    if(p == NULL || Q == NULL){
        return FALSE;
    }
    int j = LocateVex(G, Q->index);
    ArcNode * T = p->firstarc;
    ArcNode * Q1 = NULL;
    if(p->firstarc == NULL){
        return FALSE;
        printf("Has nothing to delete");
    }
    if(p->firstarc->adjvex == j){
        free(p->firstarc);
        p->firstarc = NULL;
        G->arcnum--;
        return SUCCESS;
    }
    else{
        while(T->nextarc != NULL){
            Q1 = T;
            T = T->nextarc;
            if(T->adjvex == j){
                Q1->nextarc = T->nextarc;
                free(T);
                G->arcnum--;
                return SUCCESS;
            }
        }
    }
    return FALSE;
}
int visited[MAX_VERTEX_NUM];
int DFSTraverse(ALGraph * G, void(* visit)(int data)){
    VNode * P = G->vertices;
    for(int v = 0; v < MAX_VERTEX_NUM; v++){
        visited[v] = 0;
    }//initialize
    for(int v = 0; v < G->vexnum; v++){
        if(!visited[v]){
            DFS(G,v);
        }
    }
}

void DFS(ALGraph * G, int v){
    visited[v] = 1; 
    visit(v);
    for(int i = FirstAdjVex(G, v); i >= 0; i = NextAdjVex(G, v, i)){
        if(!visited[i]){
            DFS(G, i);    
        }
    }
}


int InitQueue(LinkQueue *Q){
	Q->rear = (QNode *)malloc(sizeof(QNode));
	Q->front = Q->rear;
	if(!Q->front) exit(OVERFLOW);
	Q->front->next = NULL;
}

int EnQueue(LinkQueue *Q, int index){
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->index = index;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

int Dequeue(LinkQueue *Q){
	if(Q->front == Q->rear) return FALSE;
	QNode * p = Q->front->next;
	int e = p->index;
	Q->front->next = p->next;
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	free(p);
	return e;
}
int QueueEmpty(LinkQueue * Q){
    if(Q->front == Q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int BFSTraverse(ALGraph * G, LinkQueue * Q, void(* visit)(int data)){
    for(int v= 0; v < G->vexnum; v++){
        visited[v] = 0;
    }
    InitQueue(Q);
    for(int v = 0; v < G->vexnum; v++){
        if(!visited[v]){
            visited[v] = 1;
            visit(v);
            EnQueue(Q, v);
            while(!QueueEmpty(Q)){
                int u = Dequeue(Q);
                for(int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)){
                    if(!visited[w]){
                        visited[w] = 1;
                        visit(w);
                        EnQueue(Q, w);
                    }
                }
            }
        }
    }
}
void visit(int data){
    printf("%d ", data);
}