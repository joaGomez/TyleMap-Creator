#ifndef MAP_H
#define MAP_H

#include "globals.h"

class Map {
    public:
        Map(std::string index);
        ~Map();

        // Public variables
        std::vector<char> map_distribution;

        // Public functions
        bool init();
        void draw();

        // Getters
        std::string getName();
        std::filesystem::path getPath();
        dimensions_t getDimensions();

    private:
        // Private variables
        std::string file_name;
        std::filesystem::path path;
        
        dimensions_t map_dimensions;




};

#endif    // MAP_H