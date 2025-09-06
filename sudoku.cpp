#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<char>>&board,int row,int col,char dig)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==dig)
        {
            return false;
        }
    }
    for(int j=0;j<9;j++)
    {
        if(board[j][col]==dig)
        {
            return false;
        }
    }
    int strow=(row/3)*3;
    int stcol=(col/3)*3;
    for(int i=strow;i<=strow+2;i++)
    {
        for(int j=stcol;j<=stcol+2;j++)
        {
            if(board[i][j]==dig)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<char>>&board,int row,int col)
{
    if(row==9)
    {
        return true;
    }
    int nextrow=row;
    int nextcol=col+1;
    if(nextcol==9)
    {
        nextrow=row+1;
        nextcol=0;
    }
    if(board[row][col]!='.')
    {
       return solve(board,nextrow,nextcol);  
    }
    for(char i='1';i<='9';i++)
    {
        if(issafe(board,row,col,i))
        {
            board[row][col]=i;
           if (solve(board,nextrow,nextcol))
           {
            return true;
           }
            board[row][col]='.';
        }
    }
    return false;
}
int main()
{
 vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
   if( solve(board,0,0))
   {
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j];
        }
       cout<< endl;
    }
   }
   else{
    cout<<"solution not find";
   }
   return 0;
    
  }