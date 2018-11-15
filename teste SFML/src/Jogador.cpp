#include "jogador.h"
#include "Math.h"
#include "string"

Jogador::Jogador(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade, float alturaPulo):
    anima(texture,contImg,trocaTempo)
{
    this->velocidade=velocidade;
    this->alturaPulo = alturaPulo;
    fileira=0;
    direita=true;

    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.0f);
    corpo.setTexture(texture);
    vida = 2;

}

Jogador::~Jogador()
{
    //dtor
}
 void Jogador::Atualiza(float deltaTime)
 {
    velocity.x = 0.0f;

    if(Keyboard::isKeyPressed(Keyboard::W)&& conseguePular)
    {
        conseguePular=false;
        velocity.y = -sqrtf(2.0f * 951.f * alturaPulo);
        //squareroot      (2.f * gravity * alturaPulo);
    }

    velocity.y+=981.f*deltaTime;

    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        velocity.x -= velocidade;

    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        velocity.x += velocidade;

    }



    if(velocity.x==0.0f){

        fileira=0;
        if(conseguePular==false)
            fileira=2;
    }
    else
    {
        if(velocity.x>0.f)
            direita=true;
        else
        {

            direita=false;
        }

        if(conseguePular==false)
            fileira=2;
        else
        {
            fileira=1;
        }

    }

    anima.Atualiza(fileira, deltaTime, direita);
    corpo.setTextureRect(anima.uvRect);
    corpo.move(velocity * deltaTime);

 }


void Jogador::Desenha(RenderWindow& janela)
{
    janela.draw(corpo);
}


Vector2f Jogador::getPosition()
{
    return corpo.getPosition();
}

Collider Jogador::GetCollider()
{
    return Collider(corpo);
}

void Jogador::OnCollision (Vector2f direction)
{
    if(direction.x < 0.f)
    {
     velocity.x = 0.f;
     //Collision left
    }
    else if (direction.x> 0.f)
    {
        velocity.x = 0.f;
        // rigth
    }
    else if(direction.y < 0.f)
    {
        velocity.y = 0.f;
        conseguePular = true;
        //Collision on the bottom
    }
    else if (direction.y > 0.f)
    {
        velocity.y = 0.f;
        //top
    }
}
void Jogador::Move(float dx, float dy)
{
    corpo.move(dx,dy);
}
int Jogador::getVida()
{
    return vida;
}
void Jogador::setVida(int x)
{
    vida = x;
}
void Jogador::setPosition (float dx, float dy)
{
    corpo.setPosition(dx, dy);
}
