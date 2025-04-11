#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include "Maquina.h"
#include "colisionable.h"
#include "Listas.h"
#include "../core/Jugador.h"
#include "arco.h"
#include "Habilidad.h"
#include "Cronometro.h"
#include "../core/Pelota.h"
#include "../core/Score.h"

class Gameplay
{
private:
    jugador Player1;
    jugador Player2;
    Pelota balon;
    Cronometro crono;
    Arco arco1;
    Arco arco2;
    Score Marcador;
    Habilidad congelado;
    Habilidad movee;
    Habilidad lento;
    int Estado;
    sf::Texture canchaText;
    sf::Sprite canchaSpr;
    int timerCongelado = 60*5;//cada cuando respawnean
    int timerMovee = 60*5;
    int timerLento = 60*5;
    bool cronometroIniciado = false;//inicio de partido
    int tiempo=0;//tiempo que dura un jugador con el efecto
    int tiempo2=0;
    int tiempoArco1=0;
    int tiempoArco2=0;
    int contador=0;
    bool mostrarGanador;
    sf::Sprite GanadorSpi1;
    sf::Texture GanadorTex1;
    sf::Sprite GanadorSpi2;
    sf::Texture GanadorTex2;
    sf::Sprite EmpateSpi;
    sf::Texture EmpateTex;
    sf::Sprite fondoauxspi;
    sf::Texture fondoauxtex;

public:
    Gameplay();
    void cmd(int *EstadoMenu);
    void update(int *EstadoMenu);
    void draw(sf::RenderWindow& window,int *EstadoMenu);
    void checkCollision();
    void consultarEstado();
    void mostrarGanadorMensaje(sf::RenderWindow& window);
    void reinciar();
    int getResultado()
    {
        if(Estado==ESTADO_GAMEPLAY::RESULTADO)
        {
            if(Marcador.getGolesJugador1()>Marcador.getGolesJugador2())
            {
                return 1;
            }
            if(Marcador.getGolesJugador1()<Marcador.getGolesJugador2())
            {

                return 2;
            }
            if(Marcador.getGolesJugador1()==Marcador.getGolesJugador2())
            {

                return 3;
            }
        }
        else
        {
            return 0;
        }
    }
};
void Gameplay::reinciar()
{
    Estado=ESTADO_GAMEPLAY::EJECUTANDO;
    timerCongelado = 60*5;//cada cuando respawnean
    timerMovee = 60*5;
    timerLento = 60*5;
    cronometroIniciado = false;//inicio de partido
    tiempo=0;//tiempo que dura un jugador con el efecto
    tiempo2=0;
    tiempoArco1=0;
    tiempoArco2=0;
    contador=0;
    balon.reset();
    congelado.desactivar();
    lento.desactivar();
    movee.desactivar();
    Player1.setPosi1();
    Player2.setPosi2();
    Marcador.reinciarGoles();

    arco1.reiniciar1();
    arco2.reiniciar2();
}
void Gameplay::checkCollision()
{
    //colision de pelota con arcos
    if(balon.getSprite().getGlobalBounds().intersects(arco1.getSprite().getGlobalBounds()))
    {
        Marcador.incrementarGolesJugador2();
        balon.reset();
        Player1.setPosi1();
        Player2.setPosi2();
    }
    if(balon.getSprite().getGlobalBounds().intersects(arco2.getSprite().getGlobalBounds()))
    {
        Marcador.incrementarGolesJugador1();
        balon.reset();
        Player1.setPosi1();
        Player2.setPosi2();
    }
    //la pelota colisione con los bordes
    if(balon.getSprite().getPosition().y<0)
    {
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_ALTA)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_BAJA);
        }
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_ALTA_IZ)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_BAJA_IZ);
        }
    }
    if(balon.getSprite().getPosition().x<0)
    {
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_ALTA_IZ)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_ALTA);
        }
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_BAJA_IZ)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_BAJA);
        }
    }
    if(balon.getSprite().getPosition().y>663)
    {
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_BAJA)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_ALTA);
        }
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_BAJA_IZ)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_ALTA_IZ);
        }
    }
    if(balon.getSprite().getPosition().x>1177)
    {

        if(balon.getEstado()==ESTADO_PELOTA::COLISION_ALTA)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_ALTA_IZ);
        }
        if(balon.getEstado()==ESTADO_PELOTA::COLISION_BAJA)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_BAJA_IZ);
        }
    }
    //colision de arcos con la cancha
    if(arco1.getSprite().getPosition().y>663)
    {
        arco1.setEstado(ESTADO_ARCO::MOVIENDO_ARRIBA);
    }
    if(arco1.getSprite().getPosition().y<200)
    {
        arco1.setEstado(ESTADO_ARCO::MOVIENDO_ABAJO);
    }
    if(arco2.getSprite().getPosition().y>663)
    {
        arco2.setEstado(ESTADO_ARCO::MOVIENDO_ARRIBA);
    }
    if(arco2.getSprite().getPosition().y<200)
    {
        arco2.setEstado(ESTADO_ARCO::MOVIENDO_ABAJO);
    }

