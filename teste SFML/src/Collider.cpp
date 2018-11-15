#include "Collider.h"


Collider::Collider(RectangleShape& corpo):
    corpo(corpo)
{

}

Collider::~Collider()
{
    //dtor
}
Vector2f Collider::getPosition()
{
    return corpo.getPosition();
}

Vector2f Collider::getHalfSize()
{
    return corpo.getSize()/2.f;
}

void Collider::Move(float dx, float dy)
{
    corpo.move(dx,dy);
}
bool Collider::CheckCollision(Collider& other, Vector2f& direction, float push)
{
    Vector2f otherPosition = other.getPosition();
    Vector2f otherHalfSize = other.getHalfSize();
    Vector2f thisPosition = getPosition();
    Vector2f thisHalfSize = getHalfSize();



    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);


    if (intersectX < 0.0f && intersectY < 0.0f)
    {
        push = std::min(std::max(push, 0.0f), 1.0f);

        if(intersectX > intersectY)
        {
            if(deltaX > 0.0f)
            {
                Move(intersectX * (1.0f - push), 0.0f);
                other.Move(-intersectX * push, 0.0f);


                direction.x=1.f;
                direction.y=0.f;
            }
            else
            {
                Move(-intersectX * (1.0f - push), 0.0f);
                other.Move(intersectX * push, 0.0f);

                direction.x=-1.f;
                direction.y=0.f;
            }
        }
        else
        {
           if(deltaY > 0.0f)
            {
                Move(0.0f, intersectY * (1.0f - push));
                other.Move(0.0f, -intersectY * push);


                direction.x=0.f;
                direction.y=1.f;
            }
            else
            {
                Move(0.0f, -intersectY * (1.0f - push));
                other.Move(0.0f, intersectY * push);


                direction.x=0.f;
                direction.y=-1.f;
            }
        }

        return true;
    }

    return false;
}
