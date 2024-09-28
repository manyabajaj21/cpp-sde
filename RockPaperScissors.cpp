#include<iostream>
#include<time.h>
#include<cstdio>
using namespace std;
char isPlaying, playerChoice, computerChoice;
unsigned int randIntForComp;
int main(){
    cout<<"This program is for simulating stone paper scissors "<<endl;
    cout<<"Would you like to paly ? Answer 'Y' or 'y' or anything else to exit." <<endl;
    cin>>isPlaying;
    while (isPlaying == 'Y' || isPlaying =='y')
    {
        cout<<"Wellcome to stone, paper, scissors! The ultimate game of chance and adreeline."<<endl;
    Restart:
        cout<<"\nChosse Rock(R), Paper(P), Scissor(S)"<<endl;
        cin>>playerChoice;
        playerChoice = toupper(playerChoice);
        srand(time(NULL));
        randIntForComp == (rand()%3);
        if (randIntForComp == 0 ){
            computerChoice = 'R';
        }
        else if (randIntForComp == 1){
            computerChoice = 'P';
        }
        else if (randIntForComp == 2){
            computerChoice = 'S';
        }
        switch (playerChoice){
        case 'R':
            if(computerChoice == 'P'){
                cout<<"You chose Rock and the computer chose Paper. You lost!"<<endl;
            }
            else if (computerChoice =='R'){
                cout<<"You chose Rock and the computer chose Rock . You tied!"<<endl;
            }
            else if (computerChoice = 'S'){
                cout<<"Congrats, you won! You chose Rock and the computer chose Scissors."<<endl;
            }
            break;
        case 'S':
            if(computerChoice == 'P'){
                cout<<"Congrats, you won! You chose Scissors and the computer chose Paper."<<endl;
            }
            else if (computerChoice =='R'){
                cout<<"You chose Scissors and the computer chose Rock . You lost!"<<endl;
            }
            else if (computerChoice = 'S'){
                cout<<"You chose Scissors and the computer chose Scissors. You tied! "<<endl;
            }
            break;
        case 'P':
            if(computerChoice == 'P'){
                cout<<"You chose Paper and the computer chose Paper. You tied!"<<endl;
            }
            else if (computerChoice =='R'){
                cout<<"Congrats, you won! You chose aPaper and the computer chose Rock."<<endl;
            }
            else if (computerChoice = 'S'){
                cout<<"You chose Paper and the computer chose Scissors. You lost!"<<endl;
            }
            break;
        default:
            cout<<"\nYou did not enter a valid option. Time to restart!"<<endl;
            goto Restart;
        }
        cout<<"\nWould you like to keep play? Enter 'Y' or 'y' for yes, or anything else for no"<<endl;
        cin>>isPlaying;
        if ((isPlaying == 'Y' || isPlaying == 'y')){
            goto Restart;
        }
        else{
            cout<<"Have a good day!";
            return 0;
        }
    }
    cout<<"Sad to dee you don't want to paly. Have good day!";
    return 1;
}
