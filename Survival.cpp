#include "Survival.h"
#include "Hero.h"
#include "Enemy.h"
#include "Attack.h"
#include "pickUp.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;



Survival::Survival()
{
    srand(time(NULL));

    int attack1_power = rand() % 25 + 8;
    string attack_1 = "Punch";
    int attack2_power = rand() % 25 + 10;
    string attack_2 = "Kick";

    int chance_miss;
    int level = 0;
    bool fled = false;
    bool alive_opponent = true;
    int hero_life;
    bool not_dead = true;
    int earned_xp;
    int enemies_killed = 0;
    int total_earned_xp = 0;
    int rounds_survived = 0;
    string player_rank;
    int xp_dif;
    int probability_miss1;
    int probability_miss2;
    char play_again;

    int chance_chest = rand() % 100 + 1;
    int chance_pickUp = rand() % 100 + 1;

    int difficulty;
    do
    {
    //TO DO: Edit game for difficulty levels (enemy attacks, chance for high ranking, ect ect)
    cout << "Choose Difficulty Number (1-4):" << endl;
    cout << "Chance for an attack to miss increases with difficulty" << endl;
    cout << "1. Easy      (Chance for HP: Very High     Chance for XP: Very Low)" << endl;
    cout << "2. Medium    (Chance for HP: High          Chance for XP: Low)" << endl;
    cout << "3. Hard      (Chance for HP: Low           Chance for XP: High)" << endl;
    cout << "4. Legendary (Chance for HP: Very Low      Chance for XP: Very High)" << endl;
    cout << "Additional game adjustments may apply" << endl;
    cin >> difficulty;

    switch(difficulty)
    {
    case 1:
        probability_miss1 = 5;
        probability_miss2 = 7;
        break;
    case 2:
        probability_miss1 = 10;
        probability_miss2 = 12;
        break;
    case 3:
        probability_miss1 = 15;
        probability_miss2 = 17;
        break;
    case 4:
        probability_miss1 = 20;
        probability_miss2 = 22;
        break;
    }

    int choice;
    string attack;

    cout << endl;

    Hero player(difficulty);
    cout << "Your Hero has " << player.get_HP() << " HP" << endl;
    cout << "Your Hero starts with " << player.get_XP() << " XP" << endl << endl;

    //Game loop
    do
    {
    int turn = 0;
    cout << "Level " << level + 1 << endl;

    cout << "AN OPPONENT APPEARS!" << endl << endl;

    cout << "You face a ";
    Enemy object;

    cout << "Prepare to fight!" << endl;

    if(chance_chest < 6)
    {
        cout << endl << endl << "You have Great luck! You come across a pick up" << endl;
        cout << "You get... " << endl;
        cout << "1st" << endl << endl;
    }


    //Round Loop
    do
    {

        chance_chest = rand() % 100 + 1;
        chance_pickUp = rand() % 100 + 1;
        attack1_power = rand() % 25 + 8;
        attack2_power = rand() % 25 + 10;
        cout << "Round " << turn + 1 << endl << endl;
        chance_miss = rand() % 100 + 1;
        cout << "Choose an attack" << endl;
        cout << "1. Punch" << endl;
        cout << "2. Kick" << endl;

        cin >> choice;
        switch(choice)
        {
        case 1:

            if(chance_miss > probability_miss1)
            {
                object.Got_hit(attack1_power);

                if(attack1_power < 13)
                {
                    cout << "You delivered a weak blow!" << endl;
                }
                else if(attack1_power < 23)
                {
                    cout << "You delivered a medium blow!" << endl;
                }
                else if(attack1_power < 30)
                {
                    cout << "You delivered a strong blow!" << endl;
                }
                else
                {
                    cout << "Critical HIT!!" << endl;
                }

                if(object.get_hp() < 0)
                {
                    break;
                }
            }
            else
            {
                cout << "MISS" << endl;
            }
            cout << "Remaining enemy health = " << object.get_hp() << endl << endl;

            break;
        case 2:
            if(chance_miss > probability_miss2)
            {
                object.Got_hit(attack2_power);

                if(attack2_power < 15)
                {
                    cout << "You delivered a weak blow!" << endl;
                }
                else if(attack2_power < 25)
                {
                    cout << "You delivered a medium blow!" << endl;
                }
                else if(attack2_power < 32)
                {
                    cout << "You delivered a strong blow!" << endl;
                }
                else
                {
                    cout << "Critical HIT!!" << endl;
                }

                if(object.get_hp() < 0)
                {
                    break;
                }
            }
            else
            {
                cout << "MISS" << endl;
            }
            cout << "Remaining enemy health = " << object.get_hp() << endl << endl;
            break;
        }

        if(chance_chest > 10 && chance_chest < 20)
        {
        cout << endl << endl << "You have GOOD luck! You come across a pick up" << endl;
        cout << "You get... " << endl;
        cout << "2nd" << endl << endl;
        }

        if(object.get_hp() <= 0)
        {
            cout << endl;
            object.Result(true);
            cout << endl << endl;
            alive_opponent == false;
            earned_xp = object.get_xp();
            cout << "You killed the OPPONENT!" << endl;
            cout << "You earned " << earned_xp << " XP from the battle" << endl;
            total_earned_xp += earned_xp;
            player.set_XP(earned_xp);
            cout << "Your total XP is now " << player.get_XP() << endl << endl;
            enemies_killed++;
            rounds_survived++;
            break;
        }
        chance_miss = rand() % 100 + 1;

        cout << "Enemy attacks!" << endl;
        if(chance_miss > 20)
        {
            player.lose_HP(object.Attack());
            cout << "You lost " << object.Attack() << " HP" << endl;
            if(player.get_HP() <= 0)
            {
                not_dead = false;
                break;
            }
            cout << "Your hero has " << player.get_HP() << " HP left" << endl;
        }
        else
        {
            cout << "ENEMY ATTACK MISSED" << endl;
            cout << "Your hero has " << player.get_HP() << " HP left" << endl;
        }

        if(chance_chest > 45 && chance_chest < 50)
        {
        cout << endl << endl << "You have NOT BAD luck! You come across a pick up" << endl;
        cout << "You get... " << endl;
        cout << "3rd" << endl << endl;
        }
        if(chance_chest > 50 && chance_chest < 60)
        {
        cout << endl << endl << "You have POOR luck! You come across a pick up" << endl;
        cout << "You get... " << endl;
        cout << "POOR CHANCE" << endl << endl;
        }



        cout << endl << endl;
        turn++;


    }while(alive_opponent);

    cout << "ROUND OVER" << endl;
    cout << endl << endl << endl;
    level++;

    }while(not_dead);

    cout << endl << endl;
    if(not_dead == false)
    {
        cout << "YOU DIED" << endl;
    }


    if( total_earned_xp >= 400 )
    {
        player_rank = "EXCELLENT";
    }
    else if( total_earned_xp >= 255)
    {
        player_rank = "Great!";
    }
    else if( total_earned_xp >= 150)
    {
        player_rank = "NOT BAD!";
    }
    else if( total_earned_xp >= 80)
    {
        player_rank = "Could be better!... and WORSE";
    }
    else
    {
        player_rank = "POOR! Try again!";
    }

    cout << endl;
    cout << "Player Results Stats" << endl << endl;
    cout << "Rounds survived: " << rounds_survived << endl;
    cout << "Enemies killed: " << enemies_killed << endl;
    cout << "Total XP rewarded: " << total_earned_xp << endl;
    cout << "Ending Hero XP: " << player.get_XP() << endl;
    cout << "Ranking: " << player_rank << endl;
    // Add a score (ranking) taking difficulty into count

    cout << "Retry? (Y/N)" << endl;
    cin >> play_again;
    play_again = toupper(play_again);
    not_dead = true;
}while(play_again == 'Y');



}

Survival::~Survival()
{
    cout << endl << "Thanks for Playing!" << endl << endl;
}
