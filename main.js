var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

canvas.width = window.innerWidth - 100;
canvas.hegiht = window.innerHeight - 100;

var image2 = new Image();
img2.src = ' dino1.png'

var dino = {
    x : 10,
    y : 200,
    width : 50,
    hegiht : 50,
    draw(){
        ctx.fillstyle = "bule"
        //네모ctx.fillRecnt(this.x,this.y, this.width,this.hegiht)
        ctx.drawImage(img2, this.x,this.y);
    }
}

var image = new Image();
img1.src = 'cactus1.png'


class Cactus{
    constructor(){
        this.x = 500;
        this.y = 200;
        this.width = 50;
    }
    draw(){
        ctx.fillstyle = 'dark';
        //네모 그려둔거ctx.fillRecnt(this.x,this.y, this.width,this.hegiht)
        ctx.drawImage(img1, this.x,this.y);
    }
}
var Cactus = new Cactus(); 
Cactus.draw()

var timer = 0;
var Cactus여러개 = [];
var jumptimer = 0;
var animation;

function 프레임마다실행하기(){
    animation = requestAnimationFrame(프레임마다실행하기);
    timer++;

    ctx.clearRect(0,0, canvas.width,canvas.hegiht);

    if(timer % 200 == 0){
        var Cactus = new Cactus();
        Cactus여러개.push(Cactus);
    }
    Cactus여러개.forEach((a,i,o)=>{
        //x좌표가 0미만일시 제거
        if(a.x < 0){
            o.splice(i,1)
        }
        a.x--;

        충돌해(dino,a);

        a.draw();
    })//점프
    if(sw점프 ==true){
        dino.y--;
        jumptimer++;
    }
    if(sw점프 == flase){
        if(dino.y > 200){
            dino.y++;
        }     
    }
    if(jumptimer > 100){
        sw점프 = flase;
        jumptimer = 0
    }
    dino.draw()
}

//충돌 확인

function 충돌해(dino,Cactus){
    var xchar = Cactus.x - (dino.x + dino.width);
    var ychar = Cactus.y - (din0.y + dino.hegiht);
    if (xchar < 0 && ychar < 0){
        ctx.clearRect(0,0, canvas.width,canvas.hegiht);
        cancelAnimationFrame(animation)
    }
}

프레임마다실행하기();
var sw점프 = flase; 
document.addEventListener('keydown',function(e){
    if (e.code == 'Space'){
        sw점프 = true;
    }
})