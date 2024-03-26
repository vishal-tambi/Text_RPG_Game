#include <iostream>
#include <cstdlib>
#include <ctime>

class Character
{
public:
    std::string name;
    int health;
    int attack;
    int defense;

    Character(const std::string &n, int h, int a, int d) : name(n), health(h), attack(a), defense(d) {}

    bool isAlive() const
    {
        return health > 0;
    }

    void takeDamage(int damage)
    {
        health -= std::max(0, damage - defense);
    }

    int dealDamage() const
    {
        return attack + rand() % 5;
    }
};

void battle(Character &player, Character &enemy)
{
    std::cout << "You encounter a " << enemy.name << " with " << enemy.health << " health!" << std::endl;

    while (player.isAlive() && enemy.isAlive())
    {
        // Player's turn
        int playerDamage = player.dealDamage();
        std::cout << "You attack the " << enemy.name << " for " << playerDamage << " damage." << std::endl;
        enemy.takeDamage(playerDamage);

        // Check if the enemy is defeated
        if (!enemy.isAlive())
        {
            std::cout << "You defeated the " << enemy.name << "!" << std::endl;
            break;
        }
        // Enemy's turn
        int enemyDamage = enemy.dealDamage();
        std::cout << "The " << enemy.name << " attacks you for " << enemyDamage << " damage." << std::endl;
        player.takeDamage(enemyDamage);

        // Check if the player is defeated
        if (!player.isAlive())
        {
            std::cout << "You were defeated by the " << enemy.name << ". Game Over!" << std::endl;
            break;
        }

        // Display remaining health
        std::cout << "Your health: " << player.health << ", " << enemy.name << "'s health: " << enemy.health << std::endl;

        // Ask if the player wants to continue the battle
        std::cout << "Do you want to continue the battle? (1) Yes, (2) No: ";
        int choice;
        std::cin >> choice;

        if (choice != 1)
        {
            std::cout << "You choose to run away from the battle." << std::endl;
            break;
        }
    }
}

int main()
{
    srand(time(0));

    std::cout << "Welcome to the Text RPG Game!" << std::endl;

    // Initialize player and enemy characters
    Character player("Hero", 100, 20, 10);
    Character enemy("Dragon", 150, 25, 15);

    // Start the battle
    battle(player, enemy);

    std::cout << "Thanks for playing! Game Over." << std::endl;

    return 0;
}
