function checkAge(age) {
    return (age > 18) ? true : confirm('Did parents allow you?');
}

function checkAge(age) {
    return (age > 18) || confirm('Did parents allow you?');
}

// *****************

function min(a, b) {
    return (a>b) ? b : a;
}

//***************

function pow(a, p) {
    let x = 1;
    while(p){
        x *= a;
        p--;
    }
    return x;
}
//*****************

let ask = (question, yes, no) => (confirm(question)) ? yes() : no();

ask(
    "Do you agree?", () => alert("You agreed."), () => alert("You canceled the execution.")
);