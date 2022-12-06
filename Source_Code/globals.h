#ifndef GLOBALS_H
#define GLOBALS_H


#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "raylib.h"


// ----------
// CONSTANTS
// ----------
#define WIDTH 20
#define HEIGHT 20


// ----------
// VARIABLES
// ----------
typedef struct {   
    int height;
    int width; 
}dimensions_t;


#endif   // GLOBALS_H