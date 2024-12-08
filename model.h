#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <climits>
#include <set>

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
std::string getVertexsList();
std::string getEdgesList();

std::string getEdgesList() {
	if (Edges.empty()) {
		return "Edge List:\nEmpty\n";
	}
	else {
		std::string res = "Edge List:\n";
		for (int i = 0; i < Edges.size(); i++) {
			res += Edges[i].previousPtr->name + " " + std::to_string(Edges[i].weight) + " " + Edges[i].nextPtr->name + "\n";
		}
		return res;
	}
}

std::string getVertexsList() {
	if (Vertexs.empty()) {
		return "Vertex List:\nEmpty\n";
	}
	else {
		std::string res = "Vertex List:\n";
		for (int i = 0; i < Vertexs.size(); i++) {
			res += Vertexs[i].name + "\n";
		}
		return res;
	}
}

bool createEdge() {
	bool exit = false;
	while (true) {
		std::string input = "";
		Vertex* _previousVertex = nullptr;
		Vertex* _nextVertex = nullptr;
		std::cout << "Enter name previous Vertex (enter '000' for exit)\n";
		std::cin >> input;
		if (input == "000") {
			exit = true;
			break;
		}
		for (int i = 0; i < Vertexs.size(); i++) {
			if (Vertexs[i].name == input) {
				_previousVertex = &Vertexs[i];
			}
		}
		if (_previousVertex == nullptr) {
			std::cout << "ERROR: Vertex not found!\n";
			continue;
		}
		input = "";
		std::cout << "Enter name next Vertex (enter '000' for exit)\n";
		std::cin >> input;
		if (input == "000") {
			exit = true;
			break;
		}
		for (int i = 0; i < Vertexs.size(); i++) {
			if (Vertexs[i].name == input) {
				_nextVertex = &Vertexs[i];
			}
		}
		if (_nextVertex == nullptr) {
			std::cout << "ERROR: Vertex not found!\n";
			continue;
		}
		std::cout << "Enter weight Edge:\n";
		std::cin >> input;
		int _weight = NULL;
		try {
			_weight = std::stoi(input);
		}
		catch (const std::exception& error) {
			std::cout << "ERROR: Weight not integer!";
		}
		if (_weight == NULL) {
			continue;
		}
		Edges.emplace_back(_weight, _nextVertex, _previousVertex);
		break;
	}
	if (exit) {
		return false;
	}
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

std::vector<Edge> algorithmPrima() {
	std::vector<Edge> res;
	// ѕроходимс€ по вершинам
	for (size_t i = 0; i < Vertexs.size(); i++) {
		int minWeight = INT_MAX;
		Edge* refEdge = nullptr;
		// —мотрим каждое ребро
		for (size_t j = 0; j < Edges.size(); j++) {
			// провер€ем св€занно ли ребро с нашей вершинной
			if (Edges[j].nextPtr->name == Vertexs[i].name || Edges[j].previousPtr->name == Vertexs[i].name) {
				// ≈сли значение ребра меньше минимально известной, то
				if (Edges[j].weight < minWeight) {
					// ќбновл€ем минимальную
					minWeight = Edges[j].weight;
					// —охран€ем ссылку на него
					refEdge = &Edges[j];
				}
			}
		}
		res.emplace_back(refEdge->weight, refEdge->nextPtr, refEdge->previousPtr);
	}

	return res;
}