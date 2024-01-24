#pragma once

#include <iostream>
#include <chrono>
#include <random>
#include <memory>

struct node
{
	int node_id = 0;
	char node_data[100] = {0};
	std::unique_ptr<node> p_left_descendant_node = nullptr;
	std::unique_ptr<node> p_right_descendant_node = nullptr;
};

int get_random_in_range(int from, int to);
void generateRandomData(char data[]);
void genTree(std::unique_ptr<node>& root, int depth, int& id);
std::unique_ptr<node> extractSubtree(std::unique_ptr<node>& root);
void printTree(const node *root);
void destroyTree(std::unique_ptr<node>& treeRoot);