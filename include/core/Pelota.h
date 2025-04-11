#ifndef PELOTA_H_INCLUDED
#define PELOTA_H_INCLUDED
class Pelota
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f velocity;
    int estado;
public:
    Pelota();
    void update();
    sf::Sprite getSprite()
    {
        return _sprite;
    }
    void setEstado(int e)
    {
        estado=e;
    }
    int getEstado()
    {
        return estado;
    }
    void reset();
};
Pelota::Pelota()
{
    estado=ESTADO_PELOTA::INICIO;
    _texture.loadFromFile("resources/imagen/balon.png");
    _sprite.setPosition(605,350);
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}
void Pelota::reset()
{
    // Reposiciona la pelota en el centro de la cancha y reinicia su estado
    _sprite.setPosition(600, 350); // coordenadas del centro de la cancha
    setEstado(ESTADO_PELOTA::INICIO); // Restablece el estado de la pelota
}
void Pelota::update()
{
    switch(estado)
    {

    case INICIO:
        break;
    case COLISION_ALTA:
        _sprite.move(6,-6);
        break;

    case COLISION_MEDIA:
        _sprite.move(6,0);
        break;

    case COLISION_BAJA:
        _sprite.move(6,6);
        break;

    case COLISION_ALTA_IZ:
        _sprite.move(-6,-6);
        break;

    case COLISION_MEDIA_IZ:
        _sprite.move(-6,0);
        break;

    case COLISION_BAJA_IZ:
        _sprite.move(-6,6);
        break;
    }
}
#endif // PELOTA_H_INCLUDED
