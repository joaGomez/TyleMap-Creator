#ifndef MENU_H
#define MENU_H

#include "Map.h"

#define PIXELS_BY_CELL  40   // Window's pixels by every cell of the map


class Menu {
    public:
        // Constructor and destructor
        Menu();
        ~Menu();

        // Variables
        Map* map;

        // Functions
        void initMap(std::string map_name);
        void deleteMap();
        void draw();
        void update();

        // Getters


        // Setters

    private:
        // Variables
        dimensions_t window_dimensions;

        // Functions
        int mousePosInMap(Vector2 mouse_pos);



};

#endif  // MENU_H
