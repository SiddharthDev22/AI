class Solver {

	public solution: Board;
	private steps: Board[];

	/**
	 * find a solution to the initial board
	 * @param {Board} initial 
	 */
	public constructor(public initial: Board) {
		//<< ====== EMPTY
	}

	/**
	 * @return {boolean} is the initial board solvable?
	 */
	public get isSolvable(): boolean {
		return true; //<< ====== EMPTY
	}

	/**
	 * return min number of moves to solve initial board; -1 if no solution
	 * @readonly
	 * @type {number}
	 */
	public get moves(): number {
		return this.solutionSteps.length;
	}

	/**
	 * return an array of board positions in solution
	 * @readonly
	 * @type {Board[]}
	 */
	public get solutionSteps(): Board[] {
		if (this.steps && this.steps.length > 0) {
			return this.steps;
		}
		var current = this.solution;
		this.steps = [];

		while (this.solution) {
			this.steps.push(current);
			current = current.parent ? current.parent : null;
		}

		return this.steps;
	}
}