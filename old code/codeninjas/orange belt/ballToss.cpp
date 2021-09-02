//scene update every frame

var pos = getPointerPos();
var gravity = 8;
var spacePressed = isKeyPressed(Keys.space);
var cannonX = pos.x - cannon.x();
var cannonY = pos.y - cannon.y();

if(spacePressed && ball.isFired === false) {
    label.text("");
    ball.isFired = true;
    ball.dirX = cannonX;
    ball.dirY = cannonY;
}

if(ball.isFired === true) {
    ball.dirY += gravity;
    ball.moveX(ball.dirX);
    ball.moveY(ball.dirY);
}

var basket = basketGroup.findName("basket");
function resetBall () {
    ball.x(35);
    ball.y(550);
    ball.isFired = false;
}
if(ball.x() > 800 || ball.y() > 600) {
    resetBall();
}
if(ball.isTouching(basket)) {
    resetBall();
    label.text("SCORE!");
    basketGroup.x(random(600,400));
    basketGroup.y(random(508,300));
}
