#ifndef FASE1_H
#define FASE1_H
#include "Obstaculo.h"
#include "../Animacao.h"
#include "Collider.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Cacto.h"
#include "Tnt.h"
#include "BolaFeno.h"
#include <SFML/Graphics.hpp>
#include "String.h"
#include <sstream>
#include "Entidade.h"





class Fase1
{
public:
    Fase1();
    virtual ~Fase1();
    void Executar(RenderWindow& window, float deltaTime, Jogador& jogador1, View& view );

protected:

private:
    Texture background, chao, cacto, tnt;
    Font fonte;
    Text vidas;

    Vector2f direction;

    std::vector<Plataforma> plataformas;
    std::vector<Plataforma>invPlataforma;
    std::vector<Obstaculo*>obs;


};

#endif // FASE1_H
