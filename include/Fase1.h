#ifndef FASE1_H
#define FASE1_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Animacao.h"
#include"Collider.h"
#include"Cacto.h"
#include"Tnt.h"
#include"BolaFeno.h"
#include"jogador.h"
#include "Projetil.h"
#include"Plataforma.h"
#include"Apache.h"
#include "JJ.h"
#include "ProjInimigo.h"
#include<string>
#include<sstream>
#include<vector>
#include "Jogador2.h"
#include "Projetil2.h"
#include <cmath>

using namespace sf;


class Fase1
{
    public:
        Fase1();
        virtual ~Fase1();
        void Executar(RenderWindow& window,float deltaTime,Jogador& jogador1,View& view, bool& _fimFase1);
        void Executar2(RenderWindow& window,float deltaTime,Jogador& jogador1,View& view, Jogador2& jogador2, bool& _fimFase1);
        void Atualiza(float deltaTime);
        void Atualiza2(float deltaTime);

    protected:

    private:
        Texture background,chao21,textureApache,bar,jj,chao,bola,cacto,tnt,bala1,bala22;
        Font fonte;
        Text vidas;
        Font fonte2;
        Text vidas2;
        SoundBuffer buffer2;
        Sound gun;

        Vector2f direction;

        std::vector<Plataforma> plataformas;
        std::vector<Plataforma>invPlataforma;
        std::vector<Plataforma>invChao;
        std::vector<Obstaculo*>obs;
        std::vector<Projetil>bala;
        std::vector<Projetil2>bala2Jog;
        std::vector<ProjInimigo>bala2;
        std::vector<Inimigo*>inimigos;
        std::vector<Vector2f>balaPos;
        std::vector<Vector2f>balaPos2;
};

#endif // FASE1_H
