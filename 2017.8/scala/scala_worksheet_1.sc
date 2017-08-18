def square(x: Int) = x * x
square(2)

val x: Int = 3 * 3

val add = (x: Int, y: Long) => x + y
add(2, 3)

def multParas = (x: Int) => (y: Int) => x + y
multParas(2)(30)

def tripleParas(x: Int)(y: Int)(z: Int): String = {
  val x_y: Long = x * y
  (x_y - z).toString
}

tripleParas(2)(3)(5)

class Greeter(prefix: String, suffix: String) {
  def greet(name: String) : Unit =
    println(prefix + name + suffix)
}

val greeter: Greeter = new Greeter("Hello ", ", you mother fucker")
greeter.greet("Billy Herrington")

case class Point(x: Int, y: Int)

val point = new Point(1, 2)
val anotherPoint = Point(1, 2)

if (point == anotherPoint) {
  println("Hey mother fucker")
} else {
  println("Who's your daddy now.")
}

object IdFactory {
  private var counter = 0
  def create(): Int = {
    counter += 1
    counter
  }
}

val newId: Int = IdFactory.create()
val nextId: Int = IdFactory.create()

trait nGreeter {
  def greet(name: String): Unit =
    println("Hello, " + name + ", Oh~")
}

class DefaultGreeter extends nGreeter
class CustomizableGreeter(prefix: String, suffix: String) extends nGreeter {
  override def greet(name: String): Unit =
    println(prefix + name + suffix)
}

val greeter1 = new DefaultGreeter()
val greeter2 = new CustomizableGreeter("hey", "fuck me")

greeter1.greet("Billy")
greeter2.greet("Herrington")

object Main {
  def main(args: Array[String]): Unit = {
    println("hey billy")
  }
}

val list: List[Any] = List(
  "a string",
  732,
  'c',
  true,
  (x: Int) => x + 1
)

list.foreach((element: Any) => println(element))

class TPoint {
  private var _x = 0
  private var _y = 0
  private val bound = 100

  def x = _x
  def x_= (newValue: Int): Unit = {
    if (newValue < bound) _x = newValue else printWarning()
  }

  def y = _y
  def y_= (newValue: Int): Unit = {
    if (newValue < bound) _y = newValue else printWarning()
  }

  private def printWarning(): Unit = println("WARNING: Out of bounds.")
}

val tp1 = new TPoint
tp1.x = 99
tp1.x

trait Iterator[A] {
  def hasNext: Boolean
  def next(): A
  def pnext(): Iterator[A]
}

// parameters in constructor without val/var are private
class IntIterator(to: Int) extends Iterator[Int] {
  private var current = 0
  override def hasNext: Boolean = current < to
  override def next(): Int = {
    if (hasNext) {
      var t: Int = current
      current += 1
      t
    } else 0
  }
  override def pnext(): IntIterator = {
    println(next())
    this
  }
}

val iterator = new IntIterator(3)
iterator.pnext().pnext().next()

import scala.collection.mutable.ArrayBuffer

trait Pet {
  val name: String
  override def toString(): String = {
    name
  }
}

class Cat(val name: String) extends Pet
class Dog(val name: String) extends Pet

val dog = new Dog("Harry")
val cat = new Cat("Billy")

val animals = ArrayBuffer.empty[Pet]
animals.append(dog)
animals.append(cat)
animals.foreach(println(_))
