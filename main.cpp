#include <iostream>
#include <cstdlib>
using namespace std;
char Matrix[3][3] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};
char player = 'X';
void printMatrix()
{
    system("cls");
    for(int i=0 ; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void Play()
{
    char pos;
    cout << "Choose your position - Player (" << player << ") :";
    cin >> pos;
    for(int i=0 ; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(Matrix[i][j] == pos)
            {
                Matrix[i][j] = player;
            }
        }
    }
    if(player == 'X' )
        player = 'O';
    else
        player = 'X';
}

char WhoWin()
{
    int xc=0, oc=0;
    int counter =0;
    for(int i=0 ; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(Matrix[i][j] != 'X' && Matrix[i][j] != 'O')
                counter++;
            if(Matrix[i][j] == 'X')
                xc++;
            else if(Matrix[i][j] == 'O')
                oc++;
            if(xc == 3 || oc ==3)
            {
                return (xc > oc) ? 'X' : 'O';
            }
        }
         xc=0;   oc=0;
    }

    for(int i=0 ; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(Matrix[j][i] == 'X')
                xc++;
            else if(Matrix[j][i] == 'O')
                oc++;
            if(xc == 3 || oc ==3)
            {
                return (xc > oc ? 'X' : 'O');
            }
        }
         xc=0;   oc=0;
    }

    if(Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X')
        return 'X';
    else if(Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O')
        return 'O';
    if(Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
        return 'X';
    else if(Matrix[0][2] == 'O' && Matrix[1][1] == 'O' && Matrix[2][0] == 'O')
        return 'O';
   if(counter == 0)
        return 'Z';

    return '.';

}

int main()
{
     while(WhoWin() == '.')
     {
         printMatrix();
         Play();
     }

    printMatrix();

    if(WhoWin() == 'Z')
        cout << "\n No Winner !!\n\n" << endl;
    else
        cout << "\nThe Winner is player (" << WhoWin() <<"), congratulations !!\n\n" << endl;
    system("pause");
    return 0;
}
