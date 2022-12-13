#include "Menu.h"

bool inside(Vector2 pos, int x1, int y1, int x2, int y2)
{
    if(pos.x >= x1 && pos.x <= x2 && pos.y >= y1 && pos.y <= y2)
        return true;
    else
        return false;
}

// Check if any key is pressed (FROM: Raylib tutorial)
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}

Menu::Menu()
{
    this->window_dimensions = { .height = HEIGHT * PIXELS_BY_CELL, .width = WIDTH * PIXELS_BY_CELL + 350};
    InitWindow(this->window_dimensions.width, this->window_dimensions.height, "TyleMap Creator");
    setState(init);
    this->map_flag = false;
    this->map_name = "";
    this->frames_counter = 0;
    this->name_error = false;
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
    Vector2 mouse_pos = GetMousePosition();
    
    BeginDrawing();
    ClearBackground(BLACK);

    if(this->map_flag == true) {
        if(IsMouseButtonPressed(0) && inside(mouse_pos, 255 + 175, 290, 600 + 175, 330)) {
            DrawText("Write your map name here.", 225 + 175, 290, 30, GRAY);
            // this->map_flag = false;
        }
        DrawText("|", 285 + MeasureText(this->map_name.c_str(), 40) - 3*this->map_name.size() + 175, 290, 40, WHITE);
        DrawText(this->map_name.c_str(), 285 + 175, 290, 35, WHITE);
        DrawText("Exit", 380 + 175, 450, 40, WHITE);
        this->frames_counter++;

        // ----------------------------
        int key = GetCharPressed();
        if ((key >= 33) && (key <= 125) && (this->map_name.size() < MAX_CHARACTERS)) {
            if(key != KEY_PERIOD)
            this->map_name = this->map_name + (char)key;
        }
    
        if (IsKeyPressed(KEY_BACKSPACE) && this->map_name.size() > 0) {
            this->map_name.erase(this->map_name.size() - 1, 1);
        }
        if(IsKeyPressed(KEY_ENTER) && this->map_name.size() > 0) {
            setState(start);
        }
    }
    else {
        if(IsMouseButtonPressed(0) && inside(mouse_pos, 255 + 175, 290, 600 + 175, 330)) {
            DrawText(this->map_name.c_str(), 285 + 175, 290, 35, WHITE);
            this->map_flag = true;
        }
        else if(map_name.size() > 0) {
            DrawText(this->map_name.c_str(), 285 + 175, 290, 35, WHITE);
        }
        else if(inside(mouse_pos, 255 + 175, 290, 600 + 175, 330)) {
            DrawText("Write your map name here.", 225 + 175, 290, 30, GRAY);
        }
        else {
            DrawText("New Map", 325 + 175, 290, 40, WHITE);
        }
        DrawText("Exit", 380 + 175, 450, 40, WHITE);
        this->frames_counter = 0;
    }
    if(IsMouseButtonPressed(0) && !inside(mouse_pos, 255 + 175, 290, 600 + 175, 330) && !inside(mouse_pos, 380 + 175, 450, 500 + 175, 490)) {
        this->map_flag = false;
    }
    else if(IsMouseButtonPressed(0) && inside(mouse_pos, 380 + 175, 450, 500 + 175, 490)) {
        this->setState(end);
        std::cout << this->map_name << std::endl;
    }
    if(this->name_error == true) {
        DrawText("ERROR: This map name is already in use.", 115 + 175, 690, 30, RED);
    }

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
    DrawText("PRESS:", 900, 50, 30, WHITE);
    DrawText("D -> Delete wall/door", 850, 150, 20, WHITE);
    DrawText("LEFT CLICK -> Add wall", 850, 200, 20, WHITE);
    DrawText("RIGHT CLICK -> Add door", 850, 250, 20, WHITE);
    DrawText("ENTER -> Save map", 850, 700, 25, WHITE);
    DrawText("ESC -> Exit", 850, 750, 25, WHITE);

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
            map->map_distribution[index] = 1;
            /*if(map->map_distribution[index] != 1) {
                map->map_distribution[index] = 1;   // Place a wall
            }
            else {  // If there it was already a wall
                map->map_distribution[index] = 0;   // Leaves empty space
            }*/
        }
        else if(IsMouseButtonPressed(1) || IsMouseButtonDown(1)) {
            std::cout << "Mouse right button pressed." << std::endl;
            map->map_distribution[index] = 2;
            /*if(map->map_distribution[index] != 2) {
                map->map_distribution[index] = 2;   // Place a door
            }
            else {  // If there it was already a door
                map->map_distribution[index] = 0;   // Leaves empty space
            }*/
        }
        else if(IsKeyPressed(KEY_D)) {
            std::cout << "Key DELETE pressed." << std::endl;
            map->map_distribution[index] = 0;
        }
        else if(IsKeyPressed(KEY_ENTER)) {
            setState(finish);
        }
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