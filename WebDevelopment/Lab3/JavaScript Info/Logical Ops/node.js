alert( null || 2 || undefined ); // 2

alert( alert(1) || 2 || alert(3) ); // 1 2 alert returns underfined

alert( 1 && null && 2 ); //null

alert( alert(1) && alert(2) ); // 1 underfined

alert( null || 2 && 3 || 4 ); // 3

/****************/

let age = prompt("Age: ", "");

(14<=age && age<=90) ? alert("Between") : alert("Not");

/*****************/

!(14<=age && age<=90) ? alert("Not") : alert("Between");

!(14>age && age>90) ? alert("Not") : alert("Between");

/*****************/


if (-1 || 0) alert( 'first' ); // -1

if (-1 && 0) alert( 'second' ); // False

if (null || -1 && 1) alert( 'third' ); // 1

/*****************/

let user = prompt("Who is there?","");

if(user=="Admin"){
    let pass = prompt("Password?", "");
    (pass=="TheMaster") ? alert("Welcome") : (pass=="Cancel") ? alert("Canceled") : alert("Wrong password");
}else if("Cancel"){
    alert("Canceled");
}else{
    alert("Idk");
}