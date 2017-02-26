function main() {
	
	let elementContainer = document.getElementsByTagName('game');

	for (let i = 0; i < elementContainer.length; i++) {
		var temp = new Game(<HTMLElement>elementContainer[i]);
	}
}

window.addEventListener('load', main);