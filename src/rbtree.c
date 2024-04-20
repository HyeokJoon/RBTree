#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void)
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  p->nil = (node_t *)malloc(sizeof(node_t));
  p->nil->color = RBTREE_BLACK;
  p->nil->parent = p->nil;
  p->root = p->nil;
  return p;
}

void postorder_delete(rbtree *t, node_t *curNode)
{
  if (curNode == t->nil)
    return;
  postorder_delete(t, curNode->left);
  postorder_delete(t, curNode->right);
  free(curNode);
}

void delete_rbtree(rbtree *t)
{
  // TODO: reclaim the tree nodes's memory
  if (t == NULL)
  {
    return;
  }
  // 재귀 or 순회
  postorder_delete(t, t->root);
  free(t);
}

void left_rotate(rbtree *t, node_t *node)
{
  node_t *rchild = node->right;

  node->right = rchild->left;
  if (rchild->left != t->nil)
    rchild->left->parent = node;

  rchild->parent = node->parent;
  if (node->parent == t->nil)
  {
    t->root = rchild;
  }
  else if (node == node->parent->left)
  {
    node->parent->left = rchild;
  }
  else
  {
    node->parent->right = rchild;
  }

  rchild->left = node;
  node->parent = rchild;
}

void right_rotate(rbtree *t, node_t *node)
{
  node_t *lchild = node->left;
  node->left = lchild->right;
  if (lchild->right != t->nil)
    lchild->right->parent = node;

  lchild->parent = node->parent;
  if (node->parent == t->nil)
    t->root = lchild;
  else if (node == node->parent->left)
    node->parent->left = lchild;
  else
    node->parent->right = lchild;

  lchild->right = node;
  node->parent = lchild;
}

void rbtree_insert_fixup(rbtree *t, node_t *node)
{
  while (node->parent->color == RBTREE_RED)
  { // 부모가 RED일때

    if (node->parent == node->parent->parent->left)
    { // 부모가 조부모의 left이면 uncle은 조부모의 right
      node_t *uncle = node->parent->parent->right;

      // 삼촌이 RED일때
      if (uncle->color == RBTREE_RED)
      {
        node->parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
        node = node->parent->parent;
      }
      // 삼촌이 black일때

      else
      { // 조부모 > 나 > 부모
        if (node == node->parent->right)
        {
          node = node->parent;
          left_rotate(t, node);
        }
        // 조부모 > 부모 > 나
        node->parent->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
        right_rotate(t, node->parent->parent);
      }
    }

    else
    { // 부모가 조부모의 right이면 uncle은 조부모의 left
      node_t *uncle = node->parent->parent->left;
      // 삼촌이 RED이면
      if (uncle->color == RBTREE_RED)
      {
        uncle->color = RBTREE_BLACK;
        node->parent->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
      }
      // 삼촌이 BLACK이면
      else
      {
        // 조부모 < 나 < 부모
        if (node == node->parent->left)
        {
          node = node->parent;
          right_rotate(t, node);
        }
        // 조부모 < 부모 < 나
        node->parent->color = RBTREE_RED;
        node->parent->parent->color = RBTREE_BLACK;
        left_rotate(t, node->parent->parent);
      }
    }
  }
  // 부모가 BLACK일때
  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key)
{
  // TODO: implement insert
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->key = key;
  newNode->left = t->nil;
  newNode->right = t->nil;

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

  return newNode;
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
