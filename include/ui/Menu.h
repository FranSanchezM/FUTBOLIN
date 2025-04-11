#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "../gameplay/Gameplay.h"
#include "../gameplay/Listas.h"
#include "../user/Usuario.h"


class Puntero
{
private:

    sf::Texture PunteroTextura;
    sf::Sprite PunteroSprite;
public:
    Puntero()
    {
        //mouse
        PunteroTextura .loadFromFile("resources/imagen/botin2.png");
        PunteroSprite.setTexture(PunteroTextura);
    }
    sf::Sprite& DrawPuntero()
    {
        return PunteroSprite;
    }
};

class Fondo
{
private:
    sf::Texture FondoTextura;
    sf::Texture FutbolinTextura;
    sf::Texture ReglasTextura;
    sf::Texture ControlesTextura;
    sf::Texture jugador1Textura;
    sf::Texture jugador2Textura;

    sf::Sprite ControlesSprite;
    sf::Sprite FondoSprite;
    sf::Sprite FutbolinSprite;
    sf::Sprite ReglasSprite;
    sf::Sprite jugador1Sprite;
    sf::Sprite jugador2Sprite;
    int EstadoMovimiento;
public:
    Fondo()
    {
        ///FONDO
        if(! FondoTextura.loadFromFile("resources/imagen/fondo.jpg"))
        {
            exit(-1);
        }
        FondoSprite.setTexture(FondoTextura);

        ///LOGO
        FutbolinTextura.loadFromFile("resources/imagen/futbolinLogo.png");
        FutbolinSprite.setTexture(FutbolinTextura);
        FutbolinSprite.setPosition(300,100);
        ///REGLAS
        ReglasTextura.loadFromFile("resources/imagen/REGLAS.png");
        ReglasSprite.setTexture(ReglasTextura);
        ReglasSprite.setPosition(350,100);
        ///CONTROLES
        ControlesTextura.loadFromFile("resources/imagen/CNTROLES.png");
        ControlesSprite.setTexture(ControlesTextura);
        ControlesSprite.setPosition(380,100);
        ///JUGADOR1
        jugador1Textura.loadFromFile("resources/imagen/juga1.png");
        jugador1Sprite.setTexture(jugador1Textura);
        jugador1Sprite.setPosition(150,200);
        ///jUGADOR2
        jugador2Textura.loadFromFile("resources/imagen/juga2.png");
        jugador2Sprite.setTexture(jugador2Textura);
        jugador2Sprite.setPosition(700,200);

    }

    void update();

    sf::Sprite& DrawFondo()
    {
        return FondoSprite;
    }
    sf::Sprite& DrawLogo()
    {
        return FutbolinSprite;
    }
    sf::Sprite& DrawReglas()
    {
        return ReglasSprite;
    }
    sf::Sprite& DrawControles()
    {
        return ControlesSprite;
    }
    sf::Sprite& DrawJuga1()
    {
        return jugador1Sprite;
    }
    sf::Sprite& DrawJuga2()
    {
        return jugador2Sprite;
    }

};
class Botones
{

private:
    sf::Texture BotonTextura[10];
    sf::Sprite  BotonSprite;
    bool Estado;
public:
    Botones()
    {
        Estado=false;
    }
    void setEstado(bool e)
    {
        Estado=e;
    }
    void setTexture(int i);
    bool getEstado()
    {
        return Estado;
    }
    sf::Sprite& getSprite()
    {
        return BotonSprite;
    }

};

void Botones::setTexture(int i)
{

    switch(i)
    {
    case 0:
        BotonTextura[0].loadFromFile("resources/imagen/controles.png");
        BotonSprite.setTexture(BotonTextura[0]);
        break;
    case 1:
        BotonTextura[1].loadFromFile("resources/imagen/opciones.png");
        BotonSprite.setTexture(BotonTextura[1]);
        break;
    case 2:
        BotonTextura[2].loadFromFile("resources/imagen/avanzar.png");
        BotonSprite.setTexture(BotonTextura[2]);
        break;
    case 4:
        BotonTextura[4].loadFromFile("resources/imagen/salir.png");
        BotonSprite.setTexture(BotonTextura[4]);
        break;
    case 5:
        BotonTextura[5].loadFromFile("resources/imagen/1vs1.png");
        BotonSprite.setTexture(BotonTextura[5]);
        break;
    case 6:
        BotonTextura[6].loadFromFile("resources/imagen/return.png");
        BotonSprite.setTexture(BotonTextura[6]);
        break;
    case 7:
        BotonTextura[7].loadFromFile("resources/imagen/avanzar.png");
        BotonSprite.setTexture(BotonTextura[7]);
        break;
    case 8:
        BotonTextura[8].loadFromFile("resources/imagen/users.png");
        BotonSprite.setTexture(BotonTextura[8]);
        break;
    }
}

