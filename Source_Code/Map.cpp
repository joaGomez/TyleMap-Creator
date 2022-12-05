#include "Map.h"

Map::Map(std::string index)
{
    this->file_name = "Map_" + index + ".txt";
    this->path = std::filesystem::current_path().parent_path();

    this->map_dimensions = { HEIGHT, WIDTH };

}

Map::~Map()
{

}

std::string Map::getName()
{ return this->file_name; }

std::filesystem::path Map::getPath()
{
    return this->path;
}

bool Map::init()
{
    std::filesystem::current_path(getPath());       // Updates file path (exits build folder)
    if(std::filesystem::exists(getName())) {        // Verifies file in current folder
        // ---------------------------------------------------
        std::cout << "This file already exists." << std::endl;
        // ---------------------------------------------------

        return false;       // If the file exists, then it has to change the map's name
    }
    else {
        // -------------------------------------------------
        std::cout << "This file doesn't exist" << std::endl;
        // -------------------------------------------------

        for(int i = 1 ; i < this->map_dimensions.height ; i++ ) {
            for(int j = 1 ; j < this->map_dimensions.width ; j++ ) {        // Inits map distribution empty
                this->map_distribution.push_back('0');
            }
        }

        std::ofstream file(getName());
        if(std::filesystem::exists(getName()))
        { std::cout << "File created succesfully." << std::endl; }

        return true;        // The file doesn't exist in the current folder so now it created a file with that name
    }
}
