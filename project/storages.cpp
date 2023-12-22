#include "storages.h"


//Very bad practice. Scalability is reduced. I do not like it.
std::vector<int> cities; // Implemented globally, so it wouldn't have to be passed to almost every function
std::vector<std::vector<int>> distanceMatrix;
