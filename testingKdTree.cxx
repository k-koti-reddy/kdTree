// Testing-kdTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "kdTree.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<double> getNNP(kdTree&, std::vector<double>&);
int main() {

    std::ifstream fin;
    std::string line;
    std::string coord;
    double      axis;

    std::vector<std::vector<double>> points;
    std::vector<double> coordinates;
    fin.open("UnitSquare1000.txt");

    if (fin.fail()) {
        std::cerr << "Error Opening file" << std::endl;
        exit(1);
    }

    points.reserve(1000);
    coordinates.reserve(10);
    while (!fin.eof())
    {
        std::getline(fin, line);
        std::istringstream ss(line);
        coordinates.clear();
        while (std::getline(ss, coord, ' ')) {
            axis = std::stod(coord);
            coordinates.push_back(axis);
        }
        points.push_back(coordinates);
    }

    //Create kdTree and insert the points.
    std::vector<double> point = {0.5,0.7};
    std::vector<double> nearestPoint;
    kdTree dTree(2);
    dTree.insert(points);
    nearestPoint = getNNP(dTree, point);
    std::cout << nearestPoint[0] << " " << nearestPoint[1] << std::endl;
    return 0;
}