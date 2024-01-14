#include<stdlib.h>
#include "raylib.h"
#include "particle.h"

int main() { 
    const int screenWidth = 800; 
    const int screenHeight = 800;

    SetRandomSeed(69);

    const long numOfParticles = 10000;

    Particle *particles = (Particle*) malloc(numOfParticles * sizeof(Particle));

    for(long long i = 0; i < numOfParticles; i++) { 
        particles[i] = Particle(screenWidth, screenHeight);
    }

    InitWindow(screenWidth, screenHeight, "raylib");

    SetTargetFPS(60); 

    while(!WindowShouldClose()) { 
        Vector2 mousePos = (Vector2) {(float)GetMouseX(), (float)GetMouseY()};

        for(int i = 0; i < numOfParticles; i++) { 
            particles[i].attract(mousePos, 1);
            particles[i].doFriction(0.99); 
            particles[i].move(screenWidth, screenHeight);
        }

        BeginDrawing();

            ClearBackground(BLACK);

            for (int i = 0; i < numOfParticles; i++)
            {
                particles[i].drawPixel();
            }

            // DrawFPS(24, 24);

        EndDrawing();
    }


    CloseWindow();
    MemFree(particles);

    return 0; 
}