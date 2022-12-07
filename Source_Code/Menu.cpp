#include "Menu.h"

Menu::Menu()
{
    this->window_dimensions = { .height = HEIGHT * PIXELS_BY_CELL, .width = WIDTH * PIXELS_BY_CELL};
    InitWindow(this->window_dimensions.width, this->window_dimensions.height, "TyleMap Creator");
    setState(init);
    map_flag = false;
}

Menu::~Menu()
{

}

bool Menu::initMap(std::string map_name)
{
    this->map = new Map(map_name);
    return this->map->init();
}

void Menu::deleteMap()
{
    delete this->map;
}

void Menu::drawStarterMenu()
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("New Map", 325, 290, 40, WHITE);
    DrawText("Exit", 380, 450, 40, WHITE);

    EndDrawing();
}

void Menu::drawMap()
{
    BeginDrawing();
    ClearBackground(GRAY);

    for(int i = 0 ; i < map->map_dimensions.height ; i++ ) {
        for(int j = 0 ; j < map->map_dimensions.width ; j++ ) {        // Draw every map cell
            DrawRectangle( j * PIXELS_BY_CELL + 2, i * PIXELS_BY_CELL + 2, 
            PIXELS_BY_CELL - 2, PIXELS_BY_CELL - 2, map->distributionValue(map->map_distribution[i * map->map_dimensions.height + j]));
        }
    }

    DrawFPS(10, 10);
    EndDrawing();
}

int Menu::mousePosInMap(Vector2 mouse_pos)
{
    int index = -1;
    for(int i = 0 ; i < map->map_dimensions.height ; i++ ) {
        for(int j = 0 ; j < map->map_dimensions.width ; j++ ) {
            if(i == 0 || i == map->map_dimensions.height - 1 ||
                j == 0 || j == map->map_dimensions.width - 1) {
                // To avoid ifs chain: by this we avoid changing the border´s value
            }
            else if( mouse_pos.x >= j * PIXELS_BY_CELL + 2 && mouse_pos.x <= j * PIXELS_BY_CELL + PIXELS_BY_CELL + 2
            && mouse_pos.y >= i * PIXELS_BY_CELL + 2 && mouse_pos.y <= i * PIXELS_BY_CELL + PIXELS_BY_CELL + 2) {
                index = i * map->map_dimensions.height + j;
            }
        }
    }
    return index;   // Returns matrix' index where it is the mouse position
}

void Menu::update()
{
    Vector2 mouse_pos = GetMousePosition();
    int index = mousePosInMap(mouse_pos);
    if(index != -1) {
        if(IsMouseButtonPressed(0) || IsMouseButtonDown(0)) {
            std::cout << "Mouse left button pressed." << std::endl;
            if(map->map_distribution[index] != 1) {
                map->map_distribution[index] = 1;   // Place a wall
            }
            else {  // If there it was already a wall
                map->map_distribution[index] = 0;   // Leaves empty space
            }
        }
        else if(IsMouseButtonPressed(1) || IsMouseButtonDown(1)) {
            std::cout << "Mouse right button pressed." << std::endl;
            if(map->map_distribution[index] != 2) {
                map->map_distribution[index] = 2;   // Place a door
            }
            else {  // If there it was already a door
                map->map_distribution[index] = 0;   // Leaves empty space
            }
        }
    }
    if(IsKeyDown(KEY_ESCAPE) || IsKeyPressed(KEY_ESCAPE)) {
        setState(finish);
    }
}

// Getters

int Menu::getState()
{
    return this->state;
}

// Setters

void Menu::setState(int new_state)
{
    this->state = new_state;
}