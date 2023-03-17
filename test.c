#include "test.h"
#include <stdio.h>
#include <stdlib.h>

BSTree *createBSTree() {
    BSTree *tree = (BSTree *) malloc(sizeof(BSTree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;
    tree->count = 0;
    return tree;
}
// 后序遍历方式释放所有结点
static void freeNode(BSTree *tree, BSNode *node) {
    if (node) {
        freeNode(tree, node->left);
        freeNode(tree, node->right);
        free(node);
        tree->count--;
    }
}
void releaseBSTree(BSTree *tree) {
    if (tree) {
        // 先释放所有树中的结点
        freeNode(tree, tree->root);
        printf("There are %d node after released!\n", tree->count);
        // 再释放树的结构
        free(tree);
    }
}

BSNode *searchBSTree(BSTree *tree, Element e) {
    // 引入辅助指针，指向遍历的节点
    BSNode *node = tree->root;
    while (node) {
        if (e < node->data) {
            node = node->left;
        } else if (e > node->data) {
            node = node->right;
        } else {			// e == node->data
            return node;
        }
    }
    return NULL;
}
static BSNode *createBSNode(Element e) {
    BSNode *node = (BSNode *) malloc(sizeof(BSNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = e;
    node->left = node->right = NULL;
    return node;
}

void insertBSTreeNoRecur(BSTree *tree, Element e) {
    BSNode *cur = tree->root;
    BSNode *pre = NULL;
    // 1. 找到待插入的位置
    while (cur) {
        pre = cur;
        if (e < cur->data) {
            cur = cur->left;
        } else if (e > cur->data) {
            cur = cur->right;
        } else {				// 插入元素已经在BST树中存在，那么就直接返回
            return;
        }
    }
    // 此时，pre就是唯一知道待插入节点的前一个位置在哪里
    // 2. 分配节点
    BSNode *node = createBSNode(e);
    // 3. 将这个新的节点，放到待插入位置前面那个节点的左或右
    // 放入pre指向结点的左或右 (请优化下面代码)
    if (cur == NULL) {
        if (pre && e < pre->data) {
            pre->left = node;
        } else if (pre && e > pre->data) {
            pre->right = node;
        }
    }
    if (pre == NULL) {
        tree->root = node;
    }
    tree->count++;
}

static void inOrder(BSNode *node) {
    if (node) {
        inOrder(node->left);
        visitBSNode(node);
        inOrder(node->right);
    }
}
void inOrderBSTree(BSTree *tree) {
    if (tree && tree->root) {
        inOrder(tree->root);
    }
}
void visitBSNode(BSNode *node) {
    printf("\t%d", node->data);
}

