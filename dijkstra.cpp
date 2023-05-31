#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

unordered_map<char, unordered_map<char, int>> createGraph() {
    unordered_map<char, unordered_map<char, int>> graph;
    graph['A'] = {{'B', 5}, {'C', 3}};
    graph['B'] = {{'A', 5}, {'D', 2}};
    graph['C'] = {{'A', 3}, {'D', 6}};
    graph['D'] = {{'B', 2}, {'C', 6}, {'E', 8}};
    graph['E'] = {{'D', 8}};
    return graph;
}

unordered_map<char, int> dijkstra(unordered_map<char, unordered_map<char, int>>& graph, char start) {
    unordered_map<char, int> distances;
    for (const auto& pair : graph) {
        distances[pair.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        char current_node = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_node]) {
            continue;
        }

        for (const auto& neighbor : graph[current_node]) {
            char adjacent_node = neighbor.first;
            int weight = neighbor.second;
            int distance = current_distance + weight;

            if (distance < distances[adjacent_node]) {
                distances[adjacent_node] = distance;
                pq.push({distance, adjacent_node});
            }
        }
    }

    return distances;
}

int main() {
    unordered_map<char, unordered_map<char, int>> graph = createGraph();
    char start_node = 'A';
    unordered_map<char, int> distances = dijkstra(graph, start_node);

    for (const auto& pair : distances) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
