import processing.serial.*;
import processing.video.*;
//import gohai.glvideo.*; // needed for pi?

Serial myPort;
String val;
Movie myMovie;
//int rate = 0;

void setup()
{
  printArray(Serial.list());
  String portName = Serial.list()[2]; // /dev/ttyACM0
  myPort = new Serial(this, portName, 9600);
  size(640, 480);
  background(0);
  myMovie = new Movie(this, "plant-timelapse.mp4");
  myMovie.play();
}

void draw()
{
  if (myPort.available() > 0) {
    val = myPort.readStringUntil('\n');
    float rate = Float.valueOf(val);
    //println(val);
    float duration = myMovie.duration();
    float where = map(rate, 0, 1023, 0, duration);
    myMovie.jump(where);
  } 

  image(myMovie, 0, 0);

  println(val);
}

void movieEvent(Movie m) {
  m.read();
}
