#ifndef PROJETIL_H
#define PROJETIL_H
#include<SFML/Graphics.hpp>
#include "jogador.h"
#include"Collider.h"
#include "Jogador2.h"


class Projetil
{
    public:
        Projetil(Texture* texture, Vector2f size, Vector2f posicao, Jogador jogador);
        Projetil (Texture* texture, Vector2f size, Vector2f posicao, Jogador2 jogador);
        virtual ~Projetil();
        void Atualiza();
        void Desenha(RenderWindow&window);
        Collider GetCollider();
    protected:

    private:
       RectangleShape bala;
       bool direcaoD;

};

#endif // PROJETIL_H
