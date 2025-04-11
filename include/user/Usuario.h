#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>

using namespace std;

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}



class NombreUsuarios
{

private:
    char Nombre[40];
public:
    void cargar();
    void mostrar();
    const char* getNombre()
    {
        return Nombre;
    }
};
void NombreUsuarios::cargar()
{
    cargarCadena(Nombre,39);
}
void NombreUsuarios::mostrar()
{
    cout<<Nombre<<endl;
}

class ArchivoUsuarios
{
private:
    char nombre[30];
public:
    ArchivoUsuarios(const char *n="usuarios.dat")
    {
        strcpy(nombre, n);
    }
    NombreUsuarios leerRegistro(int pos);
    void grabarRegistro(NombreUsuarios obj);
    void modificarRegistro(NombreUsuarios obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

NombreUsuarios ArchivoUsuarios::leerRegistro(int pos)
{
    NombreUsuarios obj;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

void ArchivoUsuarios::grabarRegistro(NombreUsuarios obj)
{
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoUsuarios::modificarRegistro(NombreUsuarios obj, int pos)
{
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr)
    {
        return;
    }
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}


//int ArchivoUsuarios::buscarRegistro(int num){
//    NombreUsuarios obj;
//    int cant=contarRegistros();
//    for(int i=0; i<cant; i++){
//        obj = leerRegistro(i);
//        if(obj.getNumero()==num){
//            return i;
//        }
//    }
//    return -1;
//}

int ArchivoUsuarios::contarRegistros()
{
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof (NombreUsuarios);
}

class Usuario
{
private:
    sf::Texture _texture[27];
    sf::Sprite _sprite[3];
public:
    Usuario();
    void setPosition1(float x, float y);
    void setPosition2(float x, float y);
    void setSprite1(int s)
    {
        _sprite[0].setTexture(_texture[s]);
    }
    void setSprite2(int s)
    {
        _sprite[1].setTexture(_texture[s]);
    }
    void setSprite3(int s)
    {
        _sprite[2].setTexture(_texture[s]);
    }
    sf::Sprite getSprite1()
    {
        return _sprite[0];
    }
    sf::Sprite getSprite2()
    {
        return _sprite[1];
    }
    sf::Sprite getSprite3()
    {
        return _sprite[2];
    }
    void resetear();
};
Usuario::Usuario()
{

    NombreUsuarios obj;
    ArchivoUsuarios arc;
    for(int i=0; i<27; i++)
    {
        obj=arc.leerRegistro(i);
        _texture[i].loadFromFile(obj.getNombre());
    }
    for(int i=0; i<3; i++)
    {
        _sprite[i].setTexture(_texture[0]);
        _sprite[i].setScale(0.05,0.05);
    }

}
void Usuario::resetear()
{
    _sprite[0].setTexture(_texture[0]);
    _sprite[1].setTexture(_texture[0]);
    _sprite[2].setTexture(_texture[0]);
}
void Usuario::setPosition1(float x, float y)
{

    _sprite[0].setPosition(x,y);
    _sprite[1].setPosition(x+30,y);
    _sprite[2].setPosition(x+60,y);
}
void Usuario::setPosition2(float x, float y)
{

    _sprite[0].setPosition(x,y);
    _sprite[1].setPosition(x+30,y);
    _sprite[2].setPosition(x+60,y);
}

#endif // USUARIO_H_INCLUDED
