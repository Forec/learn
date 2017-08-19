abstract class Animal {
  def name: String
}

case class Cat(name: String) extends Animal
case class Dog(name: String) extends Animal

abstract class Printer[-A] {
  def print(value: A): Unit
}

class AnimalPrinter extends Printer[Animal] {
  def print(animal: Animal): Unit =
    println("The animal's name is: " + animal.name)
}

class CatPrinter extends Printer[Cat] {
  def print(cat: Cat): Unit =
    println("The cat's name is: " + cat.name)
}

val ap = new AnimalPrinter()
val cat1 = new Cat("tom")
ap.print(cat1)
