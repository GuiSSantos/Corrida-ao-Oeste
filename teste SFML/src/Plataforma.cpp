#include "Plataforma.h"

Plataforma::Plataforma(Texture* texture, Vector2f size, Vector2f position)
{
    corpo.setSize(size);
    corpo.setOrigin(size / 2.f);
    corpo.setTexture(texture);
    corpo.setPosition(position);
}

Plataforma::~Plataforma()
{
    //dtor
}
Collider Plataforma::GetCollider()
{
    return Collider(corpo);
}
void Plataforma::Desenha(RenderWindow& window)
{
    window.draw(corpo);
}
