#include "Menu.h"


int main(int, char**) {
    
    Menu* menu = new Menu();

    menu->initMap("1");
    menu->map->writeFile();

    while (!WindowShouldClose())
    {
        menu->update();

        // Drawing
        BeginDrawing();
        ClearBackground(GRAY);
        menu->draw();
        DrawFPS(10, 10);
        EndDrawing();


    }

    menu->map->writeFile();
    CloseWindow();
    
}
