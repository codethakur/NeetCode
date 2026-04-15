#include"iostream"
#include<vector>
#include<string>
using namespace std;


struct Point
{
   float x;
   float y;
};

struct QNode
{
    float x, y, w, h;
    int capacity;
    QNode(float x, float y, float w, float h, int cap) 
        :x(x), y(y), w(w), h(h), capacity(cap){}
    
    std::vector<Point>points;
    QNode* NW = nullptr;
    QNode* NE = nullptr;
    QNode* SW = nullptr;
    QNode* SE = nullptr;

    ~QNode() {
        delete NW; delete NE;
        delete SW; delete SE;
    }
};

bool contains(QNode* node, Point p)
{
    return p.x>= node->x && p.x < node->x + node->w &&
           p.y>= node->y && p.y< node->y + node->h;
}

void subdivide(QNode* node)
{
    float hw = node->w/2;
    float hh = node->h/2;

    node->NW = new QNode(node->x, node->y, hw, hh, node->capacity);
    node->NE = new QNode(node->x + hw, node->y, hw, hh, node->capacity);

    node->SW = new QNode(node->x, node->y + hh, hw, hh, node->capacity);
    node->SE = new QNode(node->x+hw, node->y + hh, hw, hh, node->capacity);
}

void insert(QNode* node, Point p) {
    if (!contains(node, p)) return;

    if ((int)node->points.size() < node->capacity && node->NW == nullptr) {
        node->points.push_back(p);
        return;
    }

    if (node->NW == nullptr) {
        subdivide(node);
        for (Point& old : node->points) {
            if(contains(node->NW, old)) insert(node->NW, old);
            else if (contains(node->NE, old)) insert(node->NE, old);
            else if (contains(node->SW, old)) insert(node->SW, old);
            else if (contains(node->SE, old)) insert(node->SE, old);
        }
        node->points.clear();
    }

    if(contains(node->NW, p)) insert(node->NW, p);
    else if (contains(node->NE, p)) insert(node->NE, p);
    else if (contains(node->SW, p)) insert(node->SW, p);
    else if (contains(node->SE, p)) insert(node->SE, p);
}

void print(QNode* node, int depth = 0) {
    if (node == nullptr) return;  // same as BST base case

    std::string indent(depth * 2, ' ');

    std::cout << indent << "Node [region: ("
         << node->x << "," << node->y << ") "
         << node->w << "x" << node->h << "]";

    if (!node->points.empty()) {
        cout << " → points: ";
        for (auto& p : node->points)
            cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << "\n";

    // Recurse into all 4 children (like left/right in BST)
    print(node->NW, depth + 1);
    print(node->NE, depth + 1);
    print(node->SW, depth + 1);
    print(node->SE, depth + 1);
}

int main() {
    // Create root: a 100x100 space, each node holds max 2 points
    QNode* root = new QNode(0, 0, 100, 100, 2);

    // Insert points (like inserting values into BST)
    insert(root, {10, 10});
    insert(root, {20, 80});
    insert(root, {70, 30});
    insert(root, {60, 60});
    insert(root, {15, 15});  // triggers subdivision!
    insert(root, {80, 90});

    std::cout << "=== Quadtree Structure ===\n";
    print(root);

    delete root;  // cleans up all children via destructor
    return 0;
} 
