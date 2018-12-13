#include <stdio.h>
#include <stdlib.h>

struct cache_line{
	unsigned int bit;
	unsigned int tag;
	unsigned int d_block;
};

int main(){
	int n=8;	//B-number is 00685115, so n=8
	int b=4;	//block offset=4
	int t=32;	//tag=32
	int s=t/(b*n);	//set index=1 bit

	struct cache_line cache[4][8];	//2d array representing cache

	char* buff[255];		//file i/o setup
	size_t buffsize = 32;

	int i, j;

	while(getline(&buff,&buffsize, "input.txt")!=NULL){
		for(i=0;i<4;i++){
			for(j=0;j<8;j++){
				cache[i][j]=(struct cache_line)getline(&buff, &buffsize, "input.txt");
				
				if((cache[i][j].bit==cache[i][0].bit)&&(j!=0)){
					if(cache[i][j].tag==cache[i][0].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][1].bit)&&(j!=1)){
					if(cache[i][j].tag==cache[i][1].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][2].bit)&&(j!=2)){
					if(cache[i][j].tag==cache[i][2].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][3].bit)&&(j!=3)){
					if(cache[i][j].tag==cache[i][3].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][4].bit)&&(j!=4)){
					if(cache[i][j].tag==cache[i][4].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][5].bit)&&(j!=5)){
					if(cache[i][j].tag==cache[i][5].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][6].bit)&&(j!=6)){
					if(cache[i][j].tag==cache[i][6].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
				if((cache[i][j].bit==cache[i][7].bit)&&(j!=7)){
					if(cache[i][j].tag==cache[i][7].tag){
						printf("HIT\n");
					}
					else{printf("MISS\n");}
				}
			}
		}
	}
}
