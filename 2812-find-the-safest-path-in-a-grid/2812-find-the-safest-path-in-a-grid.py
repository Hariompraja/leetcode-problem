class Solution(object):
    def maximumSafenessFactor(self, grid):
     

        n = len(grid)

        dist = [[-1] * n for _ in range(n)]
        q = deque()

        # Multi-source BFS
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    dist[i][j] = 0
                    q.append((i, j))

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while q:
            r, c = q.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and dist[nr][nc] == -1:
                    dist[nr][nc] = dist[r][c] + 1
                    q.append((nr, nc))

        
        pq = [(-dist[0][0], 0, 0)]
        visited = [[False] * n for _ in range(n)]

        while pq:
            safe, r, c = heapq.heappop(pq)
            safe = -safe

            if visited[r][c]:
                continue
            visited[r][c] = True

            if r == n - 1 and c == n - 1:
                return safe

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                    heapq.heappush(
                        pq,
                        (-min(safe, dist[nr][nc]), nr, nc)
                    )

        return 0
        