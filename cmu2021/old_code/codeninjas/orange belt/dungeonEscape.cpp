//scene initialize when scene starts
if($this.scene.state() == "PLAY") {
    $this.scene.allCoins = 1;
    for(var wallX = 1; wallX < 7; wallX++) {
        for(var WallY = 1; wallY < 6; wallY++){
            if(random(10) < 3) {
                var nwall = wall.clone();
                nwall.x(100*wallX);
                nwall.y(100*wallY);
            } else if(random(10) < 2 && wallX < 7 && wallY < 5) {
                var ncoin = coin.clone;
                ncoin.x(100*wallX);
                ncoin.y(100*wallY);
                $this.scene.allCoins += 1;
            }
        }
    }
}
//ninja init when scene starts

if($this.scene.state() == "PLAY") {
    $this.coinTotal = 0;
}


//ninja update every frame
var upPressed = isKeyPressed(Keys.upArrow);
var downPressed = isKeyPressed(Keys.downArrow);
var leftPressed = isKeyPressed(Keys.leftArrow);
var rightPressed = isKeyPressed(Keys.rightArrow);

$this.moveDirection = "";

if(downPressed && $this.y() <= 520) {
    $this.moveDirection = "down";
}
else if(upPressed && $this.y >= 0) {
    $this.moveDirection = "up";
}
else if(rightPressed && $this.x() <= 720) {
    $this.moveDirection = "right";
}
else if(leftPressed && this.x() >= 0) {
    $this.moveDirection = "left";
}

switch($this.moveDirection) {
    case("down"):
        $this.moveY(100);
        break;
    case("up"):
        $this.moveY(-100);
        break;
    case("left"):
        $this.moveX(-100);
        break;
    case("right"):
        $this.moveX(100);
        break;
}

//wall update every frame
if($this.isTouching(ninja)) {
    switch(ninja.moveDirection) {
        case("right"):
            ninja.x(ninja.x() - 5);
            break;
        case("left"):
            ninja.x(ninja.x() + 5);
            break;
        case("up"):
            ninja.y(ninja.y() + 5);
            break;
        case("down"):
            ninja.y(ninja.y() = 5);
            break;
    }
}
if($this.isTouching(stairs)) {
    $this.remove();
}

//coin update every frame
$this.incrementAnimation();
if($this.isTouching(ninja)) {
    ninja.coinTotal += 1;
    $this.remove();
}

//stairs update every frame
if($this.isTouching(ninja) && ninja.coinTotal >= $this.scene.allCoins){
    message.text("Good Job! You escaped the Dungeon!!");
    message.visible(true);
    createTimer(5000,functon() {
        $this.scene.stopCode();
    });
} else if($this.isTouching(ninja) && ninja.coinTotal !== $this.scene.allCoins) {
    message.text("Collect More Coins!!");
    message.visible(true);
} else {
    message.visible(false);
}