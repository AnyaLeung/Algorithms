PImage img, newImg;
float[][] gradientMagnitude;
float[][] seamFitness;

void setup() {
  
  String url = "Broadway tower.jpg";
  img = loadImage(url, "jpg");
  size(500,333);

  background(255);
  image(img, 0, 0);
}

float colorDistance(color c1, color c2) {
  float r = red(c1) - red(c2);
  float g = green(c1) - green(c2);
  float b = blue(c1) - blue(c2);
  return (r*r + g*g + b*b);
}

void computeGradient() {
  color left, right, above, below;
  int center;
  gradientMagnitude = new float[img.width][img.height];
  img.loadPixels();

  for (int x = 0; x < img.width; x++) {
    for (int y = 0; y < img.height; y++) {
      center = x + y*img.width;

      if (x == 0) 
        left = img.pixels[center];
      else 
        left = img.pixels[(x-1) + y*img.width];
      
      if (x == img.width-1) 
        right = img.pixels[center];
      else 
        right = img.pixels[(x+1) + y*img.width];

      if (y == 0) 
        above = img.pixels[center];
      else 
        above = img.pixels[x + (y-1)*img.width];

      if (y == img.height - 1) 
        below = img.pixels[center];
      else 
        below = img.pixels[x + (y+1)*img.width];

      gradientMagnitude[x][y] = colorDistance(left, right) + colorDistance(above, below);
    }
  }
}

void computeVerticalSeams() {
  seamFitness = new float[img.width][img.height];
  for (int i = 0; i < img.width; i++) 
    seamFitness[i][0] = gradientMagnitude[i][0];
  
  for (int y = 1; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      seamFitness[x][y] = gradientMagnitude[x][y];

      if (x == 0)
        seamFitness[x][y] += min(seamFitness[x][y-1], seamFitness[x+1][y-1]);
      else if (x == img.width-1)
        seamFitness[x][y] += min(seamFitness[x][y-1], seamFitness[x-1][y-1]);
      else
        seamFitness[x][y] += min(seamFitness[x-1][y-1], seamFitness[x][y-1], seamFitness[x+1][y-1]);
      
    }
  }
}

PImage removeVerticalSeams(int numAttempts) {
  computeGradient();
  computeVerticalSeams();
  
  newImg = createImage(img.width-numAttempts, img.height, RGB);
  newImg.loadPixels();

  
  int bestCol = 0;
  for (int i = 0; i < img.width-1; i++)
    if (seamFitness[bestCol][img.height-1] > seamFitness[i][img.height-1])
      bestCol = i;  

  for (int y = newImg.height-1; y >= 0; y--) {
    boolean pastBestCol = false;

    for (int x = 0; x < newImg.width; x++) {
      if (x == bestCol) 
        pastBestCol = true;      

      int newLoc = x + y*newImg.width;

      int oldLoc;
      if (pastBestCol)
        oldLoc = x + 1;
      else
        oldLoc = x;
      oldLoc += y*img.width;

      newImg.pixels[newLoc] = img.pixels[oldLoc];
    }

    if (y > 0) {
      // update best column for the next row
      float theMin = seamFitness[bestCol][y-1];

      if (bestCol > 0 && seamFitness[bestCol-1][y-1] <= theMin) 
        bestCol = bestCol - 1;
      else if (bestCol < img.width-1 && seamFitness[bestCol+1][y-1] <= theMin)
        bestCol = bestCol + 1;
      
    }
  } 

  newImg.updatePixels();
  return newImg;
}

void seamCarveTo(int newWidth) {  
  if (newWidth < img.width) {
    println("loading....");
    while (newWidth < img.width) {
      img = removeVerticalSeams(1);
    }
    println("down");
  }
}

void mousePressed() {
  if (mouseX > 0 && mouseY > 0) {
     seamCarveTo(mouseX);
  }
}

void draw() {
   background(255);
   image(img, 0, 0);
}

void keyPressed() {
  setup();
}
