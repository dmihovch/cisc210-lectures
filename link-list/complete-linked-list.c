#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	struct node_t* next;
	int data;
}node_t;

node_t* add_node(node_t* head, int new_data);
void free_list(node_t* head);
void print_list(node_t* head);

int main(int argc, char** argv){
	if(argc < 2){
		printf("usage: %s <num_nodes>\n",argv[0]);
		return 1;
	}
	int num_nodes = atoi(argv[1]);
	node_t* head = NULL;
	for(int i = 0; i<num_nodes; i++){
		head = add_node(head, i+10);
	}
	print_list(head);
	free_list(head);
	return 0;
}


void free_list(node_t* head){
	while (head) {
        node_t* next = head->next;
		printf("Freeing: %p\n",head);
        free(head);
        head = next;
	}
}

node_t* add_node(node_t* head, int new_data){
	if(head == NULL){
		node_t* new_node = (node_t*)malloc(sizeof(node_t));
		if(new_node == NULL){
			return NULL;
		}
		new_node->data = new_data;
		new_node->next = NULL;
		return new_node;
	}
	head->next = add_node(head->next, new_data);
	return head;
}

void print_list(node_t* head){
	int i = 1;
	while(head){
		printf("==== node %d ====\n", i);
		printf("address of node: %p\n",head);
		printf("address of next node: %p\n",head->next);
		printf("Data: %d\n",head->data);
		head = head->next;
		puts("=================");
		i++;
	}
}

