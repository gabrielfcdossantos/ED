#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int reg;
    struct _node * esq;
    struct _node * dir;
    int h;
}tnode;


int altura(tnode * pnode){
    int ret;
    if (pnode == NULL){
        ret = -1;
    }
    else{
        ret = pnode->h;
    }
    return ret;


}

int max(int a, int b){
    return (a>b)?a:b;
}


void imprime_arv(tnode * pnode,int p){
    int i;
    if (pnode != NULL){
        imprime_arv(pnode->esq,p+1);
        for (i=0;i<p;i++)
            printf("   ");
        printf("%d\n",pnode->reg);
        imprime_arv(pnode->dir,p+1);
    }
}

void destroi_arv(tnode * pnode){
    if (pnode != NULL){
        destroi_arv(pnode->esq);
        destroi_arv(pnode->dir);
        free(pnode);
    }
}

void pre_ordem(tnode *pnode){
    if (pnode != NULL){

        pre_ordem(pnode->esq);
        printf("(%d,%d) ",pnode->reg,pnode->h);
        pre_ordem(pnode->dir);
    }
}

tnode ** busca_pont(tnode ** pnode, int reg){
    tnode ** ret;
    if (*pnode == NULL){
        ret = NULL;
    }else if ((*pnode)->reg == reg){
        ret = pnode;
    }else{
        if (reg > (*pnode)->reg){
            ret = busca_pont(&(*pnode)->dir,reg);
        }else{
            ret = busca_pont(&(*pnode)->esq,reg);
        }

    }
    return ret;
}

void RE(tnode ** pnode){
    tnode * x;
    tnode * y;
    tnode * a;
    tnode * b;
    x = *pnode;
    y = x->dir;
    a = x->esq;
    b = y->esq;
    printf("RE %d\n", x->reg);

    x->esq = a;
    x->dir = b;
    y->esq = x;
    *pnode = y;

    x->h = max(altura(x->esq),altura(x->dir))+1;
    y->h = max(altura(y->esq),altura(y->dir))+1;

}

void RD(tnode ** pnode){
    tnode * x;
    tnode * y;
    tnode * a;
    tnode * b;
    y = *pnode;
    x = y->esq;
    a = x->esq;
    b = x->dir;
    printf("RD %d\n", y->reg);

    x->esq = a;
    x->dir = y;
    y->esq = b;
    *pnode = x;


    y->h = max(altura(y->esq),altura(y->dir))+1;
    x->h = max(altura(x->esq),altura(x->dir))+1;
}

void _rebalancear(tnode ** pnode){
    int fb; // fator de balanceamento do pai
    int fbf;// fator de balanceamento do filho
    tnode * filho; //filho mais alto
    tnode * pai;
    pai = *pnode;
    fb = altura(pai->esq) - altura(pai->dir);
    if(fb == 2){
        filho = pai->esq;
        fbf = altura(filho->esq) - altura(filho->dir);
        if(fbf == -1){
            RE(&(pai->esq));
        }
        RD(pnode);
    }

    else if(fb == -2){
        filho = pai->dir;
        fbf = altura(filho->esq) - altura(filho->dir);
        if(fbf == 1){
            RD(&(pai->dir));
        }
        RE(pnode);
    }
}
void insere(tnode ** parv,int c){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->h = 0;
        (*parv)->reg = c;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;

    }
    else{
        if(c > (*parv)->reg ){
          insere(&(*parv)->dir, c);
        }
        else{
          insere(&(*parv)->esq, c);
        }
        (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
        _rebalancear(parv);
    }
}




int main(void){
      int num,n,test,i,j;

    tnode * arv;
    arv = NULL;
    /*#ifdef DEBUG
    freopen("test.txt","r",stdin);
    #endif
     */
        scanf("%d",&n);
        for (j=0;j<n;j++)
        {
            scanf("%d",&num);
            insere(&arv,num);
        }


        printf("\n");
        printf("-------------------------------------------------------\n");
        pre_ordem(arv);
        printf("\n");
        printf("-------------------------------------------------------\n");

        imprime_arv(arv,0);
        printf("\n");
        printf("-------------------------------------------------------\n");


    return 0;


    return 0;
}
