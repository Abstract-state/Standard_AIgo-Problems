from collections import deque

# Define the initial and goal states
initial_state = (3, 3, 1)  # (missionaries on the left, cannibals on the left, boat position)
goal_state = (0, 0, 0)  # (missionaries on the left, cannibals on the left, boat position)

# Define the valid moves from a given state
def get_valid_moves(state):
    moves = []
    missionaries_left, cannibals_left, boat = state

    # Generate all possible moves from the current state
    for m in range(3):
        for c in range(3):
            if 1 <= m + c <= 2:  # At most 2 people in the boat
                if m <= missionaries_left and c <= cannibals_left:
                    # Valid move only if the number of cannibals doesn't exceed the number of missionaries
                    new_state = (
                        missionaries_left - m,
                        cannibals_left - c,
                        1 - boat
                    )  # Update the state based on the move
                    moves.append((new_state, (m, c)))
    return moves

# Perform breadth-first search to find a solution
def solve():
    visited = set()
    queue = deque([(initial_state, [])])  # (state, path)
    while queue:
        state, path = queue.popleft()
        if state == goal_state:
            return path
        visited.add(state)
        for next_state, move in get_valid_moves(state):
            if next_state not in visited:
                queue.append((next_state, path + [move]))
    return None

# Solve the problem and print the solution
solution = solve()
if solution is None:
    print("No solution found.")
else:
    print("Solution:")
    for move in solution:
        missionaries, cannibals = move  # Extract the move from the tuple
        if move[1] == (0, 0):
            print(f"Return to the left shore.")
        else:
            print(f"{missionaries} missionaries and {cannibals} cannibals move to the {'left' if move[0][2] == 1 else 'right'} shore.")
