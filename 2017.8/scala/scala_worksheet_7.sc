def listOfDuplicated[A](x: A, length: Int): List[A] = {
  if (length < 1)
    Nil
  else
    x:: listOfDuplicated(x, length - 1)
}

listOfDuplicated(3, 4)
listOfDuplicated("La", 8)

val x = 1 + 2 * 3
val y = x.toString()
def succ(x: Int) = x + 1
succ(34)

10.+(1)

// any legal identifier can act as an operator
case class Vec(val x: Double, val y: Double) {
  def +(that: Vec) = new Vec(this.x + that.x, this.y + that.y)
}

val vector1 = Vec(1.0, 2.0)
val vector2 = Vec(2.0, 2.0)

val vector3 = vector1 + vector2
vector3.x

// operator starts with character ? has the highest precedence?

// => means is going to be (in the future)
def calculate(input: => Int) = input * 37
def whileLoop(condition: => Boolean)(body: => Unit): Unit =
if (condition) {
  body
  whileLoop(condition)(body)
}

var i = 2

whileLoop(i > 0) {
  println(i)
  i -= 1
}

object DeprecationDemo extends App{
  @deprecated
  def hello = "hola"
  hello
}

import scala.annotation.tailrec
def factorial(x: Int): Int = {
  @tailrec  // this ensures the method is indeed tail-recursive
  def factorialHelper(x: Int, accumulator: Int): Int = {
    if (x== 1) accumulator
    else factorialHelper(x - 1, accumulator * x)
  }
  factorialHelper(x, 1)
}

