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
	// Проходимся по вершинам
	for (size_t i = 0; i < Vertexs.size(); i++) {
		int minWeight = INT_MAX;
		int _weight = NULL;
		Vertex* _nextPtr = NULL;
		Vertex* _previousPtr = NULL;
		// Смотрим каждое ребро
		for (size_t j = 0; j < Edges.size(); j++) {
			// проверяем связанно ли ребро с нашей вершинной
			if (Edges[j].nextPtr->name == Vertexs[i].name || Edges[j].previousPtr->name == Vertexs[i].name) {
				// Если значение ребра меньше минимально известной, то
				if (Edges[j].weight < minWeight) {
					// Проверяем существует ли уже такое значение
					bool unic = true;
					for (size_t k = 0; k < res.size(); k++)
					{
						if (res[k].weight == Edges[j].weight && res[k].nextPtr == Edges[j].nextPtr && res[k].previousPtr == Edges[j].previousPtr) {
							unic = false;
						}
					}
					if (unic) {
						// Обновляем минимальную
						minWeight = Edges[j].weight;
						// Сохраняем инфу
						_weight = Edges[j].weight;
						_nextPtr = Edges[j].nextPtr;
						_previousPtr = Edges[j].previousPtr;
					}
				}
			}
		}
		if (_weight != NULL && _nextPtr != NULL && _previousPtr != NULL) {
			res.emplace_back(_weight, _nextPtr, _previousPtr);
		}
	}
	
	return res;
}