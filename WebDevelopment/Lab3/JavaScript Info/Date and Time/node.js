let d1 = new Date(2012, 1, 20, 3, 12);
alert( d1 );

//**********

function getWeekDay(date) {
    let days = ['SU', 'MO', 'TU', 'WE', 'TH', 'FR', 'SA'];

    return days[date.getDay()];
}

let date = new Date(2014, 0, 3); // 3 Jan 2014
alert( getWeekDay(date) ); // FR

//**********

let date = new Date(2012, 0, 3);  // 3 Jan 2012
alert( getLocalDay(date) );

function getLocalDay(date) {

    let day = date.getDay();

    if (day == 0) { // weekday 0 (sunday) is 7 in european
        day = 7;
    }

    return day;
}

//************

function getDateAgo(date, days) {
    let dateCopy = new Date(date);

    dateCopy.setDate(date.getDate() - days);
    return dateCopy.getDate();
}

let date = new Date(2015, 0, 2);

alert( getDateAgo(date, 1) ); // 1, (1 Jan 2015)
alert( getDateAgo(date, 2) ); // 31, (31 Dec 2014)
alert( getDateAgo(date, 365) ); // 2, (2 Jan 2014)

//**********

function getLastDayOfMonth(year, month) {
    let date = new Date(year, month + 1, 0);
    return date.getDate();
}

alert( getLastDayOfMonth(2012, 0) ); // 31
alert( getLastDayOfMonth(2012, 1) ); // 29
alert( getLastDayOfMonth(2013, 1) ); // 28

//********

function getSecondsToday() {
    let now = new Date();


    let today = new Date(now.getFullYear(), now.getMonth(), now.getDate());

    let diff = now - today;
    return Math.round(diff / 1000);
}

getSecondsToday() == 36000 // (3600 * 10);

alert( getSecondsToday() );


//********
function getSecondsToTomorrow() {
    let now = new Date();

    // tomorrow date
    let tomorrow = new Date(now.getFullYear(), now.getMonth(), now.getDate()+1);

    let diff = tomorrow - now;
    return Math.round(diff / 1000);
}

getSecondsToTomorrow() == 3600;

//**********

function formatDate(date) {
    let diff = new Date() - date;

    if (diff < 1000) {
        return 'right now';
    }

    let sec = Math.floor(diff / 1000);

    if (sec < 60) {
        return sec + ' sec. ago';
    }

    let min = Math.floor(diff / 60000);
    if (min < 60) {
        return min + ' min. ago';
    }

    let d = date;
    d = [
        '0' + d.getDate(),
        '0' + (d.getMonth() + 1),
        '' + d.getFullYear(),
        '0' + d.getHours(),
        '0' + d.getMinutes()
    ].map(component => component.slice(-2));


    return d.slice(0, 3).join('.') + ' ' + d.slice(3).join(':');
}

alert( formatDate(new Date(new Date - 1)) );

alert( formatDate(new Date(new Date - 30 * 1000)) );

alert( formatDate(new Date(new Date - 5 * 60 * 1000)) );


alert( formatDate(new Date(new Date - 86400 * 1000)) );

