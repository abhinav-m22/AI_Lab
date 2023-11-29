from collections import deque

def is_valid(state):
    m, c, b = state
    # Check if the number of missionaries is greater than or equal to cannibals on both sides
    return (m >= c or m == 0) and ((3 - m) >= (3 - c) or (3 - m) == 0)

def is_goal(state):
    # Check if all missionaries and cannibals have crossed to the other side
    return state == (0, 0, 0)

def get_successors(state):
    successors = []
    m, c, b = state
    
    # Possible moves: (1, 0), (2, 0), (0, 1), (0, 2), (1, 1)
    for dm in range(3):
        for dc in range(3):
            if 1 <= dm + dc <= 2:
                new_state = (m - (-1) ** b * dm, c - (-1) ** b * dc, 1 - b)
                if is_valid(new_state):
                    successors.append(new_state)
    return successors

def bfs():
    start_state = (3, 3, 1)
    queue = deque([(start_state, [])])

    while queue:
        current_state, path = queue.popleft()

        if is_goal(current_state):
            return path + [current_state]

        for successor in get_successors(current_state):
            if successor not in path:
                queue.append((successor, path + [current_state]))

    return None

def print_solution(solution):
    for state in solution:
        print(state)

if __name__ == "__main__":
    solution = bfs()
    if solution:
        print_solution(solution)
    else:
        print("No solution found.")
