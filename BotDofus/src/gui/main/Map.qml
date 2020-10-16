import QtQuick 2.0

Item
{
    property color  gridColor: '#C6C4B5'

    property color cellNoCollisionColor: "#9EA79E"
    property color cellNoCollisionAlternativeColor: "#949B93"

    property color collisionBlockColor: "grey"

    property color cellInteractiveColor: "blue"
    property color cellUsableColor: "green"

    property color innerBotColor: "violet"
    property color aroundBotColor: "white"

    property color innerPlayerBotColor: "yellow"
    property color aroundPlayerBotColor: "white"

    property color innerPlayerColor: "blue"
    property color aroundPlayerColor: "white"

    property color innerMonsterColor: "white"
    property color aroundMonsterColor: "red"

    property color innerNpcColor: "orange"
    property color aroundNpcColor: "white"

    Connections
    {
        target: accountForm
        onEntityTypesChanged: canvas.requestPaint()
        onCollisionTypesChanged: canvas.requestPaint()
        onInteractiveTypesChanged: canvas.requestPaint()
    }

    id:canvasContainer

    anchors.left: parent.left
    anchors.top: parent.top
    anchors.rightMargin: Units.dp(25)
    width:parent.width-Units.dp(250)
    anchors.bottom: mapLabels.top

    Canvas {
        id: canvas

        //property int ratio: Screen.devicePixelRatio

        clip:true
        scale: 1/ratio

        width: parent.width * ratio
        height: parent.height * ratio
        anchors.centerIn: parent

        renderStrategy: Canvas.Threaded
        antialiasing: true
        onPaint: draw();

        function draw()
        {
            if(accountForm.collisionTypes.length !== 0)
            {
                var ctx = canvas.getContext("2d");
                ctx.reset();
                ctx.clearRect(0, 0, canvas.width, canvas.height);

                var dimensionX = canvas.width/14*13.5/14
                var dimensionY = canvas.height/20*19/20;

                ctx.translate(0, dimensionY/2);

                var index = 0;
                for(var i = 0; i < 40; i++)
                {
                    for(var j=0; j < 14; j++)
                    {
                        ctx.lineWidth = ratio
                        ctx.strokeStyle = gridColor

                        var margin = 0;

                        if(i%2 != 0)
                        {
                            ctx.fillStyle = cellNoCollisionColor;
                            margin = dimensionX/2;
                        }

                        else
                            ctx.fillStyle = cellNoCollisionAlternativeColor;

                        if(accountForm.collisionTypes[index] === accountForm.NOTHING)
                        {
                            ctx.beginPath();

                            ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1));    // RIGHT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, -(dimensionY/2)+(dimensionY/2)*(i+1)); // TOP MIDDLE

                            ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE

                            ctx.fill();

                            if(accountForm.interactiveTypes[index] !== accountForm.NOTHING)
                            {
                                if(accountForm.interactiveTypes[index] === accountForm.INTERACTIVE)
                                    ctx.fillStyle = cellInteractiveColor

                                else if(accountForm.interactiveTypes[index] === accountForm.USABLE)
                                    ctx.fillStyle = cellUsableColor

                                ctx.globalAlpha = 0.5
                                ctx.fill();
                                ctx.globalAlpha=1
                            }

                            ctx.stroke();
                        }

                        if(accountForm.collisionTypes[index] === accountForm.COLLISION_NO_SIGHT)
                        {
                            ctx.beginPath();

                            ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, -(dimensionY/2)+(dimensionY/2)*(i+1)-dimensionY/2); // TOP MIDDLE

                            ctx.fillStyle = collisionBlockColor;

                            ctx.fill();

                            if(accountForm.interactiveTypes[index] !== accountForm.NOTHING)
                            {
                                if(accountForm.interactiveTypes[index] === accountForm.INTERACTIVE)
                                    ctx.fillStyle = cellInteractiveColor

                                else if(accountForm.interactiveTypes[index] === accountForm.USABLE)
                                    ctx.fillStyle = cellUsableColor

                                ctx.globalAlpha = 0.5
                                ctx.fill();
                                ctx.globalAlpha=1
                            }


                            ctx.beginPath();

                            ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                            ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2); //BOTTOM MIDDLE

                            ctx.fillStyle = collisionBlockColor;

                            ctx.fill();

                            if(accountForm.interactiveTypes[index] !== accountForm.NOTHING)
                            {
                                if(accountForm.interactiveTypes[index] === accountForm.INTERACTIVE)
                                    ctx.fillStyle = cellInteractiveColor

                                else if(accountForm.interactiveTypes[index] === accountForm.USABLE)
                                    ctx.fillStyle = cellUsableColor

                                ctx.globalAlpha = 0.5
                                ctx.fill();
                                ctx.globalAlpha=1
                            }

                            ctx.beginPath();

                            ctx.moveTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1));    // RIGHT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE

                            ctx.fillStyle = collisionBlockColor;

                            ctx.fill();

                            if(accountForm.interactiveTypes[index] !== accountForm.NOTHING)
                            {
                                if(accountForm.interactiveTypes[index] === accountForm.INTERACTIVE)
                                    ctx.fillStyle = cellInteractiveColor

                                else if(accountForm.interactiveTypes[index] === accountForm.USABLE)
                                    ctx.fillStyle = cellUsableColor

                                ctx.globalAlpha = 0.5
                                ctx.fill();
                                ctx.globalAlpha=1
                            }

                            ctx.beginPath();

                            ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                            ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1));  // RIGHT MIDDLE

                            ctx.moveTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                            ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                            ctx.lineTo(dimensionX/2+j*dimensionX+margin, -(dimensionY/2)+(dimensionY/2)*(i+1)-dimensionY/2); // TOP MIDDLE
                            ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE

                            ctx.stroke();
                        }


                        if(accountForm.entityTypes[index] !== accountForm.NOTHING)
                        {
                            if(accountForm.entityTypes[index] === accountForm.PLAYER)
                            {
                                ctx.fillStyle = innerPlayerColor;
                                ctx.strokeStyle = aroundPlayerColor;
                            }

                            else if(accountForm.entityTypes[index] === accountForm.PLAYER_BOT)
                            {
                                ctx.fillStyle = innerPlayerBotColor;
                                ctx.strokeStyle = aroundPlayerBotColor;
                            }

                            else if(accountForm.entityTypes[index] === accountForm.BOT)
                            {
                                ctx.fillStyle = innerBotColor;
                                ctx.strokeStyle = aroundBotColor;
                            }

                            else if(accountForm.entityTypes[index] === accountForm.NPC)
                            {
                                ctx.fillStyle = innerNpcColor;
                                ctx.strokeStyle = aroundNpcColor;
                            }

                            else if(accountForm.entityTypes[index] === accountForm.MONSTER)
                            {
                                ctx.fillStyle = innerMonsterColor;
                                ctx.strokeStyle = aroundMonsterColor;
                            }

                            ctx.beginPath();

                            ctx.lineWidth = dimensionY/8

                            ctx.arc(j*dimensionX+margin+dimensionX/2, (dimensionY/2)*(i+1), dimensionY/4, 0, 2*Math.PI);
                            ctx.fill();

                            ctx.stroke();
                        }

                        index++;
                    }
                }
            }
        }
    }
}
