
class Cell {

	constructor(readonly element: HTMLElement) { }

	set position(pos: number) {

		this.element.style.zIndex = '50';
		this.element.className = "p" + pos;
		this.element.style.borderColor = 'black'
		setTimeout(() => {
			this.element.style.zIndex = '';
			this.element.style.borderColor = '';
		}, 500);

	}

	get position(): number {
		return 1;// later
	}

	get value(): number {
		return Number(this.element.innerHTML);
	}
}