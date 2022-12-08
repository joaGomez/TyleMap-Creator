#ifndef MENU_H
#define MENU_H

#include "Map.h"

#define PIXELS_BY_CELL  40   // Window's pixels by every cell of the map
#define MAX_CHARACTERS  8    // Max characters for map name

enum states {
    init,      // Init menu variables
    start,     // Init map
    running,   // Painting map in progress
    pause,     // Pause menu while running
    finish,    // Finish drawing map
    end        // End program
};

bool inside(Vector2 pos, int x1, int y1, int x2, int y2);
bool IsAnyKeyPressed();

class Menu {
    public:
        // Constructor and destructor
        Menu();
        ~Menu();

        // Variables
        Map* map;
        bool map_flag;
        std::string map_name;
        int frames_counter;

        // Functions
        bool initMap(std::string map_name);
        void deleteMap();
        void drawStarterMenu();
        void drawMap();
        void update();

        // Getters
        int getState();

        // Setters
        void setState(int new_state);

    private:
        // Variables
        dimensions_t window_dimensions;
        int state;

        // Functions
        int mousePosInMap(Vector2 mouse_pos);


};

#endif  // MENU_H
