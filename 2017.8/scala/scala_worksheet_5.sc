abstract class Animal {
  def name: String
}

abstract class Pet extends Animal {}

class Cat extends Pet {
  override def name: String = "cat"
}

class Dog extends Pet {
  override def name: String = "dog"
}

class Lion extends Animal {
  override def name: String = "lion"
}

class PetContainer[P <: Pet](p: P) {
  def pet: P = p
}

val dogContainer = new PetContainer[Dog](new Dog)
val catContainer = new PetContainer[Cat](new Cat)

trait Node[+B] {
  def prepend[U >: B](elem: U): Unit
}

case class ListNode[+B](h: B, t: Node[B]) extends Node[B] {
  def prepend[U >: B](elem: U) = ListNode[U](elem, this)
  def head: B = h
  def tail = t
}

case class Nil[+B] extends Node[B] {
  def prepend[U >: B](elem: U) = ListNode(elem, this)
}

trait Mammal
case class AfricanSwallow() extends Mammal
case class EuropeanSwallow() extends Mammal

val africanSwallowList = ListNode[AfricanSwallow](AfricanSwallow(), Nil
val mammalList: Node[Mammal] = africanSwallowList
mammalList.prepend(new EuropeanSwallow)

