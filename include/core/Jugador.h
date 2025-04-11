#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class jugador
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f velocity;
    int numPlayer=1;
    int Estado;
    int EstadoAlterado;
public:
    jugador();
    void update();
    sf::Sprite getSprite()
    {
        return _sprite;
    }
    void cmd();
    void setEstado(int e)
    {
        Estado=e;
    }
    void setEstadoAlterado(int ea)
    {
        EstadoAlterado=ea;
    }
    void setJugador2();
    int getEstadoAlterado()
    {
        return EstadoAlterado;
    }
    void setPosi1();
    void setPosi2();
};
void jugador::setPosi1()
{
    _sprite.setPosition(200,370);
}
void jugador::setPosi2()
{
    _sprite.setPosition(990,370);
}
jugador::jugador()
{
    EstadoAlterado=ESTADO_JUGADOR::NORMAL;
    velocity= {4,4};
    _texture.loadFromFile("resources/imagen/boy/walk1.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(200,370);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);

}
void jugador::setJugador2()
{
    EstadoAlterado=ESTADO_JUGADOR::NORMAL;
    velocity= {4,4};
    _texture.loadFromFile("resources/imagen/girl/walk4.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(990,370);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
    numPlayer=2;
}
void jugador::cmd()
{

    if(numPlayer==1)
    {
        velocity = {0,0};
        //MOVIMIENTOS DEL PJ
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Estado=ESTADO_JUGADOR::ARRIBA;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Estado=ESTADO_JUGADOR::ABAJO;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {

            Estado=ESTADO_JUGADOR::ATRAS;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Estado=ESTADO_JUGADOR::ADELANTE;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Estado=ESTADO_JUGADOR::ADELANTE_ARRIBA;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Estado=ESTADO_JUGADOR::ADELANTE_ABAJO;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Estado=ESTADO_JUGADOR::ATRAS_ARRIBA;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Estado=ESTADO_JUGADOR::ATRAS_ABAJO;
        }
    }
    if(numPlayer==2)
    {
        velocity =    {0,0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {

            Estado=ESTADO_JUGADOR::ARRIBA;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {

            Estado=ESTADO_JUGADOR::ABAJO;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {

            Estado=ESTADO_JUGADOR::ATRAS;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Estado=ESTADO_JUGADOR::ADELANTE;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Estado=ESTADO_JUGADOR::ADELANTE_ARRIBA;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Estado=ESTADO_JUGADOR::ADELANTE_ABAJO;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Estado=ESTADO_JUGADOR::ATRAS_ARRIBA;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Estado=ESTADO_JUGADOR::ATRAS_ABAJO;
        }
    }

}

void jugador::update()
{
    if(Estado!=ESTADO_JUGADOR::IA)
    {
        if(Estado==ESTADO_JUGADOR::ABAJO)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(0,4);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(0,2);
            }
            Estado=ESTADO_JUGADOR::PARADO;

        }
        if(Estado==ESTADO_JUGADOR::ARRIBA)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(0,-4);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(0,-2);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::ADELANTE)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(4,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(2,0);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::ATRAS)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(-4,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(-2,0);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::ADELANTE_ARRIBA)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(4,-4);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(2,-2);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::ADELANTE_ABAJO)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(4,4);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(2,2);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::ATRAS_ABAJO)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(-4,4);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(-2,2);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::ATRAS_ARRIBA)
        {
            if(EstadoAlterado==ESTADO_JUGADOR::NORMAL)
            {
                _sprite.move(-4,-4);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::CONGELADO)
            {
                _sprite.move(0,0);
            }
            if(EstadoAlterado==ESTADO_JUGADOR::SLOW)
            {
                _sprite.move(-2,-2);
            }
            Estado=ESTADO_JUGADOR::PARADO;
        }
        if(Estado==ESTADO_JUGADOR::PARADO)
        {
            _sprite.move(0,0);
        }
        //que no se salga de la pantalla
        if(_sprite.getGlobalBounds().left<0)
        {
            _sprite.setPosition(_sprite.getOrigin().x,_sprite.getPosition().y);
        }
        if(_sprite.getGlobalBounds().top<0)
        {
            _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
        }
        if(_sprite.getGlobalBounds().left+_sprite.getGlobalBounds().width>1200)
        {
            _sprite.setPosition(1200-(_sprite.getGlobalBounds().width-_sprite.getOrigin().x),_sprite.getPosition().y);
        }
        if(_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height>686)
        {
            _sprite.setPosition(_sprite.getPosition().x,686+(_sprite.getGlobalBounds().height-_sprite.getOrigin().y));
        }
    }
    else
    {
///HACER IA

    }
}

#endif // JUGADOR_H_INCLUDED
