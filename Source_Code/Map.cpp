#include "Map.h"

Map::Map(std::string name)
{
    this->file_name = "Map_" + name + ".txt";
    this->path = std::filesystem::current_path().parent_path();

    this->map_dimensions = { .height = HEIGHT, .width = WIDTH };

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
        // ---------------------------------------------------------
        std::cout << "ERROR: This file already exists." << std::endl;
        // ---------------------------------------------------------

        return false;       // If the file exists, then it has to change the map's name
    }
    else {

        for(int i = 0 ; i < this->map_dimensions.height ; i++ ) {
            for(int j = 0 ; j < this->map_dimensions.width ; j++ ) {        // Inits map distribution empty
                this->map_distribution.push_back(0);
            }
        }

        std::ofstream file(getName());
        if(std::filesystem::exists(getName())) {
            // ------------------------------------------------------------
            std::cout << "The file was created successfully." << std::endl;
            // ------------------------------------------------------------
        }

        return true;        // The file doesn't exist in the current folder so now it created a file with that name
    }
}


void Map::writeFile()
{
    std::ofstream file;
    file.open(getName());
    if( !file ) {                   // file couldn't be opened
        // ----------------------------------------------------------
        std::cout << "Error: file could not be opened." << std::endl;
        // ----------------------------------------------------------
        return;
    }

    for( int i = 0 ; i < this->map_distribution.size() ; i++ ) {
        if( i % this->map_dimensions.height == 0 ) {
            if(i != 0)
                file << std::endl;
            file << this->map_distribution[i];      // Writes in a file the map distribution in a readable way
        }
        else {
            file << " " << this->map_distribution[i];
        }
    }
    file.close();
}

Color Map::distributionValue(int value)
{
    switch (value)
    {
        case 0:             // Empty space
            return BLACK;
        case 1:             // Wall
            return WHITE;
        case 2:             // Door
            return RED;

        default:
            break;
    }
    return BLACK;           // Possible misvalue
}