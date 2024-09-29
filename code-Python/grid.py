# grid.py

class Grid:
    BOX_SIZE = 3
    GRID_SIZE = 9

    def __init__(self, input=''):
        self.grid = [[int(input[i * self.GRID_SIZE + j]) for j in range(self.GRID_SIZE)] for i in range(self.GRID_SIZE)]

    def get_row(self, row):
        return self.grid[row]

    def get_column(self, col):
        return [self.grid[i][col] for i in range(self.GRID_SIZE)]

    def get_box(self, row, col):
        start_row = (row // self.BOX_SIZE) * self.BOX_SIZE
        start_col = (col // self.BOX_SIZE) * self.BOX_SIZE
        box = []
        for i in range(start_row, start_row + self.BOX_SIZE):
            for j in range(start_col, start_col + self.BOX_SIZE):
                box.append(self.grid[i][j])
        return box

    def set_num(self, row, col, num):
        self.grid[row][col] = num

    def get_num(self, row, col):
        return self.grid[row][col]

    def get_inference(self):
        return self.backtracking(self.grid)

    def backtracking(self, grid):
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0:
                    continue
                for k in range(1, 10):
                    if self.is_valid(i, j, k, grid):
                        grid[i][j] = k
                        if self.backtracking(grid):
                            return True
                        grid[i][j] = 0
                return False
        return True

    def is_valid(self, row, col, val, grid):
        for i in range(9):
            if grid[row][i] == val or grid[i][col] == val:
                return False
        start_row = (row // 3) * 3
        start_col = (col // 3) * 3
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if grid[i][j] == val:
                    return False
        return True


# sudoku.py

# from grid import Grid

class Sudoku(Grid):
    def __init__(self, input=''):
        self.grid = Grid(input)

    def get_inference(self):
        return self.grid.get_inference()

    def print(self):
        self.print()


# main.py

# from sudoku import Sudoku

def main():
    input_str = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    
    sudoku = Sudoku(input_str)

    if sudoku.get_inference():
        sudoku.print()

if __name__ == "__main__":
    main()