function main() {

	var initial = new Board();
	initial.emptyPosition = <Position>{ row: 2, col: 2 };
	initial.table = [
		[1, 2, 3],
		[4, 5, 6],
		[7, 8, 0],
	];

	var solver = new Solver(initial);

	console.log(
		//solver.isSolvable,
		//solver.moves,
		//solver.solution,
	);



	let elementContainer = document.getElementsByTagName('game');

	for (let i in elementContainer) {
		var temp = new Game(<HTMLElement>elementContainer[0], initial);
	}
}

window.addEventListener('load', main);