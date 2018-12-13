#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include <string.h>

#define ARRAY_SIZE 2	//equal to 2 because P is n array of 2 elements

int g=10;	//global var

struct var_state{
	void *address;
	unsigned int size;
	unsigned int data;
	struct var_state* next;
};

struct var_state *var_state_head = NULL;

void save_state(void *addr, unsigned int size){
	struct var_state saved;
	saved.address=addr;
	saved.size=size;
	saved.data=malloc(sizeof(size));
	//above block saved the input into saved

	*var_state_head=saved;
	saved.next=var_state_head;
	//above block puts saved at the start of var_state_head
}

void restore_state(){
	struct var_state t1;	//scratch var_state to move head forward
	t1=*var_state_head;

	int hasnext=1;		//acts as a boolean to determine if there is a next element

	while(hasnext){

		var_state_head->address=var_state_head->data;

		free(var_state_head->data);
		free(var_state_head);
		//above block to prevent memory leaks
		
		if (t1.next==NULL){hasnext=0;}
		t1=*var_state_head->next;
		*var_state_head=t1;
	}
}

void sig_hand(int val){
	jmp_buf buff;
	longjmp(buff, val);
}

void f(){
	int x;
	char *p;
	x=11;
	p=(char *) malloc(ARRAY_SIZE);
	p[0]=p[1]='x';

	int i;
	jmp_buf buff;
	
	for(i=0; i<32; i++){	
		//exhaust all 32 possible signals
		signal(i, sig_hand);
	}

	save_state(&x, sizeof(x));
	save_state(&p, sizeof(p));
	save_state(&g, sizeof(g));
	save_state(p, ARRAY_SIZE);
	//above block saves the required states


	if(!setjmp(buff)){
		g=30;
		x=100;
		p=0;
		p[0]=p[1]=p[2]='x';
	}
	else{
		restore_state();
		printf("%d, %d, %c, %C\n", g, x, p[0], p[1]);
	}
}


int main (){
	f();
	return 0;
}
