#include "Menu.h"


int main(int, char**) {
    
    Menu* menu = new Menu();

    int state = menu->getState();

    SetTargetFPS(30);

    while (!WindowShouldClose() && state != end)
    {
        state = menu->getState();
        if(state == init) {
            menu->drawStarterMenu();
        }
        
        else if(state == start) {
            if(menu->initMap(menu->map_name)) {   // Creates a file for the map distribution
                menu->map_flag = false;
                menu->name_error = false;
                menu->setState(running);    // Created file successfully and now runs drawing mode
            }
            else {
                // ----------------------------------------------------
                std::cout << "File could not be created." << std::endl;  // File already exists
                // ----------------------------------------------------
                menu->setState(init);
                menu->name_error = true;
                menu->map_flag = false;
            }
        }
        else if(state == running) {
            menu->update();
            menu->drawMap();
        }
        else if(state == pause) {

        }
        else if(state == finish) {
            menu->setState(init);
            menu->map->writeFile();
            menu->deleteMap();
            menu->map_name = "";
            std::cout << "Map deleted successfully." << std::endl;
        }
    }
    CloseWindow();
    
    return 0;
}