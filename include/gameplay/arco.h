#ifndef ARCO_H_INCLUDED
#define ARCO_H_INCLUDED
class Arco
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f velocity;
    int numArco=1;
    int Estado;
    int EstadoAlterado;
public:
    Arco();
    void update();
    sf::Sprite getSprite()
    {
        return _sprite;
    }
    void cmd();
    int getEstadoAlterado()
    {
        return EstadoAlterado;
    }
    void setArco2();
    void setEstado(int e)
    {
        Estado=e;
    }
    void setEstadoAlterado(int ea)
    {
        EstadoAlterado=ea;
    }
    void SetPositionn(float x,float y)
    {
        _sprite.setPosition(x,y);
    }
    int getEstado()
    {
        return Estado;
    }
    void reiniciar1();
    void reiniciar2();
};
Arco::Arco()
{
    EstadoAlterado=ESTADO_ARCO::QUIETO;
    velocity= {0,0};
    _texture.loadFromFile("resources/imagen/arco.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(-5,443);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}
void Arco::setArco2()
{
    EstadoAlterado=ESTADO_ARCO::QUIETO;
    velocity= {0,0};
    _texture.loadFromFile("resources/imagen/arco2.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(1205,443);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
    numArco=2;
}
void Arco::reiniciar1()
{
    Estado=ESTADO_ARCO::QUIETO;
    _sprite.setPosition(-5,443);

}
void Arco::reiniciar2()
{
    Estado=ESTADO_ARCO::QUIETO;
    _sprite.setPosition(1205,443);
}
void Arco::update()
{
    //MOVIMIENTOS
    if(Estado==ESTADO_ARCO::MOVIENDO_ABAJO)
    {
        _sprite.move(0,4);
    }
    if(Estado==ESTADO_ARCO::QUIETO)
    {
        _sprite.move(0,0);
    }
    if(Estado==ESTADO_ARCO::MOVIENDO_ARRIBA)
    {
        _sprite.move(0,-4);
    }
}
#endif // ARCO_H_INCLUDED
