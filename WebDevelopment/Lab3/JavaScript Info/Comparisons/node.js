"use strict"

let x = 5 > 4 // True
x = "apple" > "pineapple" // False
x = "2" > "12" // True
x = undefined == null // True
x = undefined === null // False
x = null == "\n0\n" // False
x = null === +"\n0\n" // False

/***********************************/

if("0"){
    alert("Hello");
}

// Hello!

let y = prompt("What is the “official” name of JavaScript?", "");

(y=="ECMAScript") ? alert("Right!") : alert("You don’t know? ECMAScript!");

/***************************************/

y = prompt("Number: ", "");

(y>0) ? alert(1) : (y<0) ? alert(-1) : alert(0);

/****************************************/

let res;

(a + b < 4) ? res = "Below" : res = "Over";

res = (a + b < 4) ? "Below" : "Over";

/******************************************/

let message = (login == 'Employee') ? "Hello" : (login == 'Director') ? "Greeting" : (login == '') ? 'No login' : '';


