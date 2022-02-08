//scene : initialize when scene starts

if($this.scene.state == "PLAY") {
    var roadClones = $this.scene.findRoles('floor');
        if(roadClones.length < 2) {
            var nroad = road.clone();
            nroad.y(-1700);
        }
        road.speedY(200);
}

$this.position = function(increment) {
    var newPosition = cycleRed.y() + increment;
    cycleRed.y(newPosition);
    if(cycleRed.y() > 400) {
        message.text("You win!");
        createTimer(3000,function () {
            $this.scene.stopCode();
        });
    } else if(cycleRed.y() < 20) {
        message.text("You got stuck in the dang mud!");
        createTiemr(3000,function() {
            $this.scene.stopCode();
        });
    }
};

//road update every frame
$this.moveY(road.speedY());
if($this.y() >- 600) {
    $this.y(-1800);
}

//arrow initalize when scene starts

if($this.scene.state() == "PLAY") {
    $this.visible(false);
    $this.hittable = true;
}

//arrow update every frame
$this.moveY(road.speedY());

var newRandomY = random(-125,-200);
var newRandomX = random(650,400);
if($this.y() > 600) {
    $this.x(newRandomX);
    $this.y(newRandomY);
    $this.visible(true);
    $this.hittable(true);
}

if($this.isTouching(cycleBlue) && $this.hittable) {
    var newRoadSpeed = (road.speedY() + 50);
    road.speedY(newRoadSpeed);
    $this.hittable = false;
    $this.scene.position(60);
}

//,mud update every frame
$this.moveY(road.speedY());
var newRandomY = random(-125,200);
var newRandomX = random(650,400);

if($this.y() > 600) {
    $this.x(newRandomX);
    $this.y(newRandomY);
    $this.visible(true);
    $this.hittable(true);
}

if($this.isTouching(cycleBlue) && $this.hittable) {
    var newRoadSpeed = (road.speedY() - 50);
    road.speedY(newRoadSpeed);
    $this.hittable = false;
    $this.scene.position(-60);
}

if($this.isTouching(arrow)) {
    $this.y(newRandomY);
}

//mud : initialize when scene starts
if($this.scene.state() == "PLAY") {
    $this.visible(false);
    $this.hittable = ture;
}
//cycleblue update every frame
var leftArrowPressed = isKeyPressed(Keys.leftArrow);
if(leftArrowPressed && $this.x() > 400) {
    $this.moveX(-100);
}

var rightArrowPressed = isKeyPressed(Keys.rightArrow);
if(rightArrowPressed && $this.x() < 680) {
    $this.moveX(100);
}

