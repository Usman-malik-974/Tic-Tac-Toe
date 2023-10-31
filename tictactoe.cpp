#include<iostream>
using namespace std;
class initial_board{
	protected:
		char board[3][3];
	
	public:
	void setInitialValue();
	void drawBoard();
	virtual void playgame()=0;
	virtual void fillplace(int,int)=0;
	virtual bool is_available(int,int)=0;
    virtual void showoutput()=0;
	virtual bool is_winner()=0;
	virtual bool is_filledup()=0;	
};
class start_game:public initial_board{
	private:
		int player=0;
	public:
	void playgame();
    void fillplace(int,int);
	bool is_available(int,int);
    void showoutput();
	bool is_winner();
	bool is_filledup();	
};
bool start_game::is_filledup()
{
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(board[i][j]==' '){
						return true;
					}
				}
			}
			return false;
}
bool start_game::is_winner(){
			if((board[0][0]==board[0][1]) && (board[0][1]==board[0][2]) && board[0][0]!=' ')
			{
				return true;
			}
			else if((board[1][0]==board[1][1]) && (board[1][1]==board[1][2]) && board[1][0]!=' ')
			{
				return true;
			}
			else if((board[2][0]==board[2][1]) && (board[2][1]==board[2][2]) && board[2][0]!=' ')
			{
				return true;
			}
			else if((board[0][0]==board[1][0]) && (board[1][0]==board[2][0]) && board[0][0]!=' ')
			{
				return true;
			}
			else if((board[0][1]==board[1][1]) && (board[1][1]==board[2][1]) && board[0][1]!=' ')
			{
				return true;
			}
			else if((board[0][2]==board[1][2]) && (board[1][2]==board[2][2]) && board[0][2]!=' ')
			{
				return true;
			}
			else if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && board[0][0]!=' ')
			{
				return true;
			}
			else if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && board[0][2]!=' ')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
void start_game::showoutput(){
			cout<<"   |   |   \n";
			cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
			cout<<"___|___|___\n";
			cout<<"   |   |   \n";
			cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
			cout<<"___|___|___\n";
			cout<<"   |   |   \n";
			cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
			cout<<"   |   |   \n";
		}
void start_game::fillplace(int i,int j){
	        if(player%2==0){
	        	board[i][j]='O';
	        	player++;
			}
			else
			{
				board[i][j]='X';
				player--;
			}
		}
bool start_game::is_available(int i,int j)
    {
			if(board[i][j]!=' '){
				return false;
			}
			else
			{
				return true;
			}
		}
void start_game::playgame()
{
			int num,i,j;
			if(player%2==0){
					cout<<"Its player 1 turn"<<endl;
				}
				else{
				    cout<<"Its player 2 turn"<<endl;	
				}
			while(1){
				cout<<"Please enter a number between 1-9:"<<endl;
				cin>>num;
				if(num<1 || num>9){
					cout<<"please enter the number in the given range"<<endl;
					continue;
				}
				else
				{
					bool result;
					
				    switch(num){
				    	case 1:
				    		result=is_available(0,0);
				    		i=0;
				    		j=0;
				    		break;
				    	case 2:
				    		result=is_available(0,1);
				    			i=0;
				    		j=1;
				    		break;
				    	case 3:
				    		result=is_available(0,2);	
				    			i=0;
				    		j=2;
				    		break;
				    	case 4:
				    		result=is_available(1,0);
				    			i=1;
				    		j=0;
				    		break;
						case 5:
				    		result=is_available(1,1);
				    			i=1;
				    		j=1;
				    		break;
						case 6:
				    		result=is_available(1,2);
				    			i=1;
				    		j=2;
				    		break;
						case 7:
				    		result=is_available(2,0);
				    			i=2;
				    		j=0;
				    		break;
						case 8:
				    		result=is_available(2,1);
				    			i=2;
				    		j=1;
				    		break;
						case 9:
				    		result=is_available(2,2);							
				    			i=2;
				    		j=2;
				    		break;
					}
					if(result){
						break;
					}
					else
					{
						cout<<"Oops! this place is already occupied"<<endl;
						continue;
					}
		    	}   	
			}
		    fillplace(i,j);
		    showoutput();
		    if(!is_winner()){
		    	if(is_filledup()){
		    		playgame();
				}
				else
				{
					cout<<"Match tied";
				}
			}
			else
			{
				if(player){
					cout<<"Player 1 won";
				}
				else
				{
					cout<<"Player 2 won";
				}
			}
}
void initial_board::setInitialValue()
{
	    	for(int i=0;i<3;i++){
	    		for(int j=0;j<3;j++){
	    			board[i][j]=' ';
				}
			}	
}
void initial_board::drawBoard()
{
			cout<<"   |   |   \n";
			cout<<" "<<'1'<<" | "<<'2'<<" | "<<'3'<<"\n";
			cout<<"___|___|___\n";
			cout<<"   |   |   \n";
			cout<<" "<<'4'<<" | "<<'5'<<" | "<<'6'<<"\n";
			cout<<"___|___|___\n";
			cout<<"   |   |   \n";
			cout<<" "<<'7'<<" | "<<'8'<<" | "<<'9'<<"\n";
			cout<<"   |   |   \n";
			
			cout<<"\nPlayer 1) O"<<endl;
			cout<<"Player 2) X"<<endl;
			setInitialValue();
			
			cout<<"Press any key to continue"<<endl;
			getchar();
		}
		
int main(){
	char choice;

	do{
			initial_board *ob;
	ob=new start_game();
    ob->drawBoard();
	ob->playgame();
	cout<<"\nDo You want to Play Again(Y/N)";
	cin>>choice;
	}while(choice=='Y' || choice=='y');
	return 0;
}
