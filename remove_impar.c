#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int treg;

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


void pre_ordem(tnode * pnode){
  if(pnode != NULL){
    printf("%d\n",pnode->reg);
    pre_ordem(pnode->esq);
    pre_ordem(pnode->dir);
  }
}


void in_ordem(tnode * pnode) {
  if(pnode != NULL){
    in_ordem(pnode->esq);
    printf("%d\n",pnode->reg);
    in_ordem(pnode->dir);
  }
}



void pos_ordem(tnode * pnode){
  if(pnode != NULL){
    pos_ordem(pnode->esq);
    pos_ordem(pnode->dir);
    printf("%d\n",pnode->reg);
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



tnode ** sucessor(tnode ** pnode){

    tnode * aux;
    tnode ** paux;
    aux = (*pnode)->dir;
    paux = &(*pnode)->dir;
    while(aux->esq != NULL){
        paux = &(aux->esq);
        aux = aux->esq;
    }
    return paux;
}

tnode ** busca(tnode ** pnode, treg reg){
    tnode ** ret;
    if(*pnode ==NULL){
        ret = NULL;
    }
    else if((*pnode)->reg == reg){
        ret = pnode;
    }
    else{
        if((*pnode)->reg < reg){
            ret =busca(&((*pnode)->dir),reg);
        }
        else{
             ret =busca(&((*pnode)->esq),reg);
        }
    }
    return ret;
}

void remove_raiz(tnode ** pnode){
    tnode * aux;
    tnode ** paux;
    /*caso 1 nó de folha*/
    if ((*pnode)->esq == NULL && (*pnode)->dir == NULL){
        aux = *pnode;
        *pnode =NULL;
        free(aux);
    }else if((*pnode)->esq != NULL && (*pnode)->dir == NULL){
        aux = *pnode;
        *pnode =(*pnode)->esq;
        free(aux);

    }else if((*pnode)->esq == NULL && (*pnode)->dir != NULL){
        aux = *pnode;
        *pnode =(*pnode)->dir;
        free(aux);
    }
    else{
        paux = sucessor(pnode);
        (*pnode)->reg = (*paux)->reg;
        remove_raiz(paux);
    }
}

int remove_node(tnode ** pnode, treg reg){
    tnode ** paux;
    int ret = 0;
    paux = busca(pnode,reg);
    if(paux != NULL){
        ret = 1;
        remove_raiz(paux);
    }

}



void remove_impar(tnode ** pnode){

}

int main(void){
    tnode * raiz;
    raiz = NULL;
    int n,i,valor;
    tnode ** paux;
    insere(&raiz,51);
    insere(&raiz,47);
    insere(&raiz,53);
    insere(&raiz,48);
    insere(&raiz,52);
    insere(&raiz,10);
    insere(&raiz,49);
    insere(&raiz,5);
  /*  scanf("%d",&n);
    #ifdef DEBUG
    freopen("remove.in","r",stdin);
    #endif

    for(i=0;i<n;i++){
        scanf("%d",&valor);
        insere(&raiz,valor);
    }*/
  /*  desenha_arv(raiz,0);

    paux = sucessor(&(raiz));
    printf("sucessor: %d\n",(*paux)->reg);

    paux = busca(&raiz,47);
    printf("Resultado da busca: %d\n",(*paux)->reg);

    remove_node(&raiz,5);
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");
    remove_node(&raiz,48);
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");
    remove_node(&raiz,51);
    desenha_arv(raiz,0);*/
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");
    pre_ordem(raiz);
    printf("-----------------------------------------------------------\n");
    remove_node(&raiz,51);
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");
    remove_node(&raiz,5);
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");
    remove_node(&raiz,52);
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");
    remove_node(&raiz,53);
    desenha_arv(raiz,0);
    printf("-----------------------------------------------------------\n");


}
