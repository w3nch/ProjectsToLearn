const dark = document.getElementById('dark');
const body = document.querySelector('body');
let isDarkMode = false;

dark.addEventListener('click', function() {
    isDarkMode = !isDarkMode;
    const iconClass = isDarkMode ? 'bi-moon' : 'bi-brightness-high-fill';
    const bgColor = isDarkMode ? 'black' : 'white';
    const textColor = isDarkMode ? 'white' : 'black';
    const buttonText = isDarkMode ? ' Light' : ' Dark';

    this.classList.toggle('bi-moon', isDarkMode);
    this.classList.toggle('bi-brightness-high-fill', !isDarkMode);
    body.style.background = bgColor;
    body.style.color = textColor;
    body.style.transition = '2s';
    this.textContent = buttonText;

    localStorage.setItem('darkMode', isDarkMode.toString());
});

const storedMode = localStorage.getItem('darkMode');
if (storedMode === 'true') {
    dark.click();
}
