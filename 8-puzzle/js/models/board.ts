class Board {

	// the 2D array representing a table
	table: number[][];
	// the parent board
	parent: Board = null
	// how many previous steps have been taken
	boardNumber: number = 0;
	// empty spot location
	emptyPosition: Position;

	static readonly goalBoard: number[][] = [
		[1, 2, 3],
		[4, 5, 6],
		[7, 8, 0],
	];

	static readonly goalBoardCords: Position[] = <Position[]>[
		{ row: 2, col: 2 },

		{ row: 0, col: 0 }, { row: 0, col: 1 }, { row: 0, col: 2 },
		{ row: 1, col: 0 }, { row: 1, col: 1 }, { row: 1, col: 2 },
		{ row: 2, col: 0 }, { row: 2, col: 1 },
	];


	static getFinalBoardVal(row: number, col: number) {
		return (row == 2 && col == 2) ? 0 : (row + 1) * (col + 1);
	}

	static getFinalBoardCods(val: number) {
		return (val == 0) ? { row: 2, col: 2 } : { row: Math.floor(val / 3), col: Math.floor(val % 3) };
	}

	/**
	 * @returns {boolean} true when reatched the final board
	 */
	public isFinalBoard(): boolean {
		for (var row in this.table) {
			for (var col in this.table[row]) {
				if (this.table[row][col] != Board.goalBoard[row][col]) {
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * @returns {number} number of blocks out of place
	 */
	public hamming(): number {
		var result = 0;
		for (var row in this.table) {
			for (var col in this.table[row]) {
				if (this.table[row][col] != Board.goalBoard[row][col]) {
					result++;
				}
			}
		}
		return result + this.boardNumber;
	}

	/**
	 * @returns {number} the sum of Manhattan distances between blocks and goal
	 */
	public manhattan(): number {
		var result = 0;
		for (var row in this.table) {
			for (var col in this.table[row]) {
				if (this.table[row][col] != Board.goalBoard[row][col]) {

					// the value destination
					let value = this.table[row][col];
					result +=
						Math.abs(Number(row) - Board.goalBoardCords[value].row) +
						Math.abs(Number(col) - Board.goalBoardCords[value].col);

				}
			}
		}
		return result + this.boardNumber;
	}


	public getNeighbor(position: Position) {
		var bor = new Board();
		bor.boardNumber = this.boardNumber + 1;
		bor.emptyPosition = position;
		bor.parent = this;
		bor.table = this.table.slice(0); // clones the array
		// swaps the position
		bor.table[this.emptyPosition.row][this.emptyPosition.col] = bor.table[position.row][position.col];
		bor.table[position.row][position.col] = 0;
		return bor;
	}

	public isValidNewPosition(ps: Position): boolean {
		return ps.col >= 0 &&
			ps.col < 3 &&
			ps.row >= 0 &&
			ps.row < 3 &&
			this.parent.emptyPosition.col != ps.col &&
			this.parent.emptyPosition.row != ps.row;
	}

	/**
	 * @returns {Board[]} all neighboring board positions
	 */
	public neighbors(): Board[] {
		var boards: Board[] = [];

		var pos = <Position[]>[
			{ row: this.emptyPosition.row, col: this.emptyPosition.col - 1 }, // left  <<<
			{ row: this.emptyPosition.row, col: this.emptyPosition.col + 1 }, // right >>>
			{ row: this.emptyPosition.row - 1, col: this.emptyPosition.col }, // up    ^^^
			{ row: this.emptyPosition.row + 1, col: this.emptyPosition.col }, // down  ___
		];

		for (var key in pos) {
			if (this.isValidNewPosition(pos[key])) {
				boards.push(this.getNeighbor(pos[key]));
			}
		}

		return boards;
	}

}

interface Position {
	row: number;
	col: number;
}