function getRequest(url) {
    const http = new XMLHttpRequest();
    http.onreadystatechange = (e) => {
        console.log(http.responseText);
    }
    http.open("GET", url);
    http.send();
}

$('#openFileUpload').click(function(){ $('#fileupload').trigger('click'); });

function homeAxes() {
    console.log('Homing axes!');
    getRequest('homeAxes');
}

function homeRoller() {
    console.log('Homing roller!');
    getRequest('homeRoller');
}

function printSVG() {
    console.log('Print SVG!');
    getRequest('printSVG');
}

function printPattern() {
    console.log('Printing pattern!');
    getRequest('printPattern')
}

function abortMotion() {
    console.log('Aborting motion!');
    getRequest('abortMotion');
}
