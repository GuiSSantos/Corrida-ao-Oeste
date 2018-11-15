#include "BolaFeno.h"

BolaFeno::BolaFeno(Texture* texture, Vector2f size, Vector2f posicao)
{
    corpo.setSize(size);
    corpo.setOrigin(size/2.0f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
    vivo = true;
}


BolaFeno::~BolaFeno()
{
    //dtor
}

 void BolaFeno::Desenha(RenderWindow& janela){
    janela.draw(corpo);
}

 Collider BolaFeno::GetCollider(){
    return Collider (corpo);
}

void BolaFeno::Atualiza(float deltaTime)
{
    int i;
    while (1)
    {
        for( i=0;i<200;i++)
            corpo.move(-1,0);
        for( i=0;i<200;i++)
            corpo.move(1,0);
    }
}


