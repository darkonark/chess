#include <iostream>
#include<string>
using namespace std;

char board [8][8] = {{'R','N','B','K','Q','B','N','N'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};




class piece {
	public:
	//stuff
};
class king {
	public:
//	void initiate (button interrupt)
};
class queen {
	public:
//	void initiate (button interrupt)
};
class bishop {
	public:
//	void initiate (button interrupt)
};
class knight {
	public:
//	void initiate (button interrupt)
};
class rook {
	public:
//	void initiate (button interrupt)
};
class pawn {
	public:
//	void initiate (button interrupt)
};
const char topking = 'K';
const char topqueen = 'Q';
const char toprook = 'R';
const char topbishop = 'B';
const char topknight = 'N';
const char toppawn = 'P';
const char btmking = 'k';
const char btmqueen = 'q';
const char btmrook = 'r';
const char btmbishop = 'b';
const char btmknight = 'n';
const char btmpawn = 'p';
const char empty ='.';
const char canmove ='X';

void printboard (void){
	int col, row;
	
	for (row = 0; row <8; row++){
		
		for (col =0; col <8; col++){
			cout<<" "<<board[row][col];
		}
		cout<<endl;}}
//end of printboard function

int main() {
	int turnNo = 0;

printboard();

return 0;}
