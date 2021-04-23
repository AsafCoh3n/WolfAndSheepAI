#include <stdio.h> 
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

// king = 2 
// pawn = 1 
// blank = 0

int chess_mem[8][8] = {  
  0, 1, 0, 1, 0, 1, 0, 1, 
  0, 0, 0, 0, 0, 0, 0, 0,  
  0, 0, 0, 0, 0, 0, 0, 0,    
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0,   
  0, 0, 0, 0, 0, 0, 0, 0,  
  0, 0, 0, 0, 0, 0, 0, 0,    
  0, 0, 0, 0, 2, 0, 0, 0  
};

void print_brd(void);
void move_piece(int from_x, int from_y, int to_x, int to_y);
int find_king(void);
void move_player(int pos);


int main() {

int input_p;
  
loop:

clear();
printf("\nChess algorithem test by Asaf Cohen\nking = @\npawn = $\nblank = #");
print_brd();
//printf("\ninput=%d\nking=%d\n",input_pos,find_king());
printf("\nking pos = %d\nset king pos = ", find_king());
scanf("%d",&input_p);
move_player(input_p);

goto loop;

}

//this function is for purly visual printing 
void print_brd(void) {

  int king = find_king();

  for(int i = 0; i < 8; i++) {
    printf("\n\n");
    for(int k = 0; k < 8; k++) {
      switch(chess_mem[i][k]) {
        
        case 1:
        printf(" %d$%d ",i,k);
        break;

        case 2:
        printf(" (@) ");
        break;	

        case 0:
        
        if(i >= 0 && i < 8) {
          if(i+1 == king / 10 && k-1 == king % 10) {
          printf(" (2) ");
          break;
          } 
          
          if(i+1 == king / 10 && k+1 == king % 10) {
          printf(" (1) ");
          break;
          } 

          if(i-1 == king / 10 && k-1 == king % 10) {
          printf(" (3) ");
          break;
          } 

          if(i-1 == king / 10 && k+1 == king % 10) {
          printf(" (4) ");
          break;
          } 

        else {
        printf("  #  ");
        break;
      }
     }
   }
  }
 printf("\n");
}
}

void move_player(int pos) {
              
      
      int king = find_king();


      switch(pos) {
     
      case 4:
          move_piece(king/10, king%10,(king/10)+1, (king%10)-1);
          break;
          
      case 3:
          move_piece(king/10, king%10,(king/10)+1, (king%10)+1);
          break;
          
      case 1:
          move_piece(king/10, king%10,(king/10)-1, (king%10)-1);
          break;
          
      case 2:
          move_piece(king/10, king%10,(king/10)-1, (king%10)+1);
          break;
          
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
	
	if(to_x <= 7 && to_y <= 7 && to_y >= 0 && to_x >= 0) { 
	  //check if its a valid piece
	  if(!chess_mem[to_x][to_y]) {
		  chess_mem[to_x][to_y] = chess_mem[from_x][from_y];
	  //reset to a blank pos
		  chess_mem[from_x][from_y] = 0; 
	  }
	  else {
	  return;
	  }
  }
}

//AI section


void move_ai(void) {


}
