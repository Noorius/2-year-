function unique(arr) {
    return Array.from(new Set(arr));
}

//*************

function aclean(arr) {
    let obj = {};

    for (let i = 0; i < arr.length; i++) {
        let sorted = arr[i].toLowerCase().split("").sort().join("");
        obj[sorted] = arr[i];
    }

    return Object.values(obj);
}

let arr = ["nap", "teachers", "cheaters", "PAN", "ear", "era", "hectares"];

alert( aclean(arr) );

//**********

let map = new Map();

map.set("name", "John");

let keys = Array.from(map.keys());

keys.push("more");

alert(keys); // name, more

//**************

let messages = [
    {text: "Hello", from: "John"},
    {text: "How goes?", from: "John"},
    {text: "See you soon", from: "Alice"}
];

let readMessages = new WeakSet();


readMessages.add(messages[0]);
readMessages.add(messages[1]);



readMessages.add(messages[0]);



alert("Read message 0: " + readMessages.has(messages[0])); // true

messages.shift();

//**************

let messages = [
    {text: "Hello", from: "John"},
    {text: "How goes?", from: "John"},
    {text: "See you soon", from: "Alice"}
];

let readMap = new WeakMap();

readMap.set(messages[0], new Date(2017, 1, 1));

//************

