
/*--------------------------- INITIALIZATION ---------------------------*/


var map = [];
var mapPattern = [];
var newLine;
var currentLineY;
var currentColumnX;
var updatingLineY;
var updatingColumnX;
var mapAppend = "";
var targetFixed = false;
var targetLineY;
var targetColumnX;
var buffer = [];
var bufferCursor;

// map structure [offset, cellsAmount]
mapPattern = [[13, 2], [12, 4], [11, 6], [10, 8], [9, 10], [8, 12], [7, 14], [6, 16], [5, 18], [4, 20], [3, 22], [2, 24], [1, 26], [0, 28], [1, 28], [2, 28], [3, 28], [4, 28], [5, 28], [6, 28], [7, 26], [8, 24], [9, 22], [10, 20], [11, 18], [12, 16], [13, 14], [14, 12], [15, 10], [16, 8], [17, 6], [18, 4], [19, 2]];

// computing map width
var maxSize = mapPattern[0][0] + mapPattern[0][1];

for (var i = 1; i < mapPattern.length; i++){

    tmp = mapPattern[i][0] + mapPattern[i][1];

    if (tmp > maxSize){
        maxSize = tmp;
    }
}

// creating js map
for (var line = 0; line < mapPattern.length; line++){
    var newLine = [];

    for (var column = 0; column < mapPattern[line][0]; column++){
        newLine.push(2);
    }

    for (var column = mapPattern[line][0]; column < (mapPattern[line][0] + mapPattern[line][1]); column++){
        newLine.push(0);
    }

    for (var column = mapPattern[line][0] + mapPattern[line][1]; column < maxSize; column++){
        newLine.push(2);
    }

    map.push(newLine);
}

// injecting obstacles
for (var i = 0; i < obstacles.length; i++){

    var y = obstacles[i][0];
    var x = obstacles[i][1];
    var type = obstacles[i][2];

    map[y][x] = type;
}

// building html grid from js map
for (var line = 0; line < map.length; line++){

    newLine = "<div class='map-line'>";

    for (var column = 0; column < map[line].length; column++){

        if (map[line][column] == 0){
            var colorClass = ((line + column) % 2 == 0 ? "default bg-default-light" : "default bg-default-dark");
        }

        else if (map[line][column] == 1){
            var colorClass = "bg-wall";
        }

        else {
            var colorClass = "bg-hole";
        }

        newLine += "<div class='square-box " + colorClass + "'" + "id='cell-" + line + "-" + column + "'><img src='images/wall.png' id='wall'><div class='filter'></div><img src='images/obstacle2.png' id='obstacle'><img src='images/obstacle2shadow.png' id='obstacle-shadow'></div>";
    }

    newLine += "</div>";
    mapAppend += newLine;
}

$("#map").append(mapAppend);


/*--------------------------- FUNCTIONS ---------------------------*/


function visibility(x0, y0, x1, y1){

    x0 = parseInt(x0);
    y0 = parseInt(y0);
    x1 = parseInt(x1);
    y1 = parseInt(y1);

    var clear = true;
    var dx = Math.abs(x1 - x0);
    var dy = Math.abs(y1 - y0);
    var x = x0;
    var y = y0;
    var n = -1 + dx + dy;
    var x_inc = (x1 > x0 ? 1 : -1);
    var y_inc = (y1 > y0 ? 1 : -1);
    var error = dx - dy;
    dx *= 2;
    dy *= 2;

    for (var i = 0; i < 1; i++){

        if (error > 0)
        {
            x += x_inc;
            error -= dy;
        }

        else if (error < 0)
        {
            y += y_inc;
            error += dx;
        }

        else {
            x += x_inc;
            error -= dy;
            y += y_inc;
            error += dx;
            n--;
        }
    }

    while (n > 0 && clear){

        if (map[y][x] == 1){
            clear = false;
        }

        else {

            if (error > 0)
            {
                x += x_inc;
                error -= dy;
            }

            else if (error < 0)
            {
                y += y_inc;
                error += dx;
            }

            else {
                x += x_inc;
                error -= dy;
                y += y_inc;
                error += dx;
                n--;
            }

            n--;
        }
    }

    return clear;
}

function addShadows(){
    for (var line = 0; line < map.length; line++){
        for (var column = 0; column < map[line].length; column++){
            if (map[line][column] == 0 || map[line][column] == 1){
                if (!visibility(currentColumnX, currentLineY, column, line)){
                    $("#cell-" + line + "-" + column).addClass("bg-shadow-light");
                }
            }
        }
    }
}

function updateShadows(){
    for (var line = 0; line < map.length; line++){
        for (var column = 0; column < map[line].length; column++){
            if (map[line][column] == 0 || map[line][column] == 1){
                (visibility(targetColumnX, targetLineY, column, line) ? $("#cell-" + line + "-" + column).removeClass("bg-shadow-dark bg-shadow-light") : $("#cell-" + line + "-" + column).addClass("bg-shadow-dark"));
            }
        }
    }
}

