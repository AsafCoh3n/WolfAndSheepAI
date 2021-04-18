#include <stdio.h> 
//#include <stdlib.h>

#define clear() printf("\033[H\033[J")

// king = 2 
// pawn = 1 
// blank = 0

int chess_mem[8][8] = {  
		      						 1, 0, 1, 0, 1, 0, 1, 0, 
                       0, 0, 0, 0, 0, 0, 0, 0,  
                       0, 0, 0, 0, 0, 0, 0, 0,    
                       0, 0, 0, 0, 0, 0, 0, 0, 
                       0, 0, 0, 0, 0, 0, 0, 0,   
                       0, 0, 0, 0, 0, 0, 0, 0,  
                       0, 0, 0, 0, 0, 0, 0, 0,    
                       0, 0, 0, 2, 0, 0, 0, 0  
};

void print_brd(void);
void move_piece(int from_x, int from_y, int to_x, int to_y);
int find_king(void);


int main() {

int input_pos = 0;


  
loop:
clear();
printf("\nchess algorithem test\n");
print_brd();
printf("\ninput=%d\nking=%d\n",input_pos,find_king());
printf("\nset king pos\n");
scanf("%d",&input_pos);
move_piece(find_king()%10,find_king()/10,input_pos%10,input_pos/10);


goto loop;

}

//this function is for purly visual printing 
void print_brd(void) {
  for(int i = 0; i < 8; i++) {
    printf("\n\n");
    for(int k = 0; k < 8; k++) {
      switch(chess_mem[i][k]) {
        
        case 1:
        printf(" %d$%d ",i,k);
        break;

        case 2:
        printf(" %d@%d ",i,k);
        break;

        case 0:
        
        if(i >= 0 && i < 8) {
          if(i+1 == find_king() / 10 && k-1 == find_king() % 10) {
          printf(" %d%d ",i,k);
          break;
          } 
          
          if(i+1 == find_king() / 10 && k+1 == find_king() % 10) {
          printf(" %d%d ",i,k);
          break;
          } 

          if(i-1 == find_king() / 10 && k-1 == find_king() % 10) {
          printf(" %d%d ",i,k);
          break;
          } 

          if(i-1 == find_king() / 10 && k+1 == find_king() % 10) {
          printf(" %d%d ",i,k);
          break;
          } 

        else {
        printf("  #  ");
        break;
        }
        break;
      }
     }
   }
  }
 printf("\n");
}

void move_player(int pos) {
  if(pos <= 4) {
     
  }

  else {
    return;
  }
}

int find_king(void) {
  for(int i = 0; i<8; i++) {
    for(int k = 0; k < 8; k++) {
      if(chess_mem[i][k] == 2) {
        return ((i*10) + k);
      }
    }
  }
}

void move_piece(int from_x, int from_y, int to_x, int to_y){
	
	//check if its a valid piece
	if(!chess_mem[from_x][from_y]) {
		chess_mem[to_x][to_y] = chess_mem[from_x][from_y];
	//reset to a blank pos
		chess_mem[from_x][from_y] = 0; 
	}
	
  else {
   return;
	}
 
}










