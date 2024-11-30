#ifndef LEAF_H
#define LEAF_H
#define MAXTAMCAD 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Leaf
{
  int data;
  struct Leaf *parent;
  struct Leaf *left;
  struct Leaf *right;
} Leaf;

#endif