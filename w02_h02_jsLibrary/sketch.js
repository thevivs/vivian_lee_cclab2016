var jerk;
var fist, punchee, poww, ouch;
var jerkImage, puncheeImage, powImage, ouchImage, fistImage;
var face;
var faceImage;
var value = 0;
var test; 
var x, y;


function setup() {
  bg = loadImage("assets/chalkboard.jpg");
  createCanvas(1024, 768);

  jerkImage = loadImage("assets/jerk.png");   
  jerk = createSprite(250, 500); 
  jerk.addImage(jerkImage); 
  
  
  puncheeImage = loadImage("assets/body.png");
  punchee = createSprite(740, 530); 
  punchee.addImage(puncheeImage); 
  
  
  faceImage = loadImage("assets/face0.png");
  face = createSprite(710, 390);
  face.addImage(faceImage);
  face.addAnimation("normal","assets/face1.png","assets/face2.png","assets/face3.png")  
    
  fistImage = loadImage("assets/fist.png");
  fist = createSprite(x, y);
  fist.addImage(fistImage);


}

function draw() {
 
  background(bg); 
  
  if(mouseWentDown(LEFT)){
    fist.position.x = 710;
    fist.position.y = 390;
    fist.rotation = -90;
  } else {
    fist.position.x = 250;
    fist.position.y = 650;
    fist.rotation = 0;
  }



  drawSprites();
}


