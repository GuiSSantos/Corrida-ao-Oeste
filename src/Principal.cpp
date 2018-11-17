#include "Principal.h"
#include "Menu.h"
#include "Menu2.h"
#include"Jogador2.h"
#include"Pausa.h"

Principal::Principal()
{

}

Principal::~Principal()
{
    //dtor
}

void Principal::Executar()
{

    RenderWindow window(sf::VideoMode(800, 600), "Corrida para o Oeste",Style::Close|Style::Titlebar);
    Menu menu1(window.getSize().x, window.getSize().x);
    Menu2 menu2(window.getSize().x, window.getSize().x);

    View view(Vector2f(0.0f,0.0f), Vector2f(800.f,600.f));



    Texture textureJogador1, textureJogador2;
    textureJogador1.loadFromFile("sprite2.png");
    textureJogador2.loadFromFile("sprite22.png");
    Jogador jogador1(&textureJogador1,Vector2u(8,12),0.1f,500.0f,128.f);
    Jogador2 jogador2(&textureJogador2,Vector2u(8,12),0.1f,200.0f,128.f);

    Pausa pause (200.f, -1200.f);

    Vector2u textureSize = textureJogador1.getSize();
    textureSize.x/=8;
    textureSize.y/=12;

    Vector2u textureSize2 = textureJogador1.getSize();
    textureSize2.x/=8;
    textureSize2.y/=12;

    Fase1 fase1;

    bool jogoPronto2 = false, jogoPronto1 = false, desenhaMenu = true, desenhaMenu2 = false, fase1Pronta = false, fase2Pronta = false, _pause = false, desenhaPause = false;



    float deltaTime=0.0f;
    Clock relogio;

    while (window.isOpen())
    {
        deltaTime = relogio.restart().asSeconds();
        if(deltaTime>1.f/20.f)
            deltaTime=1.f/20.f;

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::P:
                    _pause=true;
                    break;
                case sf::Keyboard::W:
                    menu1.MoveUp();
                    menu2.MoveUp();
                    pause.MoveUp();
                    break;

                case sf::Keyboard::S:
                    menu1.MoveDown();
                    menu2.MoveDown();
                    pause.MoveDown();
                    break;

                case sf::Keyboard::BackSpace:
                    switch (menu2.GetPressedItem())
                    {
                    case 0:
                        printf("\n Fase1 button has been pressed \n");
                        jogoPronto1=true;
                        desenhaMenu2=false;
                        _pause=false;
                        break;
                    case 1:
                        jogoPronto2=true;
                        desenhaMenu2=false;
                        break;
                    case 2:
                        window.close();
                        break;

                    }
                    break;

                case sf::Keyboard::Return:
                    switch (menu1.GetPressedItem())
                    {
                    case 0:
                        printf("\n Fase1 button has been pressed \n");
                        desenhaMenu = false;
                        desenhaMenu2 = true;
                        fase1Pronta=true;
                        break;
                    case 1:
                        desenhaMenu = false;
                        desenhaMenu2 = true;
                        fase2Pronta=true;
                        break;
                    case 2:
                        window.close();
                        break;

                    }
                break;

                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }

        }


        if (jogoPronto1==true && fase1Pronta)
        {
            fase1.Executar(window,deltaTime,jogador1,view);
            if (_pause==false)
            {
                jogador1.Desenha(window);
                jogador1.Atualiza(deltaTime);
                fase1.Atualiza(deltaTime);
            }

        }
        else if (jogoPronto2==true && fase1Pronta)
        {
            fase1.Executar2(window,deltaTime,jogador1, view, jogador2);
            if (_pause==false)
            {
                jogador2.Desenha(window);
                jogador1.Desenha(window);
                jogador1.Atualiza(deltaTime);
                jogador2.Atualiza(deltaTime);
                fase1.Atualiza2(deltaTime);
            }

        }
        else if (jogoPronto1==true && fase2Pronta)
        {
            fase1.Executar(window,deltaTime,jogador1,view);
            if (_pause==false)
            {
                jogador1.Desenha(window);
                jogador1.Atualiza(deltaTime);
            }

        }
        else if (jogoPronto2==true && fase2Pronta)
        {

            fase1.Executar2(window,deltaTime,jogador1, view, jogador2);
            if (_pause==false)
            {
                jogador2.Desenha(window);
                jogador1.Desenha(window);
                jogador1.Atualiza(deltaTime);
                jogador2.Atualiza(deltaTime);
            }
        }
        if (_pause==true)
        {
            pause.setPosition(jogador1.GetPosition().x+100, jogador1.GetPosition().y-300);
            pause.draw(window);
        }
        if (desenhaMenu==true)
        {
            menu1.draw(window);
        }
        if (desenhaMenu2==true)
        {
            menu2.draw(window);
        }

        window.display();
        window.clear();
    }
}
