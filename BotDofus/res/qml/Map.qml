import QtQuick 2.0
import QtQuick.Window 2.0
import MapViewerCellEnum 1.0

Canvas {
    id: canvas

    property int ratio: Screen.devicePixelRatio

    property color background : "#434343"

    property int tileWidth: 0
    property int tileHeight: 0
    property variant cellPos: []

    signal mouseMove(int x, int y);
    signal mouseDown(int x, int y, int buttons);
    signal mouseUp(int x, int y);
    signal mouseOut();

    Connections {
        target: mapForm
        function onEntityTypesChanged() { canvas.requestPaint() }
        function onCollisionTypesChanged() { canvas.requestPaint() }
        function onInteractiveTypesChanged() { canvas.requestPaint() }
        function onCellClickedChanged() { canvas.requestPaint() }
        function onDisplayCellIdsChanged() { canvas.requestPaint() }
    }

    clip:true
    scale: 1/ratio

    width: width * ratio
    height: height * ratio
    renderStrategy: Canvas.Threaded
    antialiasing: true
    onPaint: draw();

    function cellCoords(cellId ) {
        return { x:cellId % 14,	 y:Math.floor(cellId / 14) }
    }

    function initCells() {
        tileWidth = canvas.width/14*13.5/14;
        tileHeight = canvas.height/20*19/20;

        var startX = 0;
        var startY = 0;
        var cell = 0;
        var b;
        for (var a = 0; a < 20; a++) {
            for (b = 0; b < 14; b++) {
                var p = cellCoords(cell);
                cellPos[cell] = { x:startX + b, y:startY + b, pixelX: p.x * tileWidth + (p.y % 2 == 1 ? tileWidth / 2 : 0), pixelY: p.y * tileHeight / 2 };
                cell++;
            }
            startX++;

            for (b = 0; b < 14; b++) {
                p = cellCoords(cell);
                cellPos[cell] = { x:startX + b, y:startY + b, pixelX: p.x * tileWidth + (p.y % 2 == 1 ? tileWidth / 2 : 0), pixelY: p.y * tileHeight / 2 };
                cell++;
            }
            startY--;
        }
    }

    function draw() {
        initCells();

        if(mapForm.collisionTypes.length !== 0) {
            var ctx = canvas.getContext("2d");
            ctx.reset();
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = background;
            ctx.fillRect(0, 0, width, height);

            tileWidth = canvas.width/14*13.5/14;
            tileHeight = canvas.height/20*19/20;

            ctx.translate(0, tileHeight/2);

            for(var cellId in cellPos) {
                // Affichage de la grille
                if(mapForm.cellChangeColor == cellId) {
                    if(mapForm.cellClicked)
                        drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xBBBBBB, 0xBBBBBB);
                    else
                        drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xFFFFFF, 0xBBBBBB);
                }
                else
                    drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xFFFFFF, 0xBBBBBB);

                // Obstacle
                if(mapForm.collisionTypes[cellId] === MapForm.COLLISION_WITH_SIGHT)
                    drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xBBBBBB);

                // Ligne de vue
                if(mapForm.collisionTypes[cellId] === MapForm.COLLISION_NO_SIGHT)
                    drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x777777);

                // Interactive
                if(mapForm.interactiveTypes[cellId] !== MapForm.NOTHING) {
                    if(mapForm.interactiveTypes[cellId] === MapForm.INTERACTIVE)
                        drawSquare(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x94a8c6);

                    else if (mapForm.interactiveTypes[cellId] === MapForm.DOOR)
                        drawSquare(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x80eeee);

                    else if(mapForm.interactiveTypes[cellId] === MapForm.USABLE)
                        drawSquare(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xe8bc75);
                }

                // Entitée
                if(mapForm.entityTypes[cellId] !== MapForm.NOTHING) {
                    if(mapForm.entityTypes[cellId] === MapForm.PLAYER)
                        drawCircle(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x8076d0);

                    else if(mapForm.entityTypes[cellId] === MapForm.BOT)
                        drawCircle(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x8076d0, 0x8076d0, MapForm.BOT);

                    else if(mapForm.entityTypes[cellId] === MapForm.NPC)
                        drawCircle(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x8a8a8a);

                    else if(mapForm.entityTypes[cellId] === MapForm.MONSTER)
                        drawCircle(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xee6276);

                    else if(mapForm.entityTypes[cellId] === MapForm.MERCHANT)
                        drawCircle(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xd09e9e);
                }

                // Text
                if(mapForm.displayCellIds)
                    drawText(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, cellId);
            }
        }
    }

    function drawTile(target, x, y, color, borderColor) {
        target.save();

        if(color !== undefined)
            target.fillStyle= "#" + color.toString(16);

        if(borderColor !== undefined)
        {
            target.strokeStyle = "#" + borderColor.toString(16);
            target.lineWidth = .5;
        }

        target.beginPath();
        target.moveTo(x + tileWidth / 2,	y + 0);
        target.lineTo(x + tileWidth, 		y + tileHeight / 2);
        target.lineTo(x + tileWidth / 2,	y + tileHeight);
        target.lineTo(x + 0,			y + tileHeight / 2);
        target.lineTo(x + tileWidth / 2,	y + 0);

        if(color !== undefined)
            target.fill();

        if(borderColor !== undefined)
            target.stroke();

        target.restore();
    }

    function drawCircle(target, x, y, color, shadow, who) {
        target.save();

        if(shadow !== undefined)
        {
            target.shadowBlur=3;
            target.shadowColor="#" + shadow.toString(16);
        }

        if(color !== undefined)
            target.fillStyle= "#" + color.toString(16);

        target.beginPath();

        if(who == MapForm.BOT)
            target.arc(x + tileWidth / 2,	y + tileHeight / 2, tileHeight / 3, 0, Math.PI * 2, false);
        else
            target.arc(x + tileWidth / 2,	y + tileHeight / 2, tileHeight / 3.8, 0, Math.PI * 2, false);

        target.closePath();

        if(color !== undefined)
            target.fill();

        target.restore();
    }

    function drawSquare(target, x, y, color) {
        target.save();

        if(color !== undefined)
            target.fillStyle= "#" + color.toString(16);

        target.beginPath();
        target.fillRect (x + tileHeight * .7, y + tileHeight * .25, tileHeight * .5, tileHeight * .5);
        target.closePath();

        if(color !== undefined)
            target.fill();

        target.restore();
    }

    function drawText(target, x, y, cell) {
        target.save();

        target.beginPath();
        target.textAlign = "center";
        target.fillStyle = "black";
        target.fillText('%1'.arg(cell), x+tileWidth/2-.5, y+tileHeight/2+4);
        target.closePath();

        target.restore();
    }

    function addEventListener(event, handler, ignored) {
        if (event === 'mousemove')
            canvas.mouseMove.connect(handler);

        else if (event === 'mousedown')
            canvas.mouseDown.connect(handler);

        else if (event === 'mouseup')
            canvas.mouseUp.connect(handler);

        else if (event === 'mouseout')
            canvas.mouseOut.connect(handler);
    }

    function removeEventListener(event, handler, ignored) {
        if (event === 'mousemove')
            canvas.mouseMove.disconnect(handler);

        else if (event === 'mousedown')
            canvas.mouseDown.disconnect(handler);

        else if (event === 'mouseup')
            canvas.mouseUp.disconnect(handler);

        else if (event === 'mouseout')
            canvas.mouseOut.disconnect(handler);
    }

    MouseArea {
        id: inputArea
        anchors.fill: parent
        hoverEnabled: true

        onPositionChanged: {
            canvas.mouseMove(mouse.x, mouse.y);
        }

        onPressed: {
            canvas.mouseDown(mouse.x, mouse.y, mouse.buttons);
        }

        onReleased: {
            canvas.mouseUp(mouse.x, mouse.y);
        }

        onExited: {
            canvas.mouseOut();
        }
    }

    onMouseDown: {

        tileWidth = canvas.width/14*13.5/14;
        tileHeight = canvas.height/20*19/20;

        for(var i in mapForm.entityTypes) {
            var cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
            var cellPosY = cellPos[i].pixelY + tileHeight / 2;

            if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2) {
                mapForm.cellClicked = true;
                mapForm.cellChangeColor=i;
                return
            }
        }
    }

    onMouseUp: {

        tileWidth = canvas.width/14*13.5/14;
        tileHeight = canvas.height/20*19/20;

        var data;
        var cellPosX;
        var cellPosY;

        for(var i in cellPos) {
            cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
            cellPosY = cellPos[i].pixelY + tileHeight / 2;

            if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2) {
                mapForm.cellClicked = false;
                mapForm.cellChangeColor=i;

                if (mapForm.interactiveTypes[i] === MapForm.USABLE)
                    mapForm.useInteractive(i);

                else if(mapForm.collisionTypes[i] === MapForm.COLLISION_WITH_SIGHT || mapForm.collisionTypes[i] === MapForm.COLLISION_NO_SIGHT || mapForm.interactiveTypes[i] === MapForm.INTERACTIVE)
                    mapForm.changeToNearestCell(i);

                else
                    mapForm.changeCell(i);

                return
            }
        }
    }

    onMouseMove: {

        tileWidth = canvas.width/14*13.5/14;
        tileHeight = canvas.height/20*19/20;

        var data;
        var cellPosX;
        var cellPosY;

        for(var i in cellPos) {
            cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
            cellPosY = cellPos[i].pixelY + tileHeight / 2;

            if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2) {
                mapForm.showInfos(i);
                return;
            }
        }
    }

    onMouseOut: {
        mapForm.cellClicked = false;
    }
}
