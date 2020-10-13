import QtQuick 2.0
import QtQuick.Window 2.0
import MapViewerCellEnum 1.0

Canvas {
    id: canvas

    property int ratio: Screen.devicePixelRatio

    property color background : "#434343"

    property color  gridColor: '#807A5B'

    property color cellNoCollisionColor: "#958D69"
    property color cellNoCollisionColor_: "#756D49"
    property color cellNoCollisionAlternativeColor: "#8B8561"
    property color cellNoCollisionAlternativeColor_: "#736D49"

    property color collisionBlockColor: "#58533A"

    property color cellInteractiveColor: "#94a8c6"
    property color cellUsableColor: "green"

    property color innerBotColor: "violet"
    property color aroundBotColor: "black"

    property color innerPlayerBotColor: "yellow"
    property color aroundPlayerBotColor: "black"

    property color innerPlayerColor: "#8076d0"
    property color aroundPlayerColor: "black"

    property color innerMonsterColor: "#ee6276"
    property color aroundMonsterColor: "black"

    property color innerNpcColor: "#8a8a8a"
    property color aroundNpcColor: "black"

    property int tileWidth: 0
    property int tileHeight: 0
    property variant cellPos: []

    signal mouseMove(int x, int y);
    signal mouseDown(int x, int y, int buttons);
    signal mouseUp(int x, int y);
    signal mouseWheel(int x, int y);
    signal mouseIn();
    signal mouseOut();

    signal keyDown(var event);
    signal keyUp(var event);

    Connections
    {
        target: mapForm
        onEntityTypesChanged: canvas.requestPaint()
        onCollisionTypesChanged: canvas.requestPaint()
        onInteractiveTypesChanged: canvas.requestPaint()
        onCellClickedChanged: canvas.requestPaint()
    }

    clip:true
    scale: 1/ratio

    width: width * ratio
    height: height * ratio
    renderStrategy: Canvas.Threaded
    antialiasing: true
    onPaint: draw();

    function draw()
    {
        initCells();

        if(mapForm.collisionTypes.length !== 0)
        {
            // Création de la région de la carte
            var ctx = canvas.getContext("2d");
            ctx.reset();
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            ctx.fillStyle = background;
            ctx.fillRect(0, 0, width, height);

            tileWidth = canvas.width/14*13.5/14;
            tileHeight = canvas.height/20*19/20;

            ctx.translate(0, tileHeight/2);

            for(var cellId in cellPos)
            {
                // Affichage de la grille
                if(mapForm.cellChangeColor == cellId)
                {
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
                if(mapForm.interactiveTypes[cellId] !== MapForm.NOTHING)
                {
                    if(mapForm.interactiveTypes[cellId] === MapForm.INTERACTIVE)
                        drawSquare(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x94a8c6);

                    else if(mapForm.interactiveTypes[cellId] === MapForm.USABLE)
                        drawSquare(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xe8bc75);
                }

//                // Chemin
//                if(mapForm.getCellIds(cellId).length >1)
//                {
//                    console.log(mapForm.getCellIds(cellId).length);
//                    for(var k=0; k < mapForm.getCellIds(cellId).length-1; k++)
//                        drawPath(ctx, mapForm.getCellIds(cellId)[k], mapForm.getCellIds(cellId)[k+1]);
//                }

                // Entitée
                if(mapForm.entityTypes[cellId] !== MapForm.NOTHING)
                {
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

    function drawTile(target, x, y, color, borderColor)
    {
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

    function drawCircle(target, x, y, color, shadow, who)
    {
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

    function drawSquare(target, x, y, color)
    {
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

    function drawText(target, x, y, cell)
    {
        target.save();

        target.beginPath();
        target.textAlign = "center";
        target.fillStyle = "black";
        target.fillText('%1'.arg(cell), x+tileWidth/2-.5, y+tileHeight/2+4);
        target.closePath();

        target.restore();
    }

    function drawPath(target, x, y, color, shadow)
    {
        var dimensionX = canvas.width/14*13.5/14;
        var dimensionY = canvas.height/20*19/20;

        target.strokeStyle= "#0xBBBBBB";
        target.setLineDash([4, 4]);

        target.beginPath();
        target.lineWidth = 1;
        target.moveTo(cellPos[start].pixelX + dimensionX / 2,cellPos[start].pixelY + dimensionY / 2);
        target.lineTo(cellPos[end].pixelX + dimensionX / 2,cellPos[end].pixelY + dimensionY / 2);
        target.closePath();
        target.stroke();
    }

    function initCells()
    {
        tileWidth = canvas.width/14*13.5/14;
        tileHeight = canvas.height/20*19/20;

        var startX = 0;
        var startY = 0;
        var cell = 0;
        var b;
        for (var a = 0; a < 20; a++)
        {
            for (b = 0; b < 14; b++)
            {
                var p = cellCoords(cell);
                cellPos[cell] = { x:startX + b, y:startY + b, pixelX: p.x * tileWidth + (p.y % 2 == 1 ? tileWidth / 2 : 0), pixelY: p.y * tileHeight / 2 };
                cell++;
            }
            startX++;

            for (b = 0; b < 14; b++)
            {
                p = cellCoords(cell);
                cellPos[cell] = { x:startX + b, y:startY + b, pixelX: p.x * tileWidth + (p.y % 2 == 1 ? tileWidth / 2 : 0), pixelY: p.y * tileHeight / 2 };
                cell++;
            }
            startY--;
        }
    }

    function cellCoords(cellId )
    {
        return { x:cellId % 14,	 y:Math.floor(cellId / 14) }
    }

    //    function anim(time, start, end)
    //    {
    //        if (!startTime) // it's the first frame
    //            startTime = time || performance.now();

    //        // deltaTime should be in the range [0 ~ 1]
    //        var deltaTime = (time - startTime) / 1000;
    //        // currentPos = previous position + (difference * deltaTime)
    //        var currentX = x + ((nextX - x) * deltaTime);
    //        var currentY = y + ((nextY - y) * deltaTime);

    //        if (deltaTime >= 1) // this means we ended our animation
    //        {
    //            x = nextX; // reset x variable
    //            y = nextY; // reset y variable
    //            startTime = null; // reset startTime
    //            drawCircle(x, y); // draw the last frame, at required position
    //        }
    //        else
    //        {
    //            drawCircle(currentX, currentY);
    //            requestAnimationFrame(anim); // do it again
    //        }
    //    }

    function addEventListener(event, handler, ignored)
    {
        if (event === 'mousemove')
            canvas.mouseMove.connect(handler);

        else if (event === 'mousedown')
            canvas.mouseDown.connect(handler);

        else if (event === 'mouseup')
            canvas.mouseUp.connect(handler);

        else if (event === 'mouseout')
            canvas.mouseOut.connect(handler);
    }

    function removeEventListener(event, handler, ignored)
    {
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

        for(var i in mapForm.entityTypes)
        {
            var data = mapForm.entityTypes[i];
            var cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
            var cellPosY = cellPos[i].pixelY + tileHeight / 2;
            if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2)
            {
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

        for(var i in cellPos)
        {
            cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
            cellPosY = cellPos[i].pixelY + tileHeight / 2;

            if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2)
            {
                mapForm.cellClicked = false;
                mapForm.cellChangeColor=i;

                if(mapForm.collisionTypes[i] === MapForm.COLLISION_WITH_SIGHT || mapForm.collisionTypes[i] === MapForm.COLLISION_NO_SIGHT)
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

        for(var i in mapForm.interactiveTypes)
        {
            var data = mapForm.interactiveTypes[i];
            if(data !== 0)
            {
                var cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
                var cellPosY = cellPos[i].pixelY + tileHeight / 2;
                if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 3.5)
                {
                    mapForm.showInfos(i);
                    return;
                }

                else
                    mapForm.hideInfos();
            }
        }

        for(var i in mapForm.entityTypes)
        {
            var data = mapForm.entityTypes[i];
            if(data !== 0)
            {
                var cellPosX = cellPos[i].pixelX + tileWidth / 2 ;
                var cellPosY = cellPos[i].pixelY + tileHeight / 2;
                if(Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 3.5)
                {
                    mapForm.showInfos(i);
                    return;
                }

                else
                    mapForm.hideInfos();
            }
        }
    }

    onMouseOut: {
        mapForm.cellClicked = false;
    }
}
