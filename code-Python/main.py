from sudoku import Sudoku

def main():
    input_str = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    
    sudoku = Sudoku(input_str)

    if sudoku.get_inference():
        sudoku.print()

if __name__ == "__main__":
    main()