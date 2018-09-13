#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct _node{
    int reg;
    struct _node * esq;
    struct _node * dir;
}tnode;


void insere(tnode **pnode, int c){
    if(*pnode == NULL){
        *pnode = (tnode *)malloc(sizeof(tnode));
        (*pnode)->reg = c;
        (*pnode)->esq = NULL;
        (*pnode)->dir = NULL;
    }
    else{
        if((*pnode)->reg < c){
          insere(&(*pnode)->dir, c);
        }
        else{
          insere(&(*pnode)->esq, c);
        }
    }

}

void desenha_arv(tnode *pnode,int prof){
    int i;
    if (pnode != NULL){
        desenha_arv(pnode->esq,prof+1);
        for (i=0;i<prof;i++)
            printf("     ");
        printf("%d\n",pnode->reg);
        desenha_arv(pnode->dir,prof+1);
    }
}


void in_ordem(tnode * pnode) {
  if(pnode != NULL){
    in_ordem(pnode->esq);
    printf("%d\n",pnode->reg);
    in_ordem(pnode->dir);
  }
}

void pre_ordem(tnode * pnode){
  if(pnode != NULL){
    printf("%d\n",pnode->reg);
    pre_ordem(pnode->esq);
    pre_ordem(pnode->dir);
  }
}

void pos_ordem(tnode * pnode){
  if(pnode != NULL){
    pos_ordem(pnode->esq);
    pos_ordem(pnode->dir);
    printf("%d\n",pnode->reg);
  }
}

void rd (tnode ** pnode){
    tnode * x = *pnode;
    tnode * y = x->esq;
    tnode * b = y->dir;
    x->esq = b;
    y->dir = x;
    *pnode = y;


}

void re(tnode ** pnode){
    tnode * y = *pnode;
    tnode * x = y->dir;
    tnode * b = x->esq;

    y->dir = b;
    x->esq = y;
    *pnode = x;


}

tnode * busca(tnode * pnode, int k){
    if(pnode == NULL){
        printf("Não existe Nó na arvore");
    }
    if(pnode->reg == k){
        //printf("%d\n",pnode->reg);
    }
    if(pnode->reg > k){
        pnode = busca(pnode->esq,k);
        
    }
    if(pnode->reg < k){
        pnode = busca(pnode->dir,k);
        
    }

    return pnode;

}



int main(void){

    tnode*raiz;
    tnode*aux;
    raiz = NULL;
  
    
    
  	
  	
  	
  	insere(&raiz,7);
  	insere(&raiz,50);
  	insere(&raiz,20);
  	insere(&raiz,80);
  	insere(&raiz,90);
  	insere(&raiz,100);
  	insere(&raiz,101);
  	insere(&raiz,102);
  	


    printf("-----------------------------------------------------\n" );
    printf("Percusso em in-ordem:\n" );
    in_ordem(raiz);
    printf("\n" );
    printf("-----------------------------------------------------\n" );
    printf("Percusso em pré-ordem:\n" );
    pre_ordem(raiz);
    printf("\n" );
    printf("-----------------------------------------------------\n" );
    printf("Percusso em pos-ordem:\n" );
    pos_ordem(raiz);
    printf("\n" );
    printf("-----------------------------------------------------\n" );

    desenha_arv(raiz,0);
    printf("\n" );
    printf("-----------------------------------------------------\n" );
  //  rd(&raiz);
    desenha_arv(raiz,0);
    printf("\n" );
    printf("-----------------------------------------------------\n" );

    aux = busca(raiz,7);

    re(&(aux->dir));
    //printf("%d\n",aux->reg);
    desenha_arv(raiz,0);

    printf("\n" );
    printf("-----------------------------------------------------\n" );

   	pre_ordem(raiz);








}