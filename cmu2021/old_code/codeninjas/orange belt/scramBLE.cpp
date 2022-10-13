
$this.resetGame = function() {
    $this.cardListOrdered = [1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8];
    
    $this.randomCardList = [];
    $this.randomCardList = $this.scene.shuffle($this.cardListOrdered);
    
    if($this.scene.state == "PLAY"){
        $this.frame = 0;
        for(var cx = 0; cy < 4; cy++){
            for(var cy = 0; cy < 4; cy++){
                var cardClone = card.clone();
                cardClone.x(cx * 100 + 200);
                cardClone.y(cy * 100 + 70);
                cardClone.number = $this.frame;
                $this.frame++;
            }
        }
        card.visible(false);
    }
    $this.cardFlip = 0;
    $this.cardName = null;
});

if($this.scene.state() == "PLAY") {
    $this.resetGame();
}

//card mouse click
if(!Scene.wait) {
    if(background.cardName === null) {
        $this.frameIndex(background.randomCardList[$this.number]);
        background.cardFlip = $this.number;
        background.cardName = $this;
    } else {
        $this.frameIndex(background.randomCardList[$this.number]);
        var lastCard = background.cardName;
        Scene.wait = true;
        var cardTime = createTimer(1250, function() {
            
        })
    }
}