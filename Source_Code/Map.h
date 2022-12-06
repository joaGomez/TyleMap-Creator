#ifndef MAP_H
#define MAP_H

#include "globals.h"

class Map {
    public:
        // Constructor and destructor
        Map(std::string index);
        ~Map();

        // Public variables
        std::vector<int> map_distribution;
        dimensions_t map_dimensions;

        // Public functions
        bool init();
        void draw();
        void writeFile();

        // Getters
        std::string getName();
        std::filesystem::path getPath();
        dimensions_t getDimensions();

    private:
        // Private variables
        std::string file_name;
        std::filesystem::path path;
        




};

#endif    // MAP_H