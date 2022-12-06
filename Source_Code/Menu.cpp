#include "Menu.h"

Menu::Menu()
{
    this->window_dimensions = { .height = HEIGHT * PIXELS_BY_CELL, .width = WIDTH * PIXELS_BY_CELL};
    InitWindow(this->window_dimensions.width, this->window_dimensions.height, "TyleMap Creator");
}

Menu::~Menu()
{

}

void Menu::initMap(std::string map_name)
{
    this->map = new Map(map_name);
    this->map->init();
}

void Menu::deleteMap()
{
    delete this->map;
}

void Menu::draw()
{
    for(int i = 0 ; i < map->map_dimensions.height ; i++ ) {
        for(int j = 0 ; j < map->map_dimensions.width ; j++ ) {        // Inits map distribution empty
            DrawRectangle( j * PIXELS_BY_CELL + 2, i * PIXELS_BY_CELL + 2, 
            PIXELS_BY_CELL - 2, PIXELS_BY_CELL - 2, map->distributionValue(map->map_distribution[i * map->map_dimensions.height + j]));
        }
    }
}

int Menu::mousePosInMap(Vector2 mouse_pos)
{
    int index = -1;
    for(int i = 0 ; i < map->map_dimensions.height ; i++ ) {
        for(int j = 0 ; j < map->map_dimensions.width ; j++ ) {
            if( mouse_pos.x >= j * PIXELS_BY_CELL + 2 && mouse_pos.x <= j * PIXELS_BY_CELL + PIXELS_BY_CELL + 2
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
        if(IsMouseButtonPressed(0)) {
            std::cout << "Mouse left button pressed." << std::endl;
            if(map->map_distribution[index] != 1) {
                map->map_distribution[index] = 1;   // Place a wall
            }
            else {  // If there it was already a wall
                map->map_distribution[index] = 0;   // Leaves empty space
            }
        }
        else if(IsMouseButtonPressed(1)) {
            std::cout << "Mouse right button pressed." << std::endl;
            if(map->map_distribution[index] != 2) {
                map->map_distribution[index] = 2;   // Place a door
            }
            else {  // If there it was already a door
                map->map_distribution[index] = 0;   // Leaves empty space
            }
        }
    }
}