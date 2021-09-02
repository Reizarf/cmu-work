
//target 1-4, mouse button down
if(dummy.playerInput) 
{
    $this.frameIndex(1);
}

//target 1 mouse button up
if(dummy.playerInput) 
{
    $this.frameIndex(0);
    dummy.playerSequence.push(1);
}

//target 2 mouse button up
if(dummy.playerInput) 
{
    $this.frameIndex(0);
    dummy.playerSequence.push(2);
}

//target 3
if(dummy.playerInput) 
{
    $this.frameIndex(0);
    dummy.playerSequence.push(3);
}

//target  4
if(dummy.playerInput) 
{
    $this.frameIndex(0);
    dummy.playerSequence.push(4);
}


//dummy initialze when scene starts

if($this.scene.state() == "PLAY")
{
    $this.playerSequence = [];
    $this.playerInput = false;
    $this.sequence = [];
    $this.computerAction = 0;
    $this.playerAction = 0;
    $this.timeOn = false;
    $this.totalScore = 0;
    var num = Math.round(random(4,1));
    $this.sequence.push(num);
}

//dummy update every frame

if($this.computerAction === 0 && !$this.timeOn)
{
    advanceTime();
}
function advanceTime()
{
    var target = buttons.findName("target" + dummy.sequence[$this.computerAction]);
    target.frameIndex(1);
    $this.timeOn = true;
    var sequenceTimer = createTimer(600, function() {
        target.frameIndex(0);
        $this.computerAction++;
        if($this.computerAction >= dummy.sequence.length){
            dummy.playerInput == true;
            $this.playerAction = 0;
        }
        var buttonTimer = createTimer(400, function () {
            advanceTime();
        },false);
    },false);
}

if($this.playerInput) {
    if($this.playerSequence[$this.playerAction] == $this.sequence[$this.playerAction]){
        $this.playerAction++;
        if($this.playerAction >= $this.sequence.length) {
            $this.totalScore+=1;
            score.text("Score: " + $this.totalScore);
            $this.playerInput = false;
            var num = Math.round(random(4,1));
            $this.sequence.push(num);
            $this.playerSequence = [];
            $this.computerAction = 0;
            var buttonTiemr = createTimer(400, function() {
                advanceTime();
            },false);
        }
    }else if($this.playerSequence[$this.playerAction] > 0) {
        message.text("Game Over!");
    }
}