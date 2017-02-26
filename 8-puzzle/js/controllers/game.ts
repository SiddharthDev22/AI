
class Game {

	private cells: Cell[] = [];

	constructor(readonly element: HTMLElement) {
		this.getCells(this.element.getElementsByTagName('cell'));
	}

	/**
	 * add a list of element to img collection
	 * @param elements the list of elements from .getEelementsBy
	 */
	private getCells(elements: NodeListOf<Element>) {
		for (let i = 0; i < elements.length; i++) {
			var tempCell = new Cell(<HTMLElement>elements[i]);
			tempCell.position = tempCell.value;
			this.cells[Number(tempCell.element.innerHTML)] = tempCell;
		}
	}

}