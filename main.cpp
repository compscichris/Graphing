#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/**
 * Node class is the class being used to represent a node of an object. This object is
 * currently represented as a string, but could be modified to fit the type of the object.
 * @param STRING value: string representation of the value of the node
 */
class Node {
public:
    string value;
    int ref;
    bool set;
    Node(string entry)
    {
        this->value = entry;
        this->ref = -1;
    }

    /*
     * Operator overloading
     */
    bool operator == (const Node &other)
    {
        if(this->value == other.value)
        {
            return true;
        }
        return false;
    }
    bool operator != (const Node &other)
    {
        if(this->value != other.value)
        {
            return true;
        }
        return false;
    }
    bool operator <= (const Node &other)
    {
        if(this->value <= other.value)
        {
            return true;
        }
        return false;
    }
    bool operator >= (const Node &other)
    {
        if(this->value >= other.value)
        {
            return true;
        }
        return false;
    }
    bool operator < (const Node &other)
    {
        if(this->value < other.value)
        {
            return true;
        }
        return false;
    }
    bool operator > (const Node &other)
    {
        if(this->value > other.value)
        {
            return true;
        }
        return false;
    }
};
/**
 * Edge class is the class being used to represent an edge.
 *
 */
class Edge {
private:
    int weight = 0;
    Node *A = nullptr;
    Node *B = nullptr;

public:
    Edge(Node *a, Node *b)
    {
        this->A = a;
        this->B = b;
    }
    void setWeight(int val)
    {
        this->weight = val;
    }
};

/**
 *
 * @tparam T
 */

class NodeSet {
public:
    vector<Node> items;
    NodeSet(vector<Node> set)
    {
        this->items.assign(set.begin(), set.end());
    }
    void add(Node *item)
    {
        if(find(items.begin(), items.end(), *item) == items.end()) {
            items.push_back(*item);
        }
    }
    Node* rem(Node *item)
    {
        Node *retVal = nullptr;
        vector<Node>::iterator pos = find(items.begin(), items.end(), *item);
        if(pos != items.end()) {
            retVal = items.erase(pos).base();
        }
        return retVal;
    }
    void front(Node *item)
    {
        items.insert(items.begin(), *item);
    }
};
/**
 * C++ program for Dijkstra's algorithm using Node class and Set class.
 * Dijkstra's Algorithm is an algorithm used to find the shortest path
 * between nodes in a weighted graph.
 */
class Dijkstra {
public:
    vector<vector<int>> distances;
    NodeSet *nodes = nullptr;
    Dijkstra(Node *bNode, NodeSet nodes)
    {
        nodes.rem(bNode);
        nodes.front(bNode);

    }
    void dijkstra_1(Node *bNode, NodeSet nodes)
    {
        vector<pair<Node*, bool>> spt_Nodes;
        vector<pair<Node*, int>> dist;
        //Begin by setting all distances to Node to be infinite.
        for_each(nodes.items.begin(), nodes.items.end(), [&](Node node){
            pair<Node*,bool> spt_Pair;
            pair<Node*,int> dist_Pair;
            spt_Pair.first = &node;
            spt_Pair.second = false;
            dist_Pair.first = &node;
            dist_Pair.second = INT_MAX;
            spt_Nodes.push_back(spt_Pair);
            dist.push_back(dist_Pair);
        });

    }
};
