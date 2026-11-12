#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	struct node_t* next;
	int data;
}node_t;

void free_list(node_t* first){
	while (first) {
        node_t* next = first->next;
		printf("Freeing: %p\n",first);
        free(first);
        first = next;
	}
}

int add_node(node_t* head, int new_data){
	if(head && head->next == NULL){
		node_t* new_node = (node_t*)malloc(sizeof(node_t));
		if(new_node == NULL){
			return 1;
		}
		new_node->next = NULL;
		new_node->data = new_data;
		head->next = new_node;
		return 0;
	}
	if(head && head->next){
		return add_node(head->next, new_data);
	}
	return 0;
}

void print_list(node_t* data_head){
	int i = 1;
	while(data_head){
		printf("==== node %d ====\n", i);
		printf("address of node: %p\n",data_head);
		printf("address of next node: %p\n",data_head->next);
		if(data_head->data == '\0'){
			printf("Data: Head contains 0, but this isn't actually application data.\n");
		}
		printf("Data: %d\n",data_head->data);
		data_head = data_head->next;
		puts("=================");
		i++;
	}
}

int main(int argc, char** argv){
	
	if(argc < 2){
		printf("usage: %s <num_nodes>\n",argv[0]);
		return 1;
	}
	int num_nodes = atoi(argv[1]);

	node_t* head;
	head->data = 0;
	head->next = NULL;
	for(int i = 0; i<num_nodes; i++){
		add_node(head, i+10);

	}
	node_t* data_head = head->next;
	print_list(data_head);
	

	data_head = head->next;
	free_list(data_head);
	return 0;
}