//pelota colisione con los jugadores
    if(Player1.getSprite().getGlobalBounds().intersects(balon.getSprite().getGlobalBounds()))
    {
        //pregunta por colision superior
        if(balon.getSprite().getPosition().y<=Player1.getSprite().getPosition().y-60)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_ALTA);
        }
        //colision inferior
        if(balon.getSprite().getPosition().y>=Player1.getSprite().getPosition().y)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_BAJA);
        }
    }
    if(Player2.getSprite().getGlobalBounds().intersects(balon.getSprite().getGlobalBounds()))
    {
        //pregunta por colision superior
        if(balon.getSprite().getPosition().y<=Player2.getSprite().getPosition().y-60)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_ALTA_IZ);
        }
        //colision inferior
        if(balon.getSprite().getPosition().y>=Player2.getSprite().getPosition().y)
        {
            balon.setEstado(ESTADO_PELOTA::COLISION_BAJA_IZ);
        }
    }
//jugadores colisiona con las habilidades
    if(Player1.getSprite().getGlobalBounds().intersects(congelado.getSprite().getGlobalBounds()))
    {
        Player2.setEstadoAlterado(ESTADO_JUGADOR::CONGELADO);
        congelado.desactivar();
    }
    if(Player1.getSprite().getGlobalBounds().intersects(lento.getSprite().getGlobalBounds()))
    {
        Player2.setEstadoAlterado(ESTADO_JUGADOR::SLOW);
        lento.desactivar();
    }
    if(Player1.getSprite().getGlobalBounds().intersects(movee.getSprite().getGlobalBounds()))
    {
        arco2.setEstado(ESTADO_ARCO::MOVIENDO_ARRIBA);
        movee.desactivar();
    }
    if(Player2.getSprite().getGlobalBounds().intersects(congelado.getSprite().getGlobalBounds()))
    {
        Player1.setEstadoAlterado(ESTADO_JUGADOR::CONGELADO);
        congelado.desactivar();
    }
    if(Player2.getSprite().getGlobalBounds().intersects(lento.getSprite().getGlobalBounds()))
    {
        Player1.setEstadoAlterado(ESTADO_JUGADOR::SLOW);
        lento.desactivar();
    }
    if(Player2.getSprite().getGlobalBounds().intersects(movee.getSprite().getGlobalBounds()))
    {
        arco1.setEstado(ESTADO_ARCO::MOVIENDO_ARRIBA);
        movee.desactivar();
    }
}
Gameplay::Gameplay():crono(20)
{
    Estado=ESTADO_GAMEPLAY::EJECUTANDO;
    if(!canchaText.loadFromFile("resources/imagen/cancha.jpg"))
    {
        exit(-1);
    }
    canchaSpr.setTexture(canchaText);
    Player2.setJugador2();
    arco2.setArco2();
    movee.setHab2();
    lento.setHab3();

    GanadorTex1.loadFromFile("resources/imagen/gana1.png");
    GanadorSpi1.setTexture(GanadorTex1);

    GanadorTex2.loadFromFile("resources/imagen/gana2.png");
    GanadorSpi2.setTexture(GanadorTex2);

    EmpateTex.loadFromFile("resources/imagen/empate.png");
    EmpateSpi.setTexture(EmpateTex);

    fondoauxtex.loadFromFile("resources/imagen/Fondo.png");
    fondoauxspi.setTexture(fondoauxtex);
}

void Gameplay::cmd(int *EstadoMenu)
{
    if(Estado==ESTADO_GAMEPLAY::EJECUTANDO)
    {
        if (!cronometroIniciado)
        {
            crono.reiniciar(); // Resetear el cronómetro cuando el juego comience
            cronometroIniciado = true;
        }
        Player1.cmd();
        Player2.cmd();
    }
}

