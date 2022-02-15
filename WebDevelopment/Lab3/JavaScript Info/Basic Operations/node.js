/*let a = 1, b = 1;

let c = ++a; // ?
let d = b++; // ?

// a = 2, b = 2, c = 2, d = 1

let a = 2;

let x = 1 + (a *= 2);

// a = 4, x = 5

x = "" + 1 + 0; // "10"
x = "" - 1 + 0 //  -1
x = true + false // 1
x = 6 / "3" // 2
x = "2" * "3" //6
x = 4 + 5 + "px" //9px
x = "$" + 4 + 5 //$45
x = "4" - 2 // 2
x = "4px" - 2 //NaN
x = "  -9  " + 5 // " -9 5 "
x = "  -9  " - 5 //-14
x = null + 1 // 1
x = undefined + 1 // NaN
x = " \t \n" - 2 // 0-2 = -2
*/

let a = prompt("First number?", 1);
let b = prompt("Second number?", 2);

alert(+a + +b); // 12
alert(Number(a) + Number(b)); // 12