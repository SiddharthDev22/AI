
class Game {

	private cells: Cell[] = [];

	constructor(public readonly element: HTMLElement, public readonly initial: Board) {
		this.getCells(this.element.getElementsByTagName('cell'));
		this.setPositions(this.initial);
	}

	/**
	 * add a list of element to img collection
	 * @param elements the list of elements from .getEelementsBy
	 */
	private getCells(elements: NodeListOf<Element>) {
		for (let i = 0; i < elements.length; i++) {
			var tempCell = new Cell(<HTMLElement>elements[i]);

			this.initial.table

			tempCell.position = tempCell.value;
			this.cells[Number(tempCell.element.innerHTML)] = tempCell;
		}
	}

	private setPositions(bor: Board) {
		for (var row = 0; row < bor.table.length; row++) {
			for (var col = 0; col < bor.table[row].length; col++) {

				let val = bor.table[row][col];
				let pos = (row == 2 && col == 2) ? 0 : (row ) * (col );
				console.log(row + 1, col + 1, pos, '---------------------');
				this.cells[val].position = pos;
			}
		}
	}

}