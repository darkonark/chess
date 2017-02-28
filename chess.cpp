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
const string K = "topking";
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
		cout<<endl;}
}//end of printboard function

int main() {
	int turnNo = 0;
	string command;
	cout<<"chess test, commands are 'print' and 'exit'"<<endl;
	cout<<"or enter a coordinate to activate a peice"<<endl;
	cout<<"follow your command with the RETURN key"<<endl;
	while(1){ //this is supposed to be an infinite loop
	getline(cin,command);
	if (command.substr(0,4) == "exit")
		{
		break;
		}
	if (command.substr(0,5) == "print")
		{
		printboard();
		continue;
		}
	if (command.substr(0, 1) >= "a" && command.substr(0, 1) <= "h" && command.substr(1, 1) >= "1" && command.substr(1, 1) <= "8")
		{
		cout<<"coordiate"<<endl;
		}
	else{ cout<<"invalid, try another command"<<endl;
		}
	} //end of the main loop
return 0;}
