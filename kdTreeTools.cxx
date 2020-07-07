#include "kdTree.h"
#include <iostream>
#include <cmath>
#include <cfloat>

std::vector<double> getNNP(kdTree&, std::vector<double>&);
void searchNNP(Node* treeNode, std::vector<double>& testPoint, std::vector<double>& nearestNode, double& nearestDistance );

void
searchNNP(  Node*                   treeNode, 
            std::vector<double>&    testPoint, 
            std::vector<double>&    nearestNode, 
            double&                 nearestDistance )
{
    double distance;
    double delx;
    double dely;
    size_t dim;
    bool   first_left = false;

    if (treeNode != NULL) {
        Node* left = treeNode->Left;
        Node* right = treeNode->Right;
        if (left == NULL && right == NULL) {// leaf node
            delx = std::abs((treeNode->point)[0] - testPoint[0]);
            dely = std::abs((treeNode->point)[1] - testPoint[1]);
            distance = std::sqrt(powf(delx,2)+powf(dely,2));
            if (distance < nearestDistance) {
                nearestDistance = distance;
                nearestNode = treeNode->point;
            }
        }
        else {
            dim = treeNode->splitaxis;
            if ((testPoint[dim] - nearestDistance) <= treeNode->median) {
                first_left = true;
            }
            else {
                first_left = false;
            }

            if (first_left) {
                if ((testPoint[dim] - nearestDistance) <= treeNode->median) {
                    searchNNP(left, testPoint, nearestNode, nearestDistance);
                }
                if ((testPoint[dim] + nearestDistance) > treeNode->median) {
                    searchNNP(right, testPoint, nearestNode, nearestDistance);
                }
            }
            else {
                if ((testPoint[dim] + nearestDistance) > treeNode->median) {
                    searchNNP(right, testPoint, nearestNode, nearestDistance);
                }
                if ((testPoint[dim] - nearestDistance) <= treeNode->median) {
                    searchNNP(left, testPoint, nearestNode, nearestDistance);
                }
            }
        }
    }

}//searchNNP

std::vector<double>
getNNP( kdTree&                  tree,
        std::vector<double>&     testPoint    ) 
{
    std::vector<double> nearestPoint = {0.0, 0.0};
    double nearestDistance = DBL_MAX;
    Node* root = tree.getRoot();
    if(!testPoint.empty()){
        searchNNP(root, testPoint, nearestPoint, nearestDistance);
    }
    return nearestPoint;
}//getNNP
