#include <iostream>
#include <algorithm>
using namespace std;

struct Player{
    string name;
    int score;
};
bool compare_player(const Player &player1, const Player &player2)
{
    if(player2.score < player1.score)
        return 1;
    if(player2.score == player1.score)
    {
        if(player2.name < player1.name)
            return 1;
    }
    return 0;
}

const int NUM_PLAYERS = 10;
Player players[NUM_PLAYERS];

void addNewPlayer(){
    Player p;
    cout << "Enter player name" << endl;
    cin >> p.name;
    cout << "Enter player score" << endl;
    cin >> p.score;
    int indexOfSmallestScore;
    int smallestScore = INT32_MAX;
    // If there is an empty slot in the array OR it has a higher score than the lowest score p should be added to topTen
    for(int i = 0; i< NUM_PLAYERS; i++){
        if(players[i].name == ""){ //Empty slot in the array
            players[i] = p;
            cout << "Successfully added new player" << endl;
            return; // I put p in the first empty slot in the array
        }
        if(players[i].score < smallestScore){ // Keeping track of lowest score and its index
            smallestScore = players[i].score;
            indexOfSmallestScore = i;
        }
    }
    if(smallestScore < p.score){ //Out of for loop and p is still toBeAdded so need to check p.score is higher than lowest score
        players[indexOfSmallestScore] = p;
        cout <<  "Smallest score is " << smallestScore << " new score is: " << p.score << endl ;
        cout << "Successfully added new player by replacing the player with the lowest score" << endl;
    } else{
        cout << "This player is not in the top ten and cannot be added" << endl;
    }
}

void printTopTenNames(){
    sort(players, players+NUM_PLAYERS, &compare_player);
    for(int i = 0; i<NUM_PLAYERS ; i++){
        cout << "Player in position " << i+1 << " is " << players[i].name << " with score " << players[i].score << endl;
    }
}

void getPlayerHighestScore(){
    string playerName;
    cout << "Enter the name of the player whose score you want to know: " << endl;
    cin >> playerName;
    sort(players, players+NUM_PLAYERS, &compare_player);

    for(int i = 0; i<NUM_PLAYERS ; i++) {
        if(players[i].name == playerName){
            cout << "Player " << playerName << " is among the top ten players and their highest score is: " << players[i].score << endl;
            return;
        }
    }
    cout << "Player " << playerName << " is not in the top ten players" << endl;
}

int main(){
    int option;
    cout << "Menu:" << endl;
    cout << "(1) Add a new player and score." << endl;
    cout << "(2) Print the top 10 names and scores to the screen sorted by score with the highest score first." << endl;
    cout << "(3) Get a player's top score" << endl;
    cout << "(4) Exit program" << endl;
    cout << "Select an option from the menu above: " << endl;
    while(true){
        cin >> option;
        if (option == 1){
            addNewPlayer();
        }
        else if (option == 2){
            printTopTenNames();
        }
        else if (option == 3){
            getPlayerHighestScore();
        }
        else if (option == 4){
            break;
        }
        else{
            cout << "Invalid option ";
            continue;
        }
        cout << "Please enter another option: " << endl;
    }
}
