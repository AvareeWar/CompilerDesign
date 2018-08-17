#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TEXT_LEN	256
#define NULL_NAME	"null"

struct TreeNode {
	struct TreeNode*	leftPtr_;
	struct TreeNode*	rightPtr_;
	float				data_;
};


struct TreeNode buildtree(){
	char text[TEXT_LEN];
	printf("Please enter a float, or %s for NULL NODE: ",NULL_NAME)
	fgets(text, TEXT_LEN, stdin);

	char* cPtr	= strchr(text,'\n');
	if (*cPtr != NULL)
		*cPtr = '\0';

	if (strcmp(text, NULL_NAME) == NULL)
		return(NULL);

	struct TreeNode*		nodePtr = (struct TreeNode*)malloc(size(TreeNode));

	nodePtr->				= strtod(text, NULL);

	printf("Going left: ");
	nodePtr-> leftPtr_		= buildTree();

	printf("Now going right: ");
	nodePtr-> leftPtr_		= buildTree();

	return(nodePtr);

}

void	prefixOrder (struct TreeNode*	nodePtr){
	
	
}

