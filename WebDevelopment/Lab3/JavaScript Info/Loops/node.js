/* let i = 3;

while (i) {
    alert( i-- ); // Last is 1
}

//***********

let i = 0;
while (++i < 5) alert( i );

let i = 0;
while (i++ < 5) alert( i );

// 1 2 3 4

//*****************

for (let i = 0; i < 5; i++) alert( i );

for (let i = 0; i < 5; ++i) alert( i );

// 0 1 2 3 4

//**************

for (let i = 2; i <= 10; ++i){
    if(i%2==0){
        alert(i);
    }
}

//**********
let n = 0;
while(n<3){
    alert(n);
    n++;
}
//********
while(n<100){
    n = prompt("Greater", '');
}
//***********

*/

n = prompt("n",'');

for(let i = 2; i <= n; i++){
    let prime = true;
    for(let j=2; j<=i/j; j++){
        if(i%j==0){
            prime = false;
            break;
        }
    }
    prime && alert(i);
}