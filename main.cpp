#include "model.h"



int main() {
	setlocale(LC_ALL, "Russian");
	bool isOn = true;
	std::string input = "";
	while (isOn) {
		std::cout << "1) Add Vertex\n2) Add the vertex of the edge\n3) Get List Vertexs\n4) Get List Edge\n";
		std::cin >> input;
		if (input == "1") {
			if (createVertex()) {
				std::cout << "The vertex was successfully added.\n";
			}
			else {
				isOn = false;
			}
		}
		else if (input == "2") {
			if (createEdge()) {
				std::cout << "The Edge was successfully added.\n";
			}
			else {
				isOn = false;
			}
		}
		else if (input == "3") {
			std::cout << getVertexsList();
		}
		else if (input == "4") {
			std::cout << getEdgesList();
		}
		else {
			std::cout << "ERROR: Unknown action!\n";
		}
	}
}

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
		for (int i = 0; i < Vertexs.size();i++) {
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
		for (int i = 0; i < Vertexs.size();i++) {
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
		} catch (const std::exception& error) {
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