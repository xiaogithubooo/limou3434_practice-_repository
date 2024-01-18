#include "graph.hpp"
using namespace limou;

int main()
{
	std::vector<char> vec1 = { '0', '1', '2', '3', '4', '5', '6', '7' };
	AMGraph<char, int, INT_MAX, false> g1(vec1, 8);
	g1.AddEdge('0', '1');
	g1.AddEdge('0', '2');
	g1.AddEdge('1', '3');
	g1.AddEdge('1', '4');
	g1.AddEdge('3', '7');
	g1.AddEdge('4', '7');
	g1.AddEdge('2', '5');
	g1.AddEdge('2', '6');
	g1.AddEdge('5', '6');

	std::vector<char> vec2 = { '0', '1', '2', '3', '4' };
	AMGraph<char, int, INT_MAX, true> g2(vec2, 5);
	g2.AddEdge('0', '1');
	g2.AddEdge('0', '4');
	g2.AddEdge('4', '1');
	g2.AddEdge('2', '4');
	g2.AddEdge('3', '2');
	g2.AddEdge('1', '3');

	std::vector<char> vec3 = { '0', '1', '2', '3', '4', '5' };
	AMGraph<char, int, INT_MAX, true> g3(vec3, 6);
	g3.AddEdge('0', '1', 4);
	g3.AddEdge('0', '3', 5);
	g3.AddEdge('2', '0', 2);
	g3.AddEdge('1', '2', 1);
	g3.AddEdge('2', '3', 8);
	g3.AddEdge('1', '4', 2);
	g3.AddEdge('4', '2', 3);
	g3.AddEdge('2', '5', 4);
	g3.AddEdge('5', '3', 1);
	g3.AddEdge('4', '5', 9);

	//�ڽӾ�����
	std::cout << "g1���ڽӾ���:\n";
	g1.Print();
	std::cout << "g2���ڽӾ���:\n";
	g2.Print();
	std::cout << "g3���ڽӾ���:\n";
	g3.Print();

	//BFS��DFS���
	std::cout << "g1��BFS���:\n";
	g1.BFS('0');
	g1.DFS('0');

	std::cout << "g2��BFS���:\n";
	g2.BFS('0');
	g2.DFS('0');

	std::cout << "g3��BFS���:\n";
	g3.BFS('0');
	g3.DFS('0');

	return 0;
}