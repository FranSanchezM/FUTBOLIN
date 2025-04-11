#ifndef MOOVARCO_H_INCLUDED
#define MOOVARCO_H_INCLUDED

class MoveArco: public sf::Drawable,public collisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
public:
    MoveArco();
   // void update(const jugador2& jugador);
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void respawn();
    sf::FloatRect getBounds()const override;
    //void checkCollision(const jugador1& jugador);
    //void checkCollision(const jugador2& jugador);
};
void MoveArco::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}
MoveArco::MoveArco()
{
    _texture.loadFromFile("resources/imagen/move.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}
void MoveArco::respawn()
{
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width,std::rand() % 500 + _sprite.getGlobalBounds().height);
}

/*void Congelado::update(const jugador2& jugador)
{

}*/


sf::FloatRect MoveArco::getBounds()const
{
    return _sprite.getGlobalBounds();
}

#endif // MOOVARCO_H_INCLUDED
