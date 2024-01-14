#include "utils.h"

int get_random_in_range(int from, int to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

void generateRandomData(char data[])
{
    for(int i = 0; i < 99; i++)
    {
        int randomValue = get_random_in_range(0, 61);

        if (randomValue < 26)
        {
            data[i] = static_cast<char>('a' + randomValue);
        }
        else if (randomValue < 52)
        {
            data[i] = static_cast<char>('A' + (randomValue - 26));
        }
        else
        {
            data[i] = static_cast<char>('0' + (randomValue - 52));
        }
    }
}

void genTree(node *&root, int depth, int& id)
{
    if(depth > 0)
    {
        root = new node;

        root->node_id = id;
        id++;

        generateRandomData(root->node_data);

        genTree(root->p_left_descendant_node, depth - 1, id);
        genTree(root->p_right_descendant_node, depth - 1, id);
    }
}

node *extractSubtree(node *&root)
{
    if(!root)
    {
        return nullptr;
    }

    node *subtree = (get_random_in_range(1,2) == 0) ? root->p_left_descendant_node : root->p_right_descendant_node;

    if(subtree == root->p_left_descendant_node)
    {
        root->p_left_descendant_node = nullptr;
    }
    else
    {
        root->p_right_descendant_node = nullptr;
    }

    return subtree;
}

void printTree(const node *root)
{
    if(root)
    {
        std::cout << "Node " << root->node_id << ": " << root->node_data << std::endl;

        printTree(root->p_left_descendant_node);
        printTree(root->p_right_descendant_node);
    }
}

void destroyTree(node *&treeRoot)
{
    if(treeRoot)
    {
        destroyTree(treeRoot->p_left_descendant_node);
        destroyTree(treeRoot->p_right_descendant_node);

        std::cout << "Node with id " << treeRoot->node_id << " has just been destroyed.\n";

        delete treeRoot;
        treeRoot = nullptr;
    }
}


