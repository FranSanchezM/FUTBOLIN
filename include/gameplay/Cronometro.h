#ifndef CRONOMETRO_H_INCLUDED
#define CRONOMETRO_H_INCLUDED

class Cronometro
{
private:
    sf::Clock clock;
    sf::Font font;
    sf::Text text;
    int tiempoLimite; // Tiempo límite en segundos
    bool estaActivo;
    sf::Time tiempoDetenido;
public:
    void update();
    sf::Clock getSprite()
    {
        return clock;
    }
    Cronometro(int limite) : tiempoLimite(limite), estaActivo(true), tiempoDetenido(sf::Time::Zero)
    {
        if (!font.loadFromFile("resources/fuentes/Pangolin.ttf"))
        {
            std::cerr << "Error cargando la fuente." << std::endl;
            exit(1);
        }
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        text.setPosition(400, 10);
    }
    void reiniciar();
    bool tiempoAgotado();
    const sf::Text& getText() const
    {
        return text;
    }
    void detener();
    void reanudar();
};

void Cronometro::reiniciar()
{
    clock.restart();
    estaActivo=true;
    tiempoDetenido = sf::Time::Zero;
}
bool Cronometro::tiempoAgotado()
{
    sf::Time tiempoTranscurrido = clock.getElapsedTime()+ tiempoDetenido;
    int segundosTranscurridos = tiempoTranscurrido.asSeconds();
    return segundosTranscurridos >= tiempoLimite;
}

void Cronometro::update()
{
    if(!estaActivo) return;
    if (!tiempoAgotado())   // Solo actualiza si el tiempo no se ha agotado
    {
        sf::Time tiempoTranscurrido = clock.getElapsedTime() + tiempoDetenido;
        int segundosTranscurridos = tiempoTranscurrido.asSeconds();
        std::stringstream ss; // Construye una cadena
        ss << "Tiempo transcurrido: " << segundosTranscurridos << " segundos"; // En la variable SS se inserta esta cadena
        text.setString(ss.str());
    }
    else
    {
        text.setString("Tiempo transcurrido: " + std::to_string(tiempoLimite) + " segundos (Tiempo Agotado)");
    }
}

void Cronometro::detener()
{
    if (estaActivo)
    {
        tiempoDetenido += clock.getElapsedTime();
        estaActivo = false; // Cambia el estado para indicar que el cronómetro está detenido
    }

}

void Cronometro::reanudar()
{
    if (!estaActivo)
    {
        clock.restart();
        estaActivo = true; // Cambia el estado para indicar que el cronómetro está activo
    }
}


#endif // CRONOMETRO_H_INCLUDED
