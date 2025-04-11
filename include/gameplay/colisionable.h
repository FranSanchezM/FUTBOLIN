#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED

class collisionable{
public:
    virtual sf::FloatRect getBounds() const=0;
    bool colision(collisionable &col) const;

};

bool collisionable::colision(collisionable& obj)const
{
    return getBounds().intersects(obj.getBounds());
}



#endif // COLISIONABLE_H_INCLUDED