void Gameplay::update(int *EstadoMenu)
{

    if(Estado==ESTADO_GAMEPLAY::EJECUTANDO)
    {

        Player1.update();
        Player2.update();
        arco1.update();
        arco2.update();
        crono.update();
        checkCollision();
        balon.update();
        consultarEstado();
        //respawn de las habilidades
        if (!congelado.isActiva() && timerCongelado > 0)
        {
            timerCongelado--;
        }
        else if (!congelado.isActiva())
        {
            congelado.respawn(1100, 500); // Asegúrate de pasar las dimensiones correctas de la ventana
            timerCongelado = 60 * 5; // Reinicia el temporizador después del respawn
        }

        if (!movee.isActiva() && timerMovee > 0)
        {
            timerMovee--;
        }
        else if (!movee.isActiva())
        {
            movee.respawn(1100, 500); // Asegúrate de pasar las dimensiones correctas de la ventana
            timerMovee = 60 * 5; // Reinicia el temporizador después del respawn
        }

        if (!lento.isActiva() && timerLento > 0)
        {
            timerLento--;
        }
        else if (!lento.isActiva())
        {
            lento.respawn(1100, 500); // Asegúrate de pasar las dimensiones correctas de la ventana
            timerLento = 60 * 5; // Reinicia el temporizador después del respawn
        }
        if (crono.tiempoAgotado())
        {
            Estado = ESTADO_GAMEPLAY::RESULTADO; // Cambia el estado del juego cuando el tiempo se agota
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            Estado=ESTADO_GAMEPLAY::PAUSA;
            crono.detener();
        }
    }
    if(Estado==ESTADO_GAMEPLAY::PAUSA)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            Estado=ESTADO_GAMEPLAY::EJECUTANDO;
            crono.reanudar();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            *EstadoMenu=ESTADO_MENU::MENU;
        }
    }
    if(Estado==ESTADO_GAMEPLAY::GAME_OVER)
    {
        *EstadoMenu=ESTADO_MENU::MENU;
        cronometroIniciado = false;
        mostrarGanador=false;
    }
}
void Gameplay::consultarEstado()
{
    if(Player1.getEstadoAlterado()==ESTADO_JUGADOR::CONGELADO)
    {
        tiempo++;
        if(tiempo>=300)
        {
            Player1.setEstadoAlterado(ESTADO_JUGADOR::NORMAL);
            tiempo=0;
        }
    }
    if(Player2.getEstadoAlterado()==ESTADO_JUGADOR::CONGELADO)
    {
        tiempo2++;
        if(tiempo2>=300)
        {
            Player2.setEstadoAlterado(ESTADO_JUGADOR::NORMAL);
            tiempo2=0;
        }
    }
    if(Player1.getEstadoAlterado()==ESTADO_JUGADOR::SLOW)
    {
        tiempo++;
        if(tiempo>=300)
        {
            Player1.setEstadoAlterado(ESTADO_JUGADOR::NORMAL);
            tiempo=0;
        }
    }
    if(Player2.getEstadoAlterado()==ESTADO_JUGADOR::SLOW)
    {
        tiempo2++;
        if(tiempo2>=300)
        {
            Player2.setEstadoAlterado(ESTADO_JUGADOR::NORMAL);
            tiempo2=0;
        }
    }
    if(arco1.getEstado()==ESTADO_ARCO::MOVIENDO_ABAJO||arco1.getEstado()==ESTADO_ARCO::MOVIENDO_ARRIBA )
    {
        tiempoArco1++;
        if(tiempoArco1>=300)
        {
            arco1.SetPositionn(-5,443);
            arco1.setEstado(ESTADO_ARCO::QUIETO);
            tiempoArco1=0;
        }
    }
    if(arco2.getEstado()==ESTADO_ARCO::MOVIENDO_ABAJO ||arco2.getEstado()==ESTADO_ARCO::MOVIENDO_ARRIBA )
    {
        tiempoArco2++;
        if(tiempoArco2>=300)
        {
            arco2.SetPositionn(1205,443);
            arco2.setEstado(ESTADO_ARCO::QUIETO);
            tiempoArco2=0;
        }

    }
}

void Gameplay::draw(sf::RenderWindow& window,int *EstadoMenu)
{

    if(Estado!=ESTADO_GAMEPLAY::GAME_OVER)
    {
        window.draw(canchaSpr);
        window.draw(arco1.getSprite());
        window.draw(arco2.getSprite());
        window.draw(balon.getSprite());
        if (congelado.isActiva())
        {
            window.draw(congelado.getSprite());
        }
        if (movee.isActiva())
        {
            window.draw(movee.getSprite());
        }
        if (lento.isActiva())
        {
            window.draw(lento.getSprite());
        }
        window.draw(Player1.getSprite());
        window.draw(Player2.getSprite());
        window.draw(crono.getText());
        Marcador.mostrarMensajeGol(window);
        Marcador.draw(window);

    }


    if(Estado==ESTADO_GAMEPLAY::RESULTADO)
    {
        window.draw(fondoauxspi);
        if(Marcador.getGolesJugador1()>Marcador.getGolesJugador2())
        {

            GanadorSpi1.setPosition(100,250);
            window.draw(GanadorSpi1);
        }
        if(Marcador.getGolesJugador1()<Marcador.getGolesJugador2())
        {

            GanadorSpi2.setPosition(100,250);
            window.draw(GanadorSpi2);
        }
        if(Marcador.getGolesJugador1()==Marcador.getGolesJugador2())
        {

            EmpateSpi.setPosition(350,250);
            window.draw(EmpateSpi);
        }
        if(contador==240)
        {
            *EstadoMenu = ESTADO_MENU::MENU;
        }
        contador++;
    }

}

#endif // GAMEPLAY_H_INCLUDED
