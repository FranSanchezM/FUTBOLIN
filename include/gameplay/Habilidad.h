#ifndef HABILIDAD_H_INCLUDED
#define HABILIDAD_H_INCLUDED
class Habilidad
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    int numHab=1;
    int Estado;
    int EstadoAlterado;
    bool activa;
public:
    Habilidad();
    sf::Sprite getSprite()
    {
        return _sprite;
    }
    void cmd();
    void setHab2();
    void setHab3();
    void respawn(int windowWidth, int windowHeight);
    bool isActiva()
    {
        return activa;
    }
    void desactivar();
    void activar(int windowWidth, int windowHeight);
};
Habilidad::Habilidad()
{
    EstadoAlterado=ESTADO_HABILIDAD::NO_EFECTO;
    _texture.loadFromFile("resources/imagen/congelado.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}
void Habilidad::setHab2()
{
    EstadoAlterado=ESTADO_HABILIDAD::NO_EFECTO;
    _texture.loadFromFile("resources/imagen/move.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
    numHab=2;
}
void Habilidad::setHab3()
{
    EstadoAlterado=ESTADO_HABILIDAD::NO_EFECTO;
    _texture.loadFromFile("resources/imagen/lento.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
    numHab=3;
}
void Habilidad::respawn(int windowWidth, int windowHeight)
{
    float newX = static_cast<float>(std::rand() % (windowWidth - static_cast<int>(_sprite.getGlobalBounds().width)));
    float newY = static_cast<float>(std::rand() % (windowHeight - static_cast<int>(_sprite.getGlobalBounds().height)));
    _sprite.setPosition(newX, newY);
    activa = true;
}
void Habilidad::desactivar()
{
    activa = false;
    _sprite.setPosition(-100, -100); // Mueve la habilidad fuera de la pantalla
}
void Habilidad::activar(int windowWidth, int windowHeight)
{
    respawn(windowWidth, windowHeight);
    activa = true;
}

#endif // HABILIDAD_H_INCLUDED
