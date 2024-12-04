#include <vector>
#include <iostream>

class Vertex {
public:
	Vertex(std::string _name) {
		name = _name;
	}
	std::string name;
};

class Edge {
public:
	Edge(int _weight, Vertex* _nextPtr, Vertex* _previousPtr) {
		weight = _weight;
		nextPtr = _nextPtr;
		previousPtr = _previousPtr;
	}
	int weight;
	Vertex* nextPtr;
	Vertex* previousPtr;
};

std::vector<Edge> Edges;
std::vector<Vertex> Vertexs;

bool createEdge();
bool createVertex();

int main() {
	setlocale(LC_ALL, "Russian");
	bool isOn = true;
	std::string input = "";
	while (isOn) {
		std::cout << "1) Add Vertex\n2) Add the vertex of the edge\n";
		std::cin >> input;
		if (input == "1") {
			if (createVertex() == true) {
				std::cout << "The vertex was successfully added.\n";
			}
			else {
				isOn = false;
			}
		}
		else if (input == "2") {
			createEdge();
		}
		else {
			std::cout << "ERROR: Unknown action!\n";
		}
	}
}

bool createEdge() {
	return true;
}

bool createVertex() {
	std::string _name;
	std::cout << "Enter name for Vertex:";
	std::cin >> _name;
	try {
		Vertexs.emplace_back(_name);
		return true;
	}
	catch (const std::exception& error) {
		std::cout << "ERROR: " << *error.what();
		return false;
	}
}