class Solution(object):
    def findSafeWalk(self, grid, health):
       
        m, n = len(grid), len(grid[0])

        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = grid[0][0]

        pq = [(grid[0][0], 0, 0)]
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]

        while pq:
            cost, r, c = heappop(pq)

            if (r, c) == (m - 1, n - 1):
                return cost < health

            if cost > dist[r][c]:
                continue

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < m and 0 <= nc < n:
                    new_cost = cost + grid[nr][nc]

                    if new_cost < dist[nr][nc]:
                        dist[nr][nc] = new_cost
                        heappush(pq, (new_cost, nr, nc))

        return False
        