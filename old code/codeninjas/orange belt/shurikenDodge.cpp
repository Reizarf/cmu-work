//scene initialize when start
if($this.scene.state() == "PLAY") {
    nextLevel();
    $this.timeDelay = 3000;
    $this.starSpeed = 100;
    $this.starCount = 0;
        createTimer($this.timeDelay, function() {
            var nShuriken = shuriken.clone();
            var starX = random(760,40);
            nShuriken.x(starX);
            nShuriken.y(10);
            $this.scene.starCount++;
            if($this.scene.starCount >= 20) {
                $this.scene.cleanupTimers();
                $this.scene.starCount = 0;
                $this.scene.starSpeed *= 1.5;
                $this.scene.timeDelay *= 0.8;
                nextLevel();
            }
        });
}

function nextLevel() {
    var gameTimer = createTimer(1000,function () {
        score.text(parseInt(score.text()+ 1));
    });
}

//scene update every frame

if($this.scene.state() == "PLAY") {
    score.text(Math.round($this.scene.timing.life/1000));
}

//shuriken update very frame
$this.moveY($this.scene.starSpeed);
$this.spin($this.scene.starSpeed);

if($this.isTouching(ground)) {
    $this.remove();
}
if($this.isTouching(avatar)) {
    $this.remove();
    $this.scene.stopCode();
}
