#ifndef BOLAFENO_H
#define BOLAFENO_H
#include "Obstaculo.h"

class BolaFeno:public Obstaculo
{
    public:
        BolaFeno(Texture* texture, Vector2f size, Vector2f posicao);
        virtual ~BolaFeno();
        Collider GetCollider();
        void Desenha(RenderWindow& janela);
        void Atualiza(float deltaTime) ;

    protected:

    private:
        RectangleShape corpo;
        bool vivo;
};

#endif // BOLAFENO_H
