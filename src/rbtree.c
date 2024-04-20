#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void)
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  p->nil = (node_t *)malloc(sizeof(node_t));
  p->nil->color = RBTREE_BLACK;
  p->root = p->nil;
  return p;
}


void delete_rbtree(rbtree *t)
{
  // TODO: reclaim the tree nodes's memory
  if (t == NULL)
  {
    return;
  }
  node_t *curNode = t->root;
  // 재귀 or 순회
  free(t);
}

void rbtree_insert_fixup(rbtree *t, const node_t *node)
{
  while (node != t->root && node->parent->color == RBTREE_RED)
  {
    // 부모가 black일때
    
    // 삼촌이 red일때
    // 삼촌이 black일때
    // 나 = 조부모
  }
}

node_t *rbtree_insert(rbtree *t, const key_t key)
{
  // TODO: implement insert
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  node_t *prevNode = t->nil;
  node_t *curNode = t->root;
  while (curNode != t->nil)
  {
    prevNode = curNode;
    if (key < curNode->key)
    {
      curNode = curNode->left;
    }
    else
      curNode = curNode->right;
  }
  newNode->parent = prevNode;
  // root인 경우
  if (prevNode == t->nil)
    t->root = newNode;
  // 새로운 노드의 키가 이전노드의 왼쪽에 오는 경우
  else if (newNode->key < prevNode->key)
    prevNode->left = newNode;
  // 새로운 노드의 키가 이전노드의 오른쪽에 오는 경우
  else
    prevNode->right = newNode;
  newNode->right = t->nil;
  newNode->left = t->nil;
  newNode->color = RBTREE_RED;
  rbtree_insert_fixup(t, newNode);

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t)
{
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p)
{
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n)
{
  // TODO: implement to_array
  return 0;
}
