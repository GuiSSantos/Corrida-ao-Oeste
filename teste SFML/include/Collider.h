#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
using namespace sf;


class Collider
{
    public:
        Collider(RectangleShape& corpo);
        ~Collider();

        void Move(float dx, float dy);

        bool CheckCollision(Collider& other, Vector2f& direction, float push);
        Vector2f getPosition();
        Vector2f getHalfSize();
    protected:

    private:
        RectangleShape& corpo;
};

#endif // COLLIDER_H
