#include <iostream> 
using namespace std; 

#define SIZE 10 

class node 
{ 
	public: 
	int data; 
	node *right,*left;
	
	
	node(int v){
		data =v;
		right = NULL;
		left=NULL;
	} 
}; 


class Queue 
{ 
	public: 
	int front, rear; 
	int size; 
	node**array; 
}; 

node* newNode(int d) 
{ 
	return new node(d); 
} 

Queue* createQueue(int size) 
{ 
	Queue* queue = new Queue(); 

	queue->front = queue->rear = -1; 
	queue->size = size; 

	queue->array = new node*[queue->size * sizeof( node* )]; 

	
	for (int i = 0; i < size; ++i) 
		queue->array[i] = NULL; 

	return queue; 
} 

int isEmpty(Queue* queue) 
{ 
	return queue->front == -1; 
} 

int isFull(Queue* queue) 
{ return queue->rear == queue->size - 1; } 

int hasOnlyOneItem(Queue* queue) 
{ return queue->front == queue->rear; } 

void Enqueue(node *root, Queue* queue) 
{ 
	if (isFull(queue)) 
		return; 

	queue->array[++queue->rear] = root; 

	if (isEmpty(queue)) 
		++queue->front; 
} 

node* Dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return NULL; 

	node* temp = queue->array[queue->front]; 

	if (hasOnlyOneItem(queue)) 
		queue->front = queue->rear = -1; 
	else
		++queue->front; 

	return temp; 
} 



node* getFront(Queue* queue) 
{ return queue->array[queue->front]; } 

int hasBothChild(node* temp) 
{ 
	return temp && temp->left && temp->right; 
} 

void insert(node **root, int data, Queue* queue) 
{ 
	node *temp = newNode(data); 

	if (!*root) 
		*root = temp; 

	else
	{ 
		node* front = getFront(queue); 

		if (!front->left) 
			front->left = temp; 

		else if (!front->right) 
			front->right = temp; 

		if (hasBothChild(front)) 
			Dequeue(queue); 
	} 

	Enqueue(temp, queue); 
} 

void levelOrder(node* root) 
{ 
	Queue* queue = createQueue(SIZE); 

	Enqueue(root, queue); 

	while (!isEmpty(queue)) 
	{ 
		node* temp = Dequeue(queue); 

		cout<<temp->data<<" "; 

		if (temp->left) 
			Enqueue(temp->left, queue); 

		if (temp->right) 
			Enqueue(temp->right, queue); 
	} 
} 

int main() 
{ 
	node* root = NULL; 
	Queue* queue = createQueue(SIZE); 
	int i; 

	for(i = 1; i <= 12; ++i) 
		insert(&root, i, queue); 

	levelOrder(root); 

	return 0; 
} 

