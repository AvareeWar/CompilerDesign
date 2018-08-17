#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define	TEXT_LEN	256
#define	NULL_NAME	"null"

struct	TreeNode
{
  struct TreeNode*	leftPtr_;
  struct TreeNode*	rightPtr_;
  float			data_;
};


struct TreeNode*	buildTree	()
{
  char	text[TEXT_LEN];

  printf("Please enter a float, or '%s' for a NULL node: ",NULL_NAME);
  fgets(text,TEXT_LEN,stdin);

  char*	cPtr	= strchr(text,'\n');
  if  (cPtr != NULL)
    *cPtr = '\0';

  if  (strcmp(text,NULL_NAME) == 0)
    return(NULL);

  struct TreeNode*	nodePtr	= (struct TreeNode*)malloc(sizeof(struct TreeNode));

  nodePtr->data_		= strtod(text,NULL);

  printf("Going left of %g: ",nodePtr->data_);
  nodePtr->leftPtr_	= buildTree();

  printf("Back at %g, now going right: ",nodePtr->data_);
  nodePtr->rightPtr_	= buildTree();

  return(nodePtr);
}


void		prefixOrder	(struct TreeNode*	nodePtr
				)
{
  if  (nodePtr == NULL)
    return;

  printf("%g\n",nodePtr->data_);
  prefixOrder(nodePtr->leftPtr_);
  prefixOrder(nodePtr->rightPtr_);
}


void		postfixOrder	(struct TreeNode*	nodePtr
				)
{
  if  (nodePtr == NULL)
    return;

  postfixOrder(nodePtr->leftPtr_);
  postfixOrder(nodePtr->rightPtr_);
  printf("%g\n",nodePtr->data_);
}


void		infixOrder	(struct TreeNode*	nodePtr
				)
{
  if  (nodePtr == NULL)
    return;

  infixOrder(nodePtr->leftPtr_);
  printf("%g\n",nodePtr->data_);
  infixOrder(nodePtr->rightPtr_);
}


void		freeTree	(struct TreeNode*	nodePtr
				)
{
  if  (nodePtr == NULL)
    return;

  freeTree(nodePtr->leftPtr_);
  freeTree(nodePtr->rightPtr_);
  free(nodePtr);
}


int	main	()
{
  struct TreeNode*	treePtr	= buildTree();

  printf("Prefix:\n");
  prefixOrder(treePtr);
  printf("\n\n");

  printf("Postfix:\n");
  postfixOrder(treePtr);
  printf("\n\n");

  printf("Infix:\n");
  infixOrder(treePtr);
  printf("\n\n");


  freeTree(treePtr);
  return(EXIT_SUCCESS);
}
