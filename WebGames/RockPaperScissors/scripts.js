const choices = ['rock', 'paper', 'scissors'];
const resultDisplay = document.getElementById('result');
const userChoiceDisplay = document.getElementById('user-choice');
const computerChoiceDisplay = document.getElementById('computer-choice');

document.querySelectorAll('button').forEach(button => {
  button.addEventListener('click', (e) => {
    const userChoice = e.currentTarget.id;
    const computerChoice = choices[Math.floor(Math.random() * 3)];

    userChoiceDisplay.textContent = userChoice;
    computerChoiceDisplay.textContent = computerChoice;

    const result = getResult(userChoice, computerChoice);
    resultDisplay.textContent = result;
  });
});

function getResult(userChoice, computerChoice) {
  if (userChoice === computerChoice) {
    return "It's a draw!";
  } else if (
    (userChoice === 'rock' && computerChoice === 'scissors') ||
    (userChoice === 'paper' && computerChoice === 'rock') ||
    (userChoice === 'scissors' && computerChoice === 'paper')
  ) {
    return "You win!";
  } else {
    return "You lose!";
  }
}
