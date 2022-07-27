class Actor {
	constructor(canvas, x, y, color, shadow, speed, me) {
		this.canvas = canvas;
		this.x = x;
		this.y = y;
		this.color = color;
		this.shadow = shadow;
		this.speed = speed;
		this.me = me;

		this.tileWidth = this.canvas.width/14*13.5/14;
		this.tileHeight = this.canvas.height/20*19/20;;
	}

	draw(context) {
		context.save();

        if(context !== undefined)
        {
            context.shadowBlur=3;
            context.shadowColor="#" + this.shadow.toString(16);
        }

        if(color !== undefined)
            context.fillStyle= "#" + this.color.toString(16);

        context.beginPath();

        if(this.me === MapForm.BOT)
            context.arc(this.x + this.tileWidth / 2,	this.y + this.tileHeight / 2, this.tileHeight / 3, 0, Math.PI * 2, false);
        else
            context.arc(this.x + this.tileWidth / 2,	this.y + this.tileHeight / 2, this.tileHeight / 3.8, 0, Math.PI * 2, false);

        context.closePath();

        if(color !== undefined)
            context.fill();

        context.restore();
	}

	update() {
		this.draw(context);
	}
}