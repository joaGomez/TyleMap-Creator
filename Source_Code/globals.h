#ifndef GLOBALS_H
#define GLOBALS_H


#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

#define WIDTH 20
#define HEIGHT 20

typedef struct {   
    int height;
    int width; 
}dimensions_t;


#endif   // GLOBALS_H