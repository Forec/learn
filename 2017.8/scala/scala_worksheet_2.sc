abstract class AbsIterator {
  type T
  def hasNext: Boolean
  def next: T
}

class StringIterator(s: String) extends AbsIterator {
  type T = Char
  private var i = 0
  def hasNext = i < s.length
  def next = {
    val ch = s.charAt(i)
    i += 1
    ch
  }
}

trait RichIterator extends AbsIterator {
  def foreach(f: T => Unit): Unit = while (hasNext) f(next)
}

object StringIteratorTest extends App {
  class Iter extends StringIterator(args(0)) with RichIterator
  val iter = new Iter
  iter.foreach(println)  // also can be written as "iter foreach println"
}

def factorial(x: Int): Int = {
  def fact(x: Int, accumulator: Int): Int = {
    if (x <= 1) accumulator
    else fact(x - 1, x * accumulator)
  }
  fact(x, 1)
}

object CurryTest extends App {
  def filter(xs: List[Int], p: Int => Boolean): List[Int] =
    if (xs.isEmpty) xs
    else if (p(xs.head)) xs.head :: filter(xs.tail, p)
    else filter(xs.tail, p)
  def modN(n: Int)(x: Int) = ((x % n) == 0)
}


val nums = List(1, 2, 3, 4, 5, 6, 7, 8)
println(CurryTest.filter(nums, CurryTest.modN(2)))
println(CurryTest.filter(nums, CurryTest.modN(3)))

case class Message(sender: String, recipient: String, body: String)

val message1 = Message("guillaume@quebec.ca", "jorge@catalonia.es", "a va?")
println(message1.sender)

import scala.collection.mutable.ArrayBuffer
import scala.util.Random
val x: Int = Random.nextInt(10)

x match {
  case 0 => "zero"
  case 1 => "one"
  case 2 => "two"
  case _ => "many"
}

abstract class Notification
case class Email(sender: String, title: String, body: String) extends Notification
case class SMS(caller: String, message: String) extends Notification
case class VoiceRecording(contactName:String, link: String) extends Notification

def showNotification(notification: Notification): String = {
  notification match {
    case Email(email, title, _) =>
      s"You got an email from $email with title: $title"
    case SMS(number, message) =>
      s"You got an SMS from $number! Message: $message"
    case VoiceRecording(name, link) =>
      s"You received a voice recording from $name! Click the link to hear it: $link"
  }
}

val someSMS = SMS("12345", "Are you there?")
val someVoiceRecording = VoiceRecording("Tom", "voicerecording.org/")

showNotification(someSMS)
showNotification(someVoiceRecording)

abstract class Device
case class Phone(model: String = "") extends Device {
  def screenOff = "Turning screen off"
}
case class Computer(model: String) extends Device {
  def screenSaverOn = "Turning screen saver on..."
}

def goIdle(device: Device) = device match {
  case p: Phone => p.screenOff
  case c: Computer => c.screenSaverOn
}

goIdle(new Computer("puppy"))

class IntPair(val x: Int, val y: Int)

object IntPair {
  import math.Ordering
  implicit def ipord: Ordering[IntPair] =
    Ordering.by(ip => (ip.x, ip.y))
}

object TX {
  private val foo: Int = 100
}

class TX {
  import TX._
  var p: Int = foo
}

import scala.util.matching.Regex
val numberPattern: Regex = "[0-9]".r

numberPattern.findFirstMatchIn("awesomepassword") match {
  case Some(_) => println("Password OK")
  case None => println("Password must contain a number")
}

val keyValPattern: Regex = "([0-9a-zA-Z-#() ]+): ([0-9a-zA-Z-#() ]+)".r
val input: String =
  """background-color: #A03300;
    |background-image: url(img/header100.png);
    |background-position: top center;
    |background-repeat: repeat-x;
    |background-size: 2160px 108px;
    |margin: 0;
    |height: 108px;
    |width: 100%;""".stripMargin

val buffer = ArrayBuffer.empty[String]
for (patternMatch <- keyValPattern.findAllMatchIn(input))
  buffer.append(s"key: ${patternMatch.group(1)} value: ${patternMatch.group(2)}")

buffer.length

keyValPattern.findFirstMatchIn("background-position: top center;") match {
  case Some(x) => println(x)
  case None => ()
}

object CustomerID {
  def apply(name: String) = s"$name--${Random.nextLong}"
  def unapply(customerID: String): Option[String] = {
    val name = customerID.split("--").head
    if (name.nonEmpty) Some(name) else None
  }
}

val customer1ID = CustomerID("Sukyoung")
customer1ID match {
  case CustomerID(name) => println(name)
  case _ => println("Could not extract a customer ID")
}

val customer2ID = CustomerID("Nico")
val CustomerID(name) = customer2ID
name