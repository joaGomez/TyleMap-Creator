#ifndef MAP_H
#define MAP_H

#include "globals.h"



class Map {
    public:
        // Constructor and destructor
        Map(std::string name);
        ~Map();

        // Variables
        std::vector<int> map_distribution;
        dimensions_t map_dimensions;

        // Functions
        bool init();
        void draw();
        void writeFile();
        Color distributionValue(int value);

        // Getters
        std::string getName();
        std::filesystem::path getPath();
        dimensions_t getDimensions();

    private:
        // Variables
        std::string file_name;
        std::filesystem::path path;


};

#endif    // MAP_H