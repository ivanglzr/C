#include "binary-tree.h"

Leaf *createLeaf(int data)
{
  Leaf *newLeaf = (Leaf *)malloc(sizeof(Leaf));
  newLeaf->data = data;
  newLeaf->parent = NULL;
  newLeaf->left = NULL;
  newLeaf->right = NULL;

  return newLeaf;
}

Leaf *insertAtRight(Leaf *parent, int data)
{
  Leaf *newLeaf = createLeaf(data);

  if (parent == NULL)
    return newLeaf;

  parent->right = newLeaf;

  newLeaf->parent = parent;

  return newLeaf;
}

Leaf *insertAtLeft(Leaf *parent, int data)
{
  Leaf *newLeaf = createLeaf(data);

  if (parent == NULL)
    return newLeaf;

  parent->left = newLeaf;

  newLeaf->parent = parent;

  return newLeaf;
}

Leaf *getRoot(Leaf *leaf)
{
  if (leaf != NULL)
  {

    Leaf *temp = leaf;
    while (temp->parent != NULL)
    {
      temp = temp->parent;
    }

    return temp;
  }
}

void printTreeRec(Leaf *root, char cad[])
{
  printf("%d\n", root->data);

  if (root->left != NULL)
  {
    char cad2[MAXTAMCAD];

    strcpy(cad2, cad);

    if (root->right != NULL)
    {
      printf("%s%c%c%c%c%c", cad, 195, 196, 196, 196, 196);

      char simb = 179, aux[2];
      aux[0] = simb;
      aux[1] = '\0';

      strcat(cad2, aux);
      strcat(cad2, "    ");

      printTreeRec(root->left, cad2);
    }
    else
    {
      printf("%s%c%c%c%c%c", cad, 192, 196, 196, 196, 196);
      strcat(cad2, "     ");
      printTreeRec(root->left, cad2);
    }
  }

  if (root->right != NULL)
  {
    char cad3[MAXTAMCAD];
    strcpy(cad3, cad);

    printf("%s%c%c%c%c%c", cad, 192, 196, 196, 196, 196);

    strcat(cad3, "     ");
    printTreeRec(root->right, cad3);
  }
}

void printTree(Leaf *root)
{
  if (root == NULL)
    printf("It's empty");
  else
    printTreeRec(root, "");
}

int main()
{
  // Crear el nodo raíz
  Leaf *root = createLeaf(1);

  // Crear un árbol binario de 10 niveles
  Leaf *currentLeft = root;
  Leaf *currentRight = root;

  // Crear subárboles a la izquierda y derecha
  for (int i = 2; i <= 10; i++)
  {
    currentLeft = insertAtLeft(currentLeft, i);
    currentRight = insertAtRight(currentRight, i + 10); // Diferenciar datos
  }

  // Imprimir el árbol
  printf("Binary Tree (Pre-order Traversal):\n");
  printTree(root);

  // Obtener y mostrar la raíz
  Leaf *actualRoot = getRoot(currentLeft);
  printf("\nRoot of the tree: %d\n", actualRoot->data);

  return 0;
}