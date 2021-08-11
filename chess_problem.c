#include <stdio.h> 
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

#define getX(x) x/10    
#define getY(y) y%10

//keep ai pos
int ai_pos[4] = {
  01,
  03,
  05,
  07
};  

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
void move_ai(void);

int main() {

int input_p = 0;
  
loop:

clear();
printf("  \nChess algorithem test by Asaf Cohen\nking = @\npawn = $\nblank = [ ]\ndebug = %d%d,%d%d,%d%d,%d%d",getX(ai_pos[0]),getY(ai_pos[0]),getX(ai_pos[1]),getY(ai_pos[1]),getX(ai_pos[2]),getY(ai_pos[2]),getX(ai_pos[3]),getY(ai_pos[3]));
print_brd();
printf("  \nking pos = %d\nset king pos = ", find_king());
scanf("%d",&input_p);
move_player(input_p);
move_ai();

goto loop;

return 0;

}

//this function is for purly visual printing 
void print_brd(void) {

  int king = find_king();

  for(int i = 0; i < 8; i++) {
    printf("\n\n");
    for(int k = 0; k < 8; k++) {
      switch(chess_mem[i][k]) {
        
        case 1:
        printf(" (%d$%d) ",i,k);
        break;

        case 2:
        printf("  (@)  ");
        break;	

        case 0:
        
        if(i >= 0 && i < 8) {
          if(i+1 == getX(king) && k-1 == getY(king)) {
          printf("  (2)  ");
          break;
          } 
          
          if(i+1 == getX(king) && k+1 == getY(king)) {
          printf("  (1)  ");
          break;
          } 

          if(i-1 == getX(king) && k-1 == getY(king)) {
          printf("  (3)  ");
          break;
          } 

          if(i-1 == getX(king) && k+1 == getY(king)) {
          printf("  (4)  ");
          break;
          } 

        else {
        printf("  [ ]  ");
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
          move_piece(getX(king), getY(king),getX(king)+1, getY(king)-1);
          break;
          
      case 3:
          move_piece(getX(king), getY(king),getX(king)+1, getY(king)+1);
          break;
          
      case 1:
          move_piece(getX(king), getY(king),getX(king)-1, getY(king)-1);
          break;
          
      case 2:
          move_piece(getX(king), getY(king),getX(king)-1, getY(king)+1);
          break;

      default:
        //if input is invalid we retry
        main();
          
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
  }
  //dont advance the game if trying to acceses an invalid pos
  else {
	 main();
	}
  
}

//AI section

 int RL = 1;
 
//RL right left
//-1 = right +1 = left
void legal_ai_move(int ai_num) {
    
    int tmp = 0; 
    
    move_piece(getX(ai_pos[ai_num]), getY(ai_pos[ai_num]), getX(ai_pos[ai_num])+RL, getY(ai_pos[ai_num])+1);
    
    tmp += (getX(ai_pos[ai_num])+RL)*10;
    tmp += getY(ai_pos[ai_num])+1;
    
    ai_pos[ai_num] = tmp;   

} 

int ai_callback = 0;

void move_ai(void) {

if(ai_callback > 4){ 
    RL = (~(RL)+1); //toggle
    ai_callback = 0;
}

legal_ai_move(ai_callback++);

}
