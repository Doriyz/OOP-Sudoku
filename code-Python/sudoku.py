
from grid import Grid

class Sudoku(Grid):
    def __init__(self, input=''):
        self.grid = Grid(input)

    def get_inference(self):
        return self.grid.get_inference()

    def print(self):
        self.print()

