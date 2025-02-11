import processing.serial.*;
import processing.video.*;

final int MAX_KNOB_RANGE = 255;
final String PORT_NAME = "/dev/tty.usbmodem6766581"; // on mac
final String MOVIE_FILE_NAME = "raddish30001-0300.mkv";
//final String PORT_NAME = "/dev/ttyACM0"; // on rpi3

Serial myPort;
String val;
Movie myMovie;

Float timeToJump;

void setup()
{
  //printArray(Serial.list());
  //myPort = new Serial(this, PORT_NAME);
  size(1920, 1080);
  background(0);
  myMovie = new Movie(this, MOVIE_FILE_NAME);
  myMovie.loop();
}

void draw()
{
  //if (myPort.available() > 0) {
  //  val = myPort.readStringUntil('\n');
  //  println(val);
  //  float timeToJump = map(Float.valueOf(val), 0, MAX_KNOB_RANGE, 0, myMovie.duration());
  //  myMovie.jump(timeToJump);
  //} 

  image(myMovie, 0, 0);
}

void movieEvent(Movie m) {
  m.read();
}
