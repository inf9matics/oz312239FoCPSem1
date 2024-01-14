#pragma once

#include <iostream>
#include <chrono>
#include <random>

struct node
{
	int node_id = 0;
	char node_data[100] = {0};
	node *p_left_descendant_node = nullptr;
	node *p_right_descendant_node = nullptr;
};

int get_random_in_range(int from, int to);
void generateRandomData(char data[]);
void genTree(node *&root, int depth, int& id);
node *extractSubtree(node *&root);
void printTree(const node *root);
void destroyTree(node *&treeRoot);
