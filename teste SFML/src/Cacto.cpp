#include "Cacto.h"

Cacto::Cacto(Texture* texture, Vector2f size, Vector2f position)
{
    corpo.setSize(size);
    corpo.setOrigin(size / 2.f);
    corpo.setTexture(texture);
    corpo.setPosition(position);
}

Cacto::~Cacto()
{
    //dtor
}

void Cacto::Desenha(RenderWindow& window)
{
    window.draw(corpo);
}
Collider Cacto::GetCollider()
{
    return Collider(corpo);
}
