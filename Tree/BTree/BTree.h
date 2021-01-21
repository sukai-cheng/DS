//
// Created by 承苏凯 on 2021/1/19.
//

#ifndef DS_BTREE_H
#define DS_BTREE_H

#include "stack"

using namespace std;
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
BTNode *FindNode(BTNode *b, ElemType x) {
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
__used BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

/**
 * search for the right child of the current node
 * @param p
 * @return
 */
__used BTNode *RchildNode(BTNode *p) {
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
        return (lchildh > rchildh ? (lchildh + 1) : (rchildh + 1));
    }
}

/**
 * 返回二叉树b中结点值为x的结点的层次
 * @param b
 * @param x
 * @param h
 * @return
 */
int Level(BTNode *b, ElemType x, int h) {
    int l;
    if (b == nullptr) {
        return 0;
    } else if (b->data == x) {
        return h;
    } else {
        l = Level(b->lchild, x, h + 1);
        if (l != 0) {
            return l;
        } else {
            return Level(b->rchild, x, h + 1);
        }
    }
}


/**
 * output binary-tree
 * @param b
 */
void DisBTree(BTNode *b) {
    if (b != nullptr) {
        printf("%c", b->data);
        if (b->lchild != nullptr || b->rchild != nullptr) {
            printf("(");
            DisBTree(b->lchild);
            if (b->rchild != nullptr) {
                printf(",");
                DisBTree(b->rchild);
                printf(")");
            }
        }
    }
}

/**
 * 返回当前结点所在的层级
 * @param b
 * @param h
 * @param k
 * @param n
 */
void Lnodenum(BTNode *b, int h, int k, int &n) {
    if (b == nullptr) {
        return;
    } else {
        if (h == k) {
            n++;
        } else if (h < k) {
            Lnodenum(b->lchild, h + 1, k, n);
            Lnodenum(b->rchild, h + 1, k, n);
        }
    }
}

/**
 * 判断两棵树是否相似
 * @param b1
 * @param b2
 * @return
 */
bool like(BTNode *b1, BTNode *b2) {
    bool like1, like2;
    if (b1 == nullptr && b2 == nullptr) {
        return true;
    } else if (b1 == nullptr || b2 == nullptr) {
        return false;
    } else {
        like1 = like(b1->lchild, b2->lchild);
        like2 = like(b1->rchild, b2->rchild);
        return like1 && like2;
    }
}

/**
 * 输出x的祖先结点
 * @param b
 * @param x
 * @return
 */
bool ancestor(BTNode *b, ElemType x) {
    if (b == nullptr) {
        return false;
    } else if (b->lchild != nullptr && b->lchild->data == x || b->rchild != nullptr && b->rchild->data == x) {
        printf("%c", b->data);
        return true;
    } else if (ancestor(b->lchild, x) || ancestor(b->rchild, x)) {
        printf("%d", b->data);
        return true;
    } else {
        return false;
    }
}

/**
 * 先序遍历
 * @param b
 */
void PreOrder1(BTNode *b) {
    BTNode *p;
    p = b;
    stack<BTNode *> s;
    if (b != nullptr) {
        s.push(b);
        while (!s.empty()) {
            s.pop();
            printf("%c", p->data);
            if (p->rchild != nullptr) {
                s.push(p->rchild);
            }
            if (p->lchild != nullptr) {
                s.push(p->lchild);
            }
        }
        printf("\n");
    }

}

/**
 * 中序遍历
 * @param b
 */
void InOrder1(BTNode *b) {
    BTNode *p;
    stack<BTNode *> st;
    p = b;
    while (!st.empty() || p != nullptr) {
        while (p != nullptr) {
            st.push(p);
            p = p->lchild;
        }
        if (!st.empty()) {
            st.pop();
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

/**
 * 后序遍历 todo
 * @param b
 */
//void PostOrder1(BTNode * b){
//    BTNode * p , * r;
//    bool flag;
//    stack<BTNode *> st;
//    p = b;
//    do{
//        while(p != nullptr){
//            st.push(p);
//            p = p->lchild;
//        }
//        r = nullptr;
//        flag = true;
//
//    }
//}



#endif //DS_BTREE_H
