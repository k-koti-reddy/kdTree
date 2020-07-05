#include "kdTree.h"
#include <cstring>
#include <cstdlib>
#include <algorithm>

kdTree::~kdTree() {
    freeMemory(root);
}

void
kdTree::freeMemory(Node* parent) {

    if (parent != NULL) {
        Node* left = parent->Left;
        Node* right = parent->Right;
        if (left == NULL && right == NULL) {// At leaf the left/right nodes are null.
            delete parent;
        }
        else {
            freeMemory(left);
            freeMemory(right);
            delete parent;
        }
    }
}

void
kdTree::insert(std::vector<std::vector<double>>& kdData) {
    root = BuildkdTree(kdData, 0);
}

Node*
kdTree::BuildkdTree(std::vector<std::vector<double>>&  kdData,
                    size_t                             depth)
{
    size_t num_of_points = kdData.size();
    std::vector<std::vector<double>> P1;
    std::vector<std::vector<double>> P2;
    double median;
    size_t currentDimension;

    //Logic starts;
    if (num_of_points == 1) {
        Node* leaf = new Node();
        leaf->point = kdData[0];
        return leaf;
    }
    else if (num_of_points != 0 && num_of_points != 1) {

        currentDimension = depth % dimension;
        //sort the array.
        auto comparator = [currentDimension](std::vector<double>& a, std::vector<double>& b) {return a[currentDimension] < b[currentDimension]; };
        std::sort(kdData.begin(), kdData.end(), comparator);

        if (num_of_points % 2 == 0) {//if number of data points are even
            auto middlePoint = num_of_points / 2;
            median = (kdData[middlePoint][currentDimension] + kdData[middlePoint - 1][currentDimension]) / 2.0;
            for (auto& data : kdData) {
                if (data[currentDimension] <= median) {
                    P1.push_back(data);
                }
                else {
                    P2.push_back(data);
                }
            }
        }
        else {//if number of data points are odd
            auto middlePoint = (num_of_points - 1) / 2;
            median = kdData[middlePoint][currentDimension];
            for (auto& data : kdData) {
                if (data[currentDimension] <= median) {
                    P1.push_back(data);
                }
                else {
                    P2.push_back(data);
                }
            }
        }

        Node* left = BuildkdTree(P1, depth + 1);//bottom
        Node* right = BuildkdTree(P2, depth + 1);//top
        Node* parent = new Node(median);
        parent->Left = left;
        parent->Right = right;
        parent->splitaxis = currentDimension;
        return parent;
    }
    return NULL;
}

Node* 
kdTree::getRoot() {
    return root;
}