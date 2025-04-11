#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class Score
{
private:
    int golesJugador1;
    int golesJugador2;
    sf::Font font;
    sf::Text textoJugador1;
    sf::Text textoJugador2;
    bool mostrarMensaje;
    sf::Clock reloj;
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Sprite ganadorSpr;
    sf::Texture ganadorTex;
public:
    Score();
    void incrementarGolesJugador1();
    void incrementarGolesJugador2();
    int getGolesJugador1() const;
    int getGolesJugador2() const;
    void mostrarMensajeGol(sf::RenderWindow& window);
    void mensajeGnador(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void reinciarGoles();
};

Score::Score() : golesJugador1(0), golesJugador2(0), mostrarMensaje(false)
{
    if (!font.loadFromFile("resources/fuentes/Pangolin.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        throw std::runtime_error("Error loading font");
    }
    textoJugador1.setFont(font);
    textoJugador1.setCharacterSize(24);
    textoJugador1.setFillColor(sf::Color::White);
    textoJugador1.setPosition(50, 10);

    textoJugador2.setFont(font);
    textoJugador2.setCharacterSize(24);
    textoJugador2.setFillColor(sf::Color::White);
    textoJugador2.setPosition(1050, 10);

    _texture.loadFromFile("resources/imagen/msjGol.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(350,100);

    ganadorTex.loadFromFile("resources/imagen/gana1.png");
    ganadorSpr.setTexture(ganadorTex);
    ganadorSpr.setPosition(350,100);
}

void Score::incrementarGolesJugador1()
{
    golesJugador1++;
    mostrarMensaje = true;
    reloj.restart();
}

void Score::incrementarGolesJugador2()
{
    golesJugador2++;
    mostrarMensaje = true;
    reloj.restart();
}

int Score::getGolesJugador1() const
{
    return golesJugador1;
}

int Score::getGolesJugador2() const
{
    return golesJugador2;
}
void Score::reinciarGoles()
{
    golesJugador1=0;
    golesJugador2=0;
}
void Score::mostrarMensajeGol(sf::RenderWindow& window)
{
    if (mostrarMensaje)
    {
        window.draw(_sprite);
        if (reloj.getElapsedTime().asSeconds() > 1)
        {
            mostrarMensaje = false;
        }
    }
}

void Score::draw(sf::RenderWindow& window)
{
    textoJugador1.setString(std::to_string(golesJugador1));
    textoJugador2.setString(std::to_string(golesJugador2));

    window.draw(textoJugador1);
    window.draw(textoJugador2);
}


#endif // SCORE_H_INCLUDED
