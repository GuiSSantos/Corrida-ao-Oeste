#ifndef CACTO_H
#define CACTO_H
#include <SFML/Graphics.hpp>
#include "Obstaculo.h"

class Cacto : public Obstaculo
{
    public:
        Cacto(Texture* texture, Vector2f size, Vector2f position);
        ~Cacto();

        void Desenha(RenderWindow& window);
        Collider GetCollider();
        void Atualiza(float delaTime) {};

    protected:

    private:
        RectangleShape corpo;
};

#endif // CACTO_H
