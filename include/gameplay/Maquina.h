#ifndef MAQUINA_H_INCLUDED
#define MAQUINA_H_INCLUDED
#include <cstring>
#include "colisionable.h"

class Maquina :public sf::Drawable, public collisionable
{

    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f velocity;
     char _nombre[50];
    bool isFrozen;
    int unfreezeTimer;
     bool isSlower;
    int slowTimer;
public:
    Maquina(const char* nombre);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    void moodStop();
    void congel();
    void descongel();
    void setFrozen(bool frozen);
     void modeSlow();
    void setSlow(bool Slow);
};
Maquina::Maquina(const char* nombre):isFrozen(false), unfreezeTimer(0), isSlower(false),slowTimer(0)
{
    std::strcpy(_nombre, nombre);
    velocity= {4,4};
    _texture.loadFromFile("resources/imagen/girl/walk4.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(990,300);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}

void Maquina::update()
{

}

void Maquina::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}
sf::FloatRect Maquina::getBounds()const
{
    return _sprite.getGlobalBounds();
}
void Maquina::moodStop()
{
    setFrozen(true);

}

void Maquina::setFrozen(bool frozen)
{
    isFrozen = frozen;
    if (frozen)
    {
        unfreezeTimer = 60 * 5; // 10 segundos de descongelación (600 frames a 60 FPS)
    }
}
void Maquina::modeSlow()
{
 setSlow(true);
}
void Maquina::setSlow(bool Slow)
{
    isSlower = Slow;
    if (Slow)
    {
        slowTimer = 60 * 5;
    }
}


#endif // MAQUINA_H_INCLUDED
