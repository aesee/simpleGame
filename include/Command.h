#ifndef COMMAND_H
#define COMMAND_H

class Player;

class Command
{
    public:
        virtual ~Command(){}
        virtual void execute(Player & player, float time) = 0;
};

class InputHandler
{
    private:
        Command* left_;
        Command* right_;
        Command* up_;
        Command* down_;

    public:
        InputHandler();

        Command* handleInput()
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return left_;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return right_;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) return up_;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return down_;

            return nullptr;
        }
};

#endif // COMMAND_H
