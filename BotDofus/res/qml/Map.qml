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
    property variant listEntitiesAlreadyExist: []
    property variant listInteractiveAlreadyExist: []

    signal mouseMove(int x, int y);
    signal mouseDown(int x, int y, int buttons);
    signal mouseUp(int x, int y);
    signal mouseOut();

    Connections {
        target: mapForm
        function onCollisionTypesChanged() { canvas.requestPaint() }
    }

    clip:true
    scale: 1/ratio

    width: width * ratio
    height: height * ratio
    anchors.centerIn: parent

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

        if (mapForm.collisionTypes.length !== 0) {
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
                if (mapForm.cellChangeColor === cellId) {
                    if (mapForm.cellClicked)
                        drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xBBBBBB, 0xBBBBBB);
                    else
                        drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xFFFFFF, 0xBBBBBB);
                }
                else
                    drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xFFFFFF, 0xBBBBBB);

                // Obstacle
                if (mapForm.collisionTypes[cellId] === MapForm.COLLISION_WITH_SIGHT)
                    drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0xBBBBBB);

                // Ligne de vue
                if (mapForm.collisionTypes[cellId] === MapForm.COLLISION_NO_SIGHT)
                    drawTile(ctx, cellPos[cellId].pixelX, cellPos[cellId].pixelY, 0x777777);
            }
        }
    }

    function drawTile(target, x, y, color, borderColor) {
        target.save();

        if (color !== undefined)
            target.fillStyle= "#" + color.toString(16);

        if (borderColor !== undefined)
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

        if (color !== undefined)
            target.fill();

        if (borderColor !== undefined)
            target.stroke();

        target.restore();
    }

    function addEntity(actorId, cellId, paths, duration, type) {
        // Define color for entity
        var color;
        if (type === MapForm.PLAYER || type === MapForm.BOT) {
            color = '#8076d0';
        } else if (type === MapForm.MONSTER) {
            color = '#ee6276';
        } else if (type === MapForm.NPC) {
            color = '#8a8a8a';
        } else if (type === MapForm.MERCHANT) {
            color = '#d09e9e';
        }

        // Define animation for entity
        var animation = '';
        if (paths && paths.length > 1) {
            animation += 'PathAnimation{running:true;duration:'+duration+';loops:1;target:entity;orientation:PathAnimation.TopFirst;anchorPoint:Qt.point(entity.width/2,entity.height/2);path:Path{id:path0;startX:'+paths[0].x+';startY:'+paths[0].y+';';
            for (var i in paths) {
                animation += 'PathLine{id:path'+i+1+';x:'+paths[i].x+';y:'+paths[i].y+';}';
            }
            animation += '}}';
        }

        var found = false;
        for(var index in listEntitiesAlreadyExist) {
            if (listEntitiesAlreadyExist[index].id === actorId) {
                var equal = false;
                if (listEntitiesAlreadyExist[index].path.length === paths.length)
                {
                    for (var i = 0; i < paths.length; ++i) {
                        if (listEntitiesAlreadyExist[index].path[i] !== paths[i]) {
                            equal = false;
                            break;
                        }
                    }
                    equal = true;
                }

                if (!equal) {
                    listEntitiesAlreadyExist[index].qmlObject.destroy();
                    listEntitiesAlreadyExist[index] = { id: actorId, cellId: cellId, qmlObject: Qt.createQmlObject('import QtQuick 2.0;Item{Rectangle{id:entity;color:"'+color+'";x:'+paths[0].x+';y:'+paths[0].y+';width:15;height:15;radius:10;}'+animation+'}',
                                                                                                   canvas,
                                                                                                   "dynamicSnippet1") };
                }
                found = true;
            }
        }

        if (!found) {
            listEntitiesAlreadyExist[listEntitiesAlreadyExist.length] = { id: actorId, cellId: cellId, qmlObject: Qt.createQmlObject('import QtQuick 2.0;Item{Rectangle{id:entity;color:"'+color+'";x:'+paths[0].x+';y:'+paths[0].y+';width:15;height:15;radius:10;}'+animation+'}',
                                                                                                                     canvas,
                                                                                                                     "dynamicSnippet1") };
        }
    }

    function removeEntity(cellId) {
        for(var i in listEntitiesAlreadyExist) {
            if (listEntitiesAlreadyExist[i].cellId === cellId) {
                listEntitiesAlreadyExist[i].qmlObject.destroy();
                listEntitiesAlreadyExist.splice(i, 1);
            }
        }
    }

    function addInteractive(interactiveId, position, type) {
        // Define color for entity
        var color;
        if (type === MapForm.INTERACTIVE) {
            color = '#94a8c6';
        } else if (type === MapForm.DOOR) {
            color = '#80eeee';
        } else if (type === MapForm.USABLE) {
            color = '#e8bc75';
        }

        var found = false;
        for(var i in listInteractiveAlreadyExist) {
            if (listInteractiveAlreadyExist[i].id === interactiveId) {
                listInteractiveAlreadyExist[i].qmlObject.destroy();
                listInteractiveAlreadyExist[i] = { id: interactiveId, qmlObject: Qt.createQmlObject('import QtQuick 2.0;Item{Rectangle{id:interactive;color:"'+color+'";x:'+position.x+';y:'+position.y+';width:15;height:15;}}',
                                                                                                    canvas,
                                                                                                    "dynamicSnippet1") };
                found = true;
            }
        }

        if (!found) {
            listInteractiveAlreadyExist[listInteractiveAlreadyExist.length] = { id: interactiveId, qmlObject: Qt.createQmlObject('import QtQuick 2.0;Item{Rectangle{id:interactive;color:"'+color+'";x:'+position.x+';y:'+position.y+';width:15;height:15;}}',
                                                                                                                                 canvas,
                                                                                                                                 "dynamicSnippet1") };
        }
    }

    function removeInteractive(interactiveId) {
        for(var i in listInteractiveAlreadyExist) {
            if (listInteractiveAlreadyExist[i].id === interactiveId) {
                listInteractiveAlreadyExist[i].qmlObject.destroy();
                listInteractiveAlreadyExist.splice(i, 1);
            }
        }
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

            if (Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2) {
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

            if (Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2) {
                mapForm.cellClicked = false;
                mapForm.cellChangeColor=i;

                if (mapForm.interactiveTypes[i] === MapForm.DOOR)
                    mapForm.useDoorInteractive(i);

                else if (mapForm.interactiveTypes[i] === MapForm.USABLE)
                    mapForm.useInteractive(i);

                else if (mapForm.collisionTypes[i] === MapForm.COLLISION_WITH_SIGHT || mapForm.collisionTypes[i] === MapForm.COLLISION_NO_SIGHT)
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

            if (Math.sqrt(Math.pow(x - 0 - cellPosX,2) + Math.pow(y - 12 - cellPosY,2)) < tileHeight / 2) {
                mapForm.showInfos(i);
                return;
            }
        }
    }

    onMouseOut: {
        mapForm.cellClicked = false;
    }
}
