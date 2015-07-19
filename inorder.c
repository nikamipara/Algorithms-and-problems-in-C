/* in order tree traversal interative*/
#include <stdio.h>

//  stack of nodes. 
 typedef struct t_node
{
	int data;
	struct t_node *left ;
	 struct t_node *right;
}t_node;
//*************************************




t_node stack[100]; // this is stack.t_node empty;
int size =0; // size of stack
t_node empty;
void push( t_node node)
{	
	size++;
	stack[size] = node;
	
	
}

t_node pop()
{
	if(size == 0) 
	{
		t_node empty;
		return empty;
	}
	else 
	{
		size--;
		return stack[size+1];
	}
}
void inorder(t_node *ROOT)
{  int done= 0;
	t_node *current = ROOT;
	t_node temp;
	//printf("size of stack is %d",size);
	while(!done)
	{	//printf("current data is %d\n",((t_node)*current).data);
		if(current != &empty)
		{
			push(*current);
			current = current->left;
			/*printf("size of stack is %d",size);
			printf("\tthis is %d\n",stack[size].data);*/
		}
		else
		{
			if(size != 0)
			{	/*printf("current is null and size of stack is %d",size);
				printf("\t this is %d\n",stack[size].data);*/


				temp = pop();
				current = &temp;
				/*printf("size of stack is %d",size);*/
				printf("%d\t",((t_node)*current).data);
				
				current = current->right;

			}
			else
				done = 1;
		}
	}
		/*printf("size of stack is %d",size);
		printf("this is %d",stack[1].data);*/
}

int main(int argc, char const *argv[])
{
	t_node root,node2,node3,node4,node5,node6,node7,node8;
	

	/* Constructed binary tree is
            5
          /     \
        3        7
      /  \	    /  \
    1     2	    6   9
  	 		    	 \
      		    	 10
         
  */

	root.data = 5;
	node2.data = 3;
	node3.data = 1;
	node4.data = 4;
	node5.data = 7;
	node6.data = 6;
	node7.data = 9;
	node8.data = 10;
	t_node *ROOT = &root;

	//pointers

	root.left = &node2;
	root.right = &node5;
	node2.left = &node3;
	node2.right= &node4;
	node5.left = &node6;
	node5.right = &node7;
	node7.right = &node8;
	node3.left = node3.right = node4.left = node4.right = node6.left=node6.right=node8.left=node8.right=node7.left= &empty;


//**************************************

	//t_node  *lol =ROOT->left->right ;
	//t_node g = *lol;
	//printf("%d\n %d\n",((t_node)*(ROOT->left->right)).data, node2.data);
	inorder(ROOT);
	
}