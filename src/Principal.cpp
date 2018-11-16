#include "Principal.h"
#include "Menu.h"

Principal::Principal()
{

}

Principal::~Principal()
{
    //dtor
}

void Principal::Executar(){

    RenderWindow window(sf::VideoMode(800, 600), "Corrida para o Oeste",Style::Close|Style::Titlebar);
    Menu menu1(window.getSize().x, window.getSize().x);



    Texture testeTexture;
    testeTexture.loadFromFile("sprite2.png");
    Jogador jogador1(&testeTexture,Vector2u(8,12),0.1f,200.0f,128.f);

    Vector2u textureSize = testeTexture.getSize();
    textureSize.x/=8;
    textureSize.y/=12;

    Fase1 fase1;

    View view(Vector2f(0.0f,0.0f), Vector2f(800.f,600.f));

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
				case sf::Keyboard::W:
					menu1.MoveUp();
					break;

				case sf::Keyboard::S:
					menu1.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu1.GetPressedItem())
					{
					case 0:
					    printf("\n Fase1 button has been pressed \n");
					    fase1.Executar(window,deltaTime,jogador1,view);
					    jogador1.Desenha(window);
                        break;
					case 1:
						printf("\n Fase2 button has been pressed \n");
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
        jogador1.Atualiza(deltaTime);
        menu1.draw(window);

        window.display();
        window.clear();
    }
}
