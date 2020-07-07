#include <iostream>
#include <vector>
#include <memory>

using namespace std;
struct Node {

    Node*                  Right;
    Node*                  Left;
    std::vector<double>    point;
    double                 median;
    size_t                 splitaxis;

    Node(double line) :median(line), Right(NULL), Left(NULL) {}
    Node() :median(-1), Right(NULL), Left(NULL) {}

};

class kdTree {
private:
    Node* root;
    size_t                dimension;
    Node* BuildkdTree(std::vector<std::vector<double>>& kdData, size_t depth);
    void  freeMemory(Node* parent);
public:
    kdTree(size_t dim) :dimension(dim) {};
    ~kdTree();
    Node* getRoot();
    void insert(std::vector<std::vector<double>>& kdData);
};