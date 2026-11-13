#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
	//TODO
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

node_t* add_node(node_t* head, int new_data){
	//TODO
	return NULL;
}

void free_list(node_t* head){
	//TODO
}

void print_list(node_t* head){
	//TODO
}
