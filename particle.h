#include <stdlib.h>
#include <math.h>
#include "raylib.h"

class Particle
{
private:
    Vector2 pos;
    Vector2 vel;
    Color color;

    float getDistance(Vector2 pos);
    Vector2 getNormal(Vector2 otherPos);

    
public:
    Particle(int screenWidth, int screenHeight);
    Particle(Vector2 pos, Vector2 vel, Color color);

    void attract(Vector2 posToAttract, float multiplier);
    void doFriction(float amount);
    void move(int screenWidth, int screenHeight);
    void drawPixel();
};

Particle::Particle(int screenWidth, int screenHeight)
{
    pos.x = GetRandomValue(0, screenWidth-1);
    pos.y = GetRandomValue(0, screenHeight-1);

    vel.x = GetRandomValue(-100, 100) / 100.f;
    vel.y = GetRandomValue(-100, 100) / 100.f;

    color = (Color){0,0,0,100};
}

Particle::Particle(Vector2 _pos, Vector2 _vel, Color _color)
{
    pos = _pos;
    vel = _vel;
    color = _color;
}
