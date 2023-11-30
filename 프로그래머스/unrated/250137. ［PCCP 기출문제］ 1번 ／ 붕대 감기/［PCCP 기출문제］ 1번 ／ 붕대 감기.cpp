#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Bandage {
public:
    int cool_time;
    int heal;
    int bonus_heal;
    
    Bandage() {cool_time=0,heal=0,bonus_heal=0;}
    Bandage(vector<int> bandage) {cool_time=bandage[0], heal=bandage[1], bonus_heal=bandage[2];}
};

class Game {
public:
    int time;
    int success;
    int max_hp;
    int hp;
    Bandage bg;
    
    Game(int health, Bandage bandage) {
        time = 0; success = 0; hp = health; bg = bandage; max_hp = health;
    }
    
    bool simulate(vector<int> attack) {
        time++;
        if (attack[0] == time) {
            success = 0;
            hp -= attack[1];
            return false;
        } else {
            heal();
            bonus_heal();
        }
        return true;
        cout << time << ": " << hp << " " << success << "\n";
    }
    
private:
    void bonus_heal() {
        if (success == bg.cool_time) {
            success = 0;
            hp = min(max_hp, hp + bg.bonus_heal);
        }
    }
    
    void heal() {
        success++;
        hp = min(max_hp, hp + bg.heal);
    }
};

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    Game game = Game(health, Bandage(bandage));
    
    for (vector<int> attack : attacks) {
        while(game.simulate(attack)) {
        }
        if (game.hp <= 0) {
            return -1;
        }
    }

    return game.hp;
}