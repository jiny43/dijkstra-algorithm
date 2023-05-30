import heapq

def dijkstra(graph, start):
    # 시작 노드에서부터의 최단 거리를 저장하는 딕셔너리
    distances = {node: float('inf') for node in graph}
    distances[start] = 0  # 시작 노드의 최단 거리는 0
    queue = [(0, start)]  # 우선순위 큐를 사용하여 처리할 노드들을 저장

    while queue:
        current_distance, current_node = heapq.heappop(queue)  # 최단 거리가 가장 작은 노드 선택

        # 이미 처리된 노드라면 건너뜀
        if current_distance > distances[current_node]:
            continue

        # 현재 노드와 연결된 인접한 노드들을 순회
        for adjacent_node, weight in graph[current_node].items():
            distance = current_distance + weight  # 현재 노드를 거쳐 가는 경로의 거리

            # 더 짧은 경로를 찾았을 때 업데이트
            if distance < distances[adjacent_node]:
                distances[adjacent_node] = distance
                heapq.heappush(queue, (distance, adjacent_node))

    return distances

# 그래프 생성 (인접 리스트로 표현)
graph = {
    'A': {'B': 5, 'C': 3},
    'B': {'A': 5, 'D': 2},
    'C': {'A': 3, 'D': 6},
    'D': {'B': 2, 'C': 6, 'E': 8},
    'E': {'D': 8}
}

start_node = 'A'
distances = dijkstra(graph, start_node)

print(distances)