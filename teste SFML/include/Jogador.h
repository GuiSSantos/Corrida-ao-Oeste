#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Animacao.h"
#include <SFML/Graphics.hpp>
#include "Collider.h"


using namespace sf;

class Jogador
{
    public:
        Jogador(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade, float alturaPulo);
        ~Jogador();

        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& janela);
        void OnCollision (Vector2f direction);
        void Move(float dx, float dy);
        int getVida();
        void setVida(int x);
        void setPosition (float dx, float dy);

        Vector2f getPosition();
        Collider GetCollider();

    protected:

    private:
        RectangleShape corpo;
        Animacao anima;
        unsigned int fileira;
        float velocidade;
        bool direita;
        Vector2f velocity;
        bool conseguePular;
        float alturaPulo;
        int vida;
};

#endif // JOGADOR_H
