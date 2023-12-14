// Example function to validate a form input
function validateInput(input) {
	if (input.value.length < 3) {
		input.classList.add("error");
		input.setCustomValidity("Please enter at least 3 characters.");
	} else {
		input.classList.remove("error");
		input.setCustomValidity("");
	}
}