void Menu()
{
    Usuario Nombre1;
    Usuario Nombre2;
    Nombre1.setPosition1(300,300);
    Nombre2.setPosition2(700,300);
    bool bandera=false;
    bool keyPressed = false;
    int cont=0;
    int contLetras=0;
    int EstadoMenu = ESTADO_MENU::MENU;

    ///INICIALIZACION
    sf::RenderWindow window(sf::VideoMode(1200, 686), "FUTBOLIN!");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    ///FONDO
    Fondo _Fondo;

    ///PUNTERO
    Puntero _Puntero;

    ///BOTONES MENU PRINCIPAL
    int CantMenuBotones=10;
    Botones *MenuBotones;
    MenuBotones= new Botones[CantMenuBotones];
    if(MenuBotones==nullptr)
    {
        exit (-1);
    }
    //controles
    MenuBotones[0].setEstado(true);
    MenuBotones[0].setTexture(0);
    MenuBotones[0].getSprite().setPosition(400,300);
    //opciones
    MenuBotones[1].setEstado(true);
    MenuBotones[1].setTexture(1);
    MenuBotones[1].getSprite().setPosition(500,300);
    //avanzar
    MenuBotones[2].setEstado(true);
    MenuBotones[2].setTexture(2);
    MenuBotones[2].getSprite().setPosition(600,300);
    //pausa
    MenuBotones[3].setEstado(true);
    MenuBotones[3].setTexture(3);
    MenuBotones[3].getSprite().setPosition(700,300);
    //salir
    MenuBotones[4].setEstado(true);
    MenuBotones[4].setTexture(4);
    MenuBotones[4].getSprite().setPosition(700,300);
    //1vs1
    MenuBotones[5].setEstado(false);
    MenuBotones[5].setTexture(5);
    MenuBotones[5].getSprite().setPosition(580,300);
    //return
    MenuBotones[6].setEstado(false);
    MenuBotones[6].setTexture(6);
    MenuBotones[6].getSprite().setPosition(1100,600);
    //jugar
    MenuBotones[7].setEstado(false);
    MenuBotones[7].setTexture(7);
    MenuBotones[7].getSprite().setPosition(580,300);
    //agregar nombres;
    MenuBotones[8].setEstado(false);
    MenuBotones[8].setTexture(8);
    MenuBotones[8].getSprite().setPosition(500,300);


//    for (int i=0; i<CantMenuBotones; i++) MenuBotones[i].setTexture(i);
//    for(int i=0;i<CantMenuBotones;i++){MenuBotones[i].getSprite().setPosition(327+i225,520);}
//    for(int i=0;i<3;i++){MenuBotones[i].setEstado(true);}
//    MenuBotones[6].getSprite().setPosition(850,430);
//    MenuBotones[6].getSprite().setPosition(550,550);

    Gameplay gameplay;
    ///GAME LOOP
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::MouseMoved:
                _Puntero.DrawPuntero().setPosition((sf::Vector2f)sf::Mouse::getPosition(window));
                break;

            case sf::Event::MouseButtonPressed:
                if (_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[2].getSprite().getGlobalBounds())&&MenuBotones[2].getEstado()==true)
                {
                    EstadoMenu = ESTADO_MENU::MENU_JUGAR;
                    MenuBotones[5].setEstado(true);
                    MenuBotones[6].setEstado(true);
                    MenuBotones[0].setEstado(false);
                    MenuBotones[1].setEstado(false);
                    MenuBotones[2].setEstado(false);
                    MenuBotones[3].setEstado(false);
                    MenuBotones[4].setEstado(false);
                    gameplay.reinciar();
                    Nombre1.resetear();
                    Nombre2.resetear();
                    break;
                }
                if (_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[5].getSprite().getGlobalBounds())&&MenuBotones[5].getEstado()==true)
                {
                    EstadoMenu = ESTADO_MENU::PVP;
                    MenuBotones[5].setEstado(false);
                    //MenuBotones[7].setEstado(true);
                    MenuBotones[8].setEstado(true);
                    break;
                }
                if (_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[7].getSprite().getGlobalBounds())&&MenuBotones[7].getEstado()==true)
                {
                    EstadoMenu=ESTADO_MENU::JUGAR;
                    MenuBotones[7].setEstado(false);
                    MenuBotones[6].setEstado(true);

                    break;
                }
                if(_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[6].getSprite().getGlobalBounds())&&MenuBotones[6].getEstado()==true)
                {
                    EstadoMenu=ESTADO_MENU::MENU;
                    MenuBotones[5].setEstado(false);
                    MenuBotones[6].setEstado(false);
                    MenuBotones[0].setEstado(true);
                    MenuBotones[1].setEstado(true);
                    MenuBotones[2].setEstado(true);
                    MenuBotones[3].setEstado(true);
                    MenuBotones[4].setEstado(true);
                    break;
                }
                if(_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[8].getSprite().getGlobalBounds())&&MenuBotones[8].getEstado()==true)
                {
                    EstadoMenu=ESTADO_MENU::NOMBRES;
                    contLetras=0;
                    bandera=false;
                    keyPressed = false;
                    cont=0;
                    MenuBotones[8].setEstado(false);
                    break;
                }
                if (_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[0].getSprite().getGlobalBounds())&&MenuBotones[0].getEstado()==true)
                {
                    EstadoMenu=ESTADO_MENU::CONTROLES;
                    MenuBotones[0].setEstado(false);
                    MenuBotones[1].setEstado(false);
                    MenuBotones[2].setEstado(false);
                    MenuBotones[5].setEstado(false);
                    MenuBotones[6].setEstado(true);
                    break;
                }
                if (_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[1].getSprite().getGlobalBounds())&&MenuBotones[1].getEstado()==true)
                {
                    EstadoMenu = ESTADO_MENU::REGLAS;
                    MenuBotones[0].setEstado(false);
                    MenuBotones[4].setEstado(false);
                    MenuBotones[2].setEstado(false);
                    MenuBotones[6].setEstado(true);
                    break;
                }
                if(_Puntero.DrawPuntero().getGlobalBounds().intersects(MenuBotones[4].getSprite().getGlobalBounds())&& MenuBotones[4].getEstado()==true)
                {
                    window.close();
                }
                // }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
///HACER EL MENU
        switch(EstadoMenu)
        {
        case MENU:
            window.clear(); //borra la pantalla
            window.draw(_Fondo.DrawFondo());
            window.draw(_Fondo.DrawLogo());
            for(int i=0; i<CantMenuBotones; i++)
            {
                if(MenuBotones[i].getEstado()==true)
                {
                    window.draw(MenuBotones[i].getSprite());
                }
            }
            window.draw(_Puntero.DrawPuntero());
            window.display(); //muestra en la pantalla
            break;

        case MENU_JUGAR:

            window.clear(); //borra la pantalla
            window.draw(_Fondo.DrawFondo());
            for(int i=0; i<CantMenuBotones; i++)
            {
                if(MenuBotones[i].getEstado()==true)
                {
                    window.draw(MenuBotones[i].getSprite());
                }
            }
            window.draw(_Puntero.DrawPuntero());
            window.display(); //muestra en la pantalla
            break;
        case PVP:
            window.clear(); //borra la pantalla
            window.draw(_Fondo.DrawFondo());
            //window.draw(MenuBotones[7].getSprite());
            window.draw(MenuBotones[8].getSprite());
            window.draw(_Puntero.DrawPuntero());
            window.display(); //muestra en la pantalla
            break;
        case NOMBRES:
            window.clear();
            Nombre1.setPosition1(250,300);
            Nombre2.setPosition2(775,300);
            window.draw(_Fondo.DrawFondo());
            window.draw(_Fondo.DrawJuga1());
            window.draw(_Fondo.DrawJuga2());
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (!keyPressed)
                {
                    bandera = true;
                    keyPressed = true;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (!keyPressed)
                {
                    bandera = true;
                    keyPressed = true;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                if (!keyPressed)
                {
                    cont = 0;
                    contLetras++;
                    keyPressed = true;
                    if (contLetras == 6)
                    {
                        EstadoMenu = ESTADO_MENU::JUGAR;
                    }
                }
            }
            else
            {
                keyPressed = false;
            }

            if (bandera)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    cont++;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    cont--;
                }
                bandera = false;
                if (cont > 26)
                {
                    cont = 0;
                }
                else if (cont < 0)
                {
                    cont = 26;
                }

                if (contLetras == 0)
                {
                    Nombre1.setSprite1(cont);
                }
                else if (contLetras == 1)
                {
                    Nombre1.setSprite2(cont);
                }
                else if (contLetras == 2)
                {
                    Nombre1.setSprite3(cont);
                }
                else if (contLetras == 3)
                {
                    Nombre2.setSprite1(cont);
                }
                else if (contLetras == 4)
                {
                    Nombre2.setSprite2(cont);
                }
                else if (contLetras == 5)
                {
                    Nombre2.setSprite3(cont);
                }
            }
            window.draw(Nombre1.getSprite1());
            window.draw(Nombre1.getSprite2());
            window.draw(Nombre1.getSprite3());
            window.draw(Nombre2.getSprite1());
            window.draw(Nombre2.getSprite2());
            window.draw(Nombre2.getSprite3());
            window.display();
            break;
        case JUGAR:
            Nombre1.setPosition1(80,10);
            Nombre2.setPosition2(950,10);
            gameplay.cmd(&EstadoMenu);
            gameplay.update(&EstadoMenu);
            window.clear(); //borra la pantalla
            gameplay.draw(window,&EstadoMenu);
            window.draw(Nombre1.getSprite1());
            window.draw(Nombre1.getSprite2());
            window.draw(Nombre1.getSprite3());
            window.draw(Nombre2.getSprite1());
            window.draw(Nombre2.getSprite2());
            window.draw(Nombre2.getSprite3());
            if(gameplay.getResultado()==1)
            {
                window.draw(Nombre1.getSprite1());
                window.draw(Nombre1.getSprite2());
                window.draw(Nombre1.getSprite3());
            }
            if(gameplay.getResultado()==2)
            {
                window.draw(Nombre2.getSprite1());
                window.draw(Nombre2.getSprite2());
                window.draw(Nombre2.getSprite3());
            }
            if(gameplay.getResultado()==3)
            {
                window.draw(Nombre1.getSprite1());
                window.draw(Nombre1.getSprite2());
                window.draw(Nombre1.getSprite3());
                window.draw(Nombre2.getSprite1());
                window.draw(Nombre2.getSprite2());
                window.draw(Nombre2.getSprite3());
            }
            window.display(); //muestra en la pantalla
            break;

        case PVIA:
            break;

        case CONTROLES:
            window.clear(); //borra la pantalla
            window.draw(_Fondo.DrawFondo());
            window.draw(_Fondo.DrawControles());
            window.draw(MenuBotones[6].getSprite());
            window.draw(_Puntero.DrawPuntero());
            window.display(); //muestra en la pantalla
            break;

        case REGLAS:
            window.clear(); //borra la pantalla
            window.draw(_Fondo.DrawFondo());
            window.draw(_Fondo.DrawReglas());
            window.draw(MenuBotones[6].getSprite());
            window.draw(_Puntero.DrawPuntero());
            window.display();//muestra en la pantalla
            break;
        }

    }
    if (EstadoMenu == ESTADO_MENU::MENU)
    {
        window.clear();
        window.draw(_Fondo.DrawFondo());
        for (int i = 0; i < 10; ++i)
        {
            if (MenuBotones[i].getEstado())
            {
                window.draw(MenuBotones[i].getSprite());
            }
        }
        window.draw(_Puntero.DrawPuntero());
        window.display();
    }
    else if (EstadoMenu == ESTADO_MENU::MENU_JUGAR || EstadoMenu == ESTADO_MENU::PVP)
    {
        gameplay.update(&EstadoMenu); // Pasar la dirección de EstadoMenu
        gameplay.draw(window,&EstadoMenu);
        window.display();
    }


    ///LIBERACION
    exit(1);
}



//}
#endif // MENU_H_INCLUDED
