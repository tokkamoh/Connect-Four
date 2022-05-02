#include<iostream>

using namespace std;

void display();

bool check(int a, int b);
int drop(int b, char player);
char place[6][7];



int main(){
    for(int a =0;a <= 5; a++){

        for(int b = 0; b<=6; b++)

            place[a][b] = ' ';

    }

    display();

    int hold;

    int hold2 = 0;

    int charsPlaced = 0;

    bool gamewon = false;

    char player = 15;

    while(!gamewon){

        if(hold2 != -1){

            if(player == 15){
                cout<<"player 1 drop where?";

                player = 254;

            }

            else{

                cout<<"player 2 drop where?";

                player = 15;

            }

        }

        while(true){

            if(charsPlaced == 42) break;

            cin>>hold;

            hold--;

            if(hold <=6 && hold>= 0) break;

            else cout<< "\nplease enter a value between 1 and 7 :";

            if (cin.fail())
            {
                cin.clear();
                char c;

                cin>>c;

            }



        }

        if(charsPlaced == 42) break;

        hold2 = drop(hold,player);

        if(hold2 == -1) cout<<"Colom is full\nPlease enter anothor number between 1 and 7:";
        else{

            gamewon = check(hold2,hold);

            charsPlaced ++;



            display();

        }

    }



    if(charsPlaced == 42){
        cout<<"No winner, Game was draw\n";


        return 0;

    }

    if(player == 15)

        cout<<"gamewon by : player 2\n";

    else cout<<"gamewon by : player 1\n";

    return 0;
}

void display(){

    cout<<" 1   2   3   4   5   6   7\n";

    for(int a = 0; a<= 5; a++)

    {

        for(int b =0; b <= 6; b++) cout<<char(218)<<char(196)<<char(191)<<" ";

        cout<<'\n';

        for(int b =0; b <= 6; b++) cout<<char(179)<<place[a][b]<<char(179)<<" ";

        cout<<'\n';

        for(int b =0; b <= 6; b++) cout<<char(192)<<char(196)<<char(217)<<" ";

        cout<<'\n';

    }

}

bool check(int a, int b){
    int vertical = 1;
    int horizontal = 1;
    int diagonal1 = 1;
    int diagonal2 = 1;

    char player = place[a][b];

    int i;

    int ii;


    for(i = a +1;place[i][b] == player && i <= 5;i++,vertical++);//Check down

    for(i = a -1;place[i][b] == player && i >= 0;i--,vertical++);//Check up

    if(vertical >= 4)return true;

    //check for horizontal(-)

    for(ii = b -1;place[a][ii] == player && ii >= 0;ii--,horizontal++);//Check left

    for(ii = b +1;place[a][ii] == player && ii <= 6;ii++,horizontal++);//Check right
    if(horizontal >= 4) return true;

    //check for diagonal 1 (\)

    for(i = a -1, ii= b -1;place[i][ii] == player && i>=0 && ii >=0; diagonal1 ++, i --, ii --);//up and left

    for(i = a +1, ii = b+1;place[i][ii] == player && i<=5 && ii <=6;diagonal1 ++, i ++, ii ++);//down and right

    if(diagonal1 >= 4) return true;

    //check for diagonal 2(/)

    for(i = a -1, ii= b +1;place[i][ii] == player && i>=0 && ii <= 6; diagonal2 ++, i --, ii ++);//up and right
    for(i = a +1, ii= b -1;place[i][ii] == player && i<=5 && ii >=0; diagonal2 ++, i ++, ii --);//up and left

    if(diagonal2 >= 4) return true;

    return false;

}

int drop(int b, char player){

    if(b >=0 && b<= 6)

    {

        if(place[0][b] == ' '){

            int i;

            for(i = 0;place[i][b] == ' ';i++)

                if(i == 5){place[i][b] = player;

            return i;}

            i--;

            place[i][b] =player;

            return i;



        }

        else{

            return -1;
        }



    }

    else{

        return -1;

    }

}























/*
int main()
{ char a[6][7];
    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 7; c++)
            a[r][c] = { };

//-------------------------------------------
    cout << " 1   2  3  4   5   6   7 " << endl;
    cout << "|------------------------|" << endl;
    for (int r = 0; r < 6; r++)
    {
        cout << " | ";
        for (int c = 0; c <= 6; c++)
          {

           cout << a[r][c];
            cout << " | ";
        }
        cout << endl << "|------------------------|" << endl;
    }
    return 0;
}
*/
