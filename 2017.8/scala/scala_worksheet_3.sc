case class User(val name: String, val age: Int)

val userBase = List(new User("Travis", 28),
  new User("Kelly", 33),
  new User("Jennifer", 44),
  new User("Dennis", 23))

val twentySomethings = for (user <- userBase if (user.age >= 20 && user.age < 30))
  yield user.name

twentySomethings.foreach(println)

def foo(n: Int, v: Int) =
for (i <- 0 until n;
     j <- i until n if i + j == v)
  yield (i, j)

foo(10, 10).foreach{
  case (a, b)=>print(s"($a, $b)")
}

def factor(n: Int): Long = {
  var res: Long = 1
  for (i <- 1 until n)
    res = res * i
  res
}

factor(0)

def even(from: Int, to: Int): List[Int] =
 for (i <- List.range(from, to) if i % 2 == 0) yield i
even(0, 20)

class Stack[A] {
  private var elements: List[A] = Nil
  def push(x: A) { elements = x :: elements }
  def peek: A = elements.head
  def pop(): A = {
    var currentTop: A = peek
    elements = elements.tail
    currentTop
  }
}

val stack = new Stack[Int]
stack.push(1)
stack.push(2)
stack.pop()
stack.pop()

class Fruit {
  override def toString: String = "Fruit"
}
class Apple extends Fruit {
  override def toString: String = "Apple"
}
class Banana extends Fruit {
  override def toString: String = "Banana"
}

val stack2 = new Stack[Fruit]
val apple = new Apple
val banana = new Banana

stack2.push(apple)
stack2.push(banana)
stack2.pop().toString

abstract class Animal {
  def name: String
}

case class Cat(name: String) extends Animal
case class Dog(name: String) extends Animal

def printAnimalNames(animals: List[Animal]): Unit = {
  animals.foreach(animal => println(animal.name))
}

val cats: List[Cat] = List(Cat("Whiskers"), Cat("Tom"))
val dogs: List[Dog] = List(Dog("Fido"), Dog("Rex"))

printAnimalNames(cats)
printAnimalNames(dogs)
