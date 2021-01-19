//
// Created by 承苏凯 on 2021/1/19.
//

#ifndef DS_BTREE_H
#define DS_BTREE_H
#define Maxsize 10
typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

/**
 * create a binary-tree
 * @param b
 * @param str
 */
void CreateBTree(BTNode *&b, char *str) {
    BTNode *St[Maxsize];
    BTNode *p;
    int top = -1, k, j = 0;
    char ch;
    b = nullptr;
    ch = str[j];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;//k置1表示为左孩子
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;//k置2表示右孩子
            default:
                p = (BTNode *) malloc(sizeof(BTNode));//建立结点
                p->data = ch;
                p->lchild = p->rchild = nullptr;
                if (b == nullptr) { //空树
                    b = p;
                } else {
                    switch (k) {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

/**
 * destroy a binary-tree
 * @param b
 */
void DestroyBTree(BTNode *&b) {
    if (b != nullptr) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->lchild);
        free(b);
    }
}

/**
 * find node whose value is target
 * @param b
 * @param x
 * @return
 */
BTNode * FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == nullptr) {
        return nullptr;
    } else if (b->data == x) {
        return b;
    } else {
        p = FindNode(b->lchild, x);
        if (p != nullptr) {
            return p;
        } else {
            return FindNode(b->rchild, x);
        }
    }
}

/**
 * search for the left child of the current node
 * @param p
 * @return
 */
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

/**
 * search for the right child of the current node
 * @param p
 * @return
 */
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

/**
 * 返回二叉树的高度
 * @param b
 * @return
 */
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == nullptr) return 0;
    else {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh ? (lchildh + 1):(rchildh + 1));
    }
}

/**
 * output binary-tree
 * @param b
 */
void DisBTree(BTNode * b){
    if(b != nullptr){
        printf("%c",b->data);
        if(b->lchild != nullptr || b->rchild != nullptr){
            printf("(");
            DisBTree(b->lchild);
            if(b->rchild != nullptr){
                printf(",");
                DisBTree(b->rchild);
                printf(")");
            }
        }
    }
}



#endif //DS_BTREE_H
