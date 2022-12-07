#include "Menu.h"


int main(int, char**) {
    
    Menu* menu = new Menu();

    std::string file_name = "1";
    int state = menu->getState();

    while (!WindowShouldClose() && state != end)
    {
        state = menu->getState();
        if(state == init) {
            menu->drawStarterMenu();
        }
        
        else if(state == start) {
            if(menu->initMap(file_name)) {   // Creates a file for the map distribution
                menu->setState(running);    // Created file successfully and now runs drawing mode
            }
            else {
                // ----------------------------------------------------
                std::cout << "File could not be created." << std::endl;  // File already exists
                // ----------------------------------------------------
            }
        }
        else if(state == running) {
            menu->update();
            menu->drawMap();
        }
        else if(state == pause) {

        }
        else if(state == finish) {
            menu->map->writeFile();
            menu->deleteMap();
            menu->setState(init);
            file_name = "";
        }
    }
    CloseWindow();
    
    return 0;
}
