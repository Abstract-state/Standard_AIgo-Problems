# Define the initial and goal states
initial_state = (3, 3, 1)  # (missionaries on the left, cannibals on the left, boat position)
goal_state = (0, 0, 0)  # (missionaries on the left, cannibals on the left, boat position)

# Define the valid moves from a given state
def get_valid_moves(state):
    moves = []
    missionaries_left, cannibals_left, boat = state

    # Determine the current shore and the opposite shore
    if boat == 1:
        current_shore = 'left'
        opposite_shore = 'right'
        missionaries_on_current_shore = missionaries_left
        cannibals_on_current_shore = cannibals_left
    else:
        current_shore = 'right'
        opposite_shore = 'left'
        missionaries_on_current_shore = 3 - missionaries_left
        cannibals_on_current_shore = 3 - cannibals_left

    # Generate all possible moves from the current state
    for m in range(min(2, missionaries_on_current_shore) + 1):
        for c in range(min(2, cannibals_on_current_shore) + 1):
            if 1 <= m + c <= 2:  # At most 2 people in the boat
                new_missionaries_left = missionaries_left + (-1 if boat == 1 else 1) * m
                new_cannibals_left = cannibals_left + (-1 if boat == 1 else 1) * c
                new_missionaries_right = 3 - new_missionaries_left
                new_cannibals_right = 3 - new_cannibals_left
                if (new_missionaries_left == 0 or new_missionaries_left >= new_cannibals_left) and \
                        (new_missionaries_right == 0 or new_missionaries_right >= new_cannibals_right) and \
                        new_missionaries_left >= 0 and new_cannibals_left >= 0 and new_missionaries_right >= 0 and new_cannibals_right >= 0:
                    # Valid move only if the number of missionaries is 0 or greater than or equal to cannibals and non-negative
                    new_state = (
                        new_missionaries_left,
                        new_cannibals_left,
                        1 - boat
                    )  # Update the state based on the move
                    moves.append((new_state, (m, c)))
    return moves

# Perform breadth-first search to find a solution
def solve(initial_state):
    frontier = [[initial_state]]
    explored = set()

    print("Queue Status:")
    print("-------------")
    print("Frontier: ", frontier)
    print("Explored: ", explored)
    print()

    while frontier:
        path = frontier.pop(0)
        state = path[-1]

        if state == goal_state:
            return path

        for next_state, move in get_valid_moves(state):
            if next_state not in explored:
                explored.add(next_state)
                new_path = list(path)
                new_path.append(next_state)
                frontier.append(new_path)

        print("Queue Status:")
        print("-------------")
        print("Frontier: ", frontier)
        print("Explored: ", explored)
        print()

    return None

# Solve the problem and print the solution
path = solve(initial_state)
if path is None:
    print("No solution found.")
else:
    print("Solution:")
    for i, state in enumerate(path):
        if i > 0:
            missionaries, cannibals, _ = path[i - 1]
            if state[2] == 1:
                boat_position = 'left'
            else:
                boat_position = 'right'
            print(f"{missionaries} missionaries and {cannibals} cannibals move from {boat_position} to {'left' if boat_position == 'right' else 'right'} shore.")
            print("Current state:")
            print(f"Left shore: {state[0]} missionaries, {state[1]} cannibals")
            print(f"Right shore: {3 - state[0]} missionaries, {3 - state[1]} cannibals")
            print()

    print("Goal state reached!")
