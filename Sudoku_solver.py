from z3 import Int, Solver, sat, Distinct

def read_sudoku():
    puzzle = []
    for i in range(9):
        row = input()
        row_values = [int(num) for num in row.split() if num.isdigit()]
        puzzle.append(row_values)
    return puzzle

sudoku_puzzle = read_sudoku()

solver = Solver()

cells = [[Int(f'x{i}_{j}') for j in range(9)] for i in range(9)]

for i in range(9):
    for j in range(9):
        solver.add(cells[i][j] >= 1, cells[i][j] <= 9)

        if sudoku_puzzle[i][j] != 0:
            solver.add(cells[i][j] == sudoku_puzzle[i][j])

for i in range(9):
    solver.add(Distinct(cells[i]))  
    solver.add(Distinct([cells[j][i] for j in range(9)]))

for i in range(0, 9, 3):
    for j in range(0, 9, 3):
        solver.add(Distinct([cells[i + x][j + y] for x in range(3) for y in range(3)]))

if solver.check() == sat:
    model = solver.model()
    for i in range(9):
        for j in range(9):
            print(f"{model[cells[i][j]]} ", end="")
        print()
else:
    print("No solution found.")