function removeShadows(){
    for (var line = 0; line < map.length; line++){
        for (var column = 0; column < map[line].length; column++){
            if (map[line][column] == 0 || map[line][column] == 1){
                $("#cell-" + line + "-" + column).removeClass("bg-shadow-dark bg-shadow-light");
            }
        }
    }
}

function historyEvent($cell){

    if ($cell.hasClass("bg-obstacle")){

        $cell.removeClass('bg-obstacle');
        map[updatingLineY][updatingColumnX] = 0;

        removeShadows();

        if (targetFixed){
            updateShadows();
        }

        else if ($("#cell-" + currentLineY + "-" + currentColumnX).hasClass('default')){
            addShadows();
        }
    }

    else {

        $cell.removeClass('cell-hover');
        $cell.addClass('bg-obstacle');
        map[updatingLineY][updatingColumnX] = 1;

        if (targetFixed){

            if (targetLineY == updatingLineY && targetColumnX == updatingColumnX){

                $("#cell-" + targetLineY + "-" + targetColumnX).removeClass('target');
                targetFixed = false;

                removeShadows();
                addShadows();
            }

            else {
                updateShadows();
            }
        }

        else if (currentLineY == updatingLineY && currentColumnX == updatingColumnX || !$("#cell-" + currentLineY + "-" + currentColumnX).hasClass('default')){
            removeShadows();
        }

        else {
            removeShadows();
            addShadows();
        }
    }
}

/*--------------------------- EVENTS ---------------------------*/


$(function(){

    $(".square-box").hover(function(){

        idSplit = $(this).attr("id").split("-");
        currentLineY = idSplit[1];
        currentColumnX = idSplit[2];
        updatingLineY = currentLineY;
        updatingColumnX = currentColumnX;

        if (map[currentLineY][currentColumnX] == 0 && !$(this).hasClass("target")){

            $(this).addClass("cell-hover");
            (targetFixed ? updateShadows() : addShadows());
        }},

        function(){

            $(this).removeClass("cell-hover");

            if ($(this).hasClass("default") && !$(this).hasClass("bg-obstacle") && !targetFixed){
                removeShadows();
            }
        }
    );

    $(".square-box").click(function(){

        idSplit = $(this).attr("id").split("-");
        currentLineY = idSplit[1];
        currentColumnX = idSplit[2];
        updatingLineY = currentLineY;
        updatingColumnX = currentColumnX;

        if ($(this).hasClass("default") && !$(this).hasClass("target")){

            if ($(this).hasClass("bg-obstacle")){

                $(this).addClass('cell-hover');
                $(this).removeClass('bg-obstacle');
                map[updatingLineY][updatingColumnX] = 0;

                (targetFixed ? updateShadows() : addShadows());
            }

            else {

                $(this).removeClass('cell-hover');
                $(this).addClass('bg-obstacle');
                map[updatingLineY][updatingColumnX] = 1;

                (targetFixed ? updateShadows() : removeShadows());
            }


            if (bufferCursor < buffer.length - 1){
                buffer.length = bufferCursor + 1; // truncate history
            }

            bufferCursor = buffer.length;
            buffer.push([currentLineY, currentColumnX]);
        }
    });

    $(".square-box").contextmenu(function(){

        idSplit = $(this).attr("id").split("-");
        currentLineY = idSplit[1];
        currentColumnX = idSplit[2];
        updatingLineY = currentLineY;
        updatingColumnX = currentColumnX;

        if ($(this).hasClass('default') && !$(this).hasClass("bg-obstacle")){

            if (!$(this).hasClass('target')){

                if (targetFixed){
                    $("#cell-" + targetLineY + "-" + targetColumnX).removeClass('target');
                }

                $(this).removeClass("cell-hover");
                $(this).addClass('target');

                targetLineY = currentLineY;
                targetColumnX = currentColumnX;
                targetFixed = true;

                removeShadows();
                updateShadows();
            }

            else {

                $(this).removeClass('target');
                $(this).addClass("cell-hover");
                targetFixed = false;

                removeShadows();
                addShadows();
            }
        }

        return false;
    });

    $(document).keydown(function(e){

        if (e.which == 90 && e.ctrlKey){

            if (buffer.length > 0 && bufferCursor > -1){

                updatingLineY = buffer[bufferCursor][0];
                updatingColumnX = buffer[bufferCursor][1];
                bufferCursor --;

                $cell = $("#cell-" + updatingLineY + "-" + updatingColumnX);
                historyEvent($cell);
            }
        }

        else if (e.which == 89 && e.ctrlKey){

            if (buffer.length > 0 && bufferCursor < buffer.length - 1){

                bufferCursor ++;
                updatingLineY = buffer[bufferCursor][0];
                updatingColumnX = buffer[bufferCursor][1];

                $cell = $("#cell-" + updatingLineY + "-" + updatingColumnX);
                historyEvent($cell);
            }
        }
    });
});