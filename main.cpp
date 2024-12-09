#include "model.h"

int main() {
	setlocale(LC_ALL, "Russian");
	bool isOn = true;
	std::string input = "";
	Vertexs.emplace_back("A");// 0
	Vertexs.emplace_back("B");// 1
	Vertexs.emplace_back("C");// 2
	Vertexs.emplace_back("D");// 3
	Vertexs.emplace_back("E");// 4
	Vertexs.emplace_back("F");// 5
	Edges.emplace_back(7, &Vertexs[0], &Vertexs[1]);
	Edges.emplace_back(8, &Vertexs[0], &Vertexs[2]);
	Edges.emplace_back(11, &Vertexs[1], &Vertexs[2]);
	Edges.emplace_back(2, &Vertexs[1], &Vertexs[3]);
	Edges.emplace_back(6, &Vertexs[2], &Vertexs[3]);
	Edges.emplace_back(9, &Vertexs[2], &Vertexs[4]);
	Edges.emplace_back(11, &Vertexs[3], &Vertexs[4]);
	Edges.emplace_back(9, &Vertexs[3], &Vertexs[5]);
	Edges.emplace_back(10, &Vertexs[4], &Vertexs[5]);
	while (isOn) {
		std::cout << "1) Add Vertex\n2) Add the vertex of the edge\n3) Get List Vertexs\n4) Get List Edge\n5) The Algorithm Prima\n";
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
		else if (input == "5") {
			std::vector<Edge> tmp = algorithmPrima();
			//std::cout << algorithmPrima();
			for (size_t i = 0; i < tmp.size(); i++)
			{
				std::cout << tmp[i].nextPtr->name + " - " + tmp[i].previousPtr->name + ": " + std::to_string(tmp[i].weight) + "\n";
			}
			Edges = tmp;
		}
		else {
			std::cout << "ERROR: Unknown action!\n";
		}
	}
}