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

function openSettings() {
    console.log('Opening settings!');
}

function printerInfo() {
    console.log('Opening printer info!');
}

function abortMotion() {
    console.log('Aborting motion!');
    getRequest('abortMotion');
}
