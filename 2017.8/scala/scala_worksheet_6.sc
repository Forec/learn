class Graph {
  class Node {
    var connectedNodes: List[Node] = Nil
    def connectTo(node: Node): Unit = {
      // how to fix:
      // change List[Node] to List[Graph#Node]
      // change node: Node to node: Graph#Node
      if (connectedNodes.find(node.equals).isEmpty)
        connectedNodes = node :: connectedNodes
    }
  }
  var nodes: List[Node] = Nil
  def newNode: Node = {
    val res = new Node
    nodes = res :: nodes
    res
  }
}

val graph1: Graph = new Graph
val node1: graph1.Node = graph1.newNode
val node2 = graph1.newNode
val node3 = graph1.newNode
node1.connectTo(node2)
node3.connectTo(node1)

val graph2: Graph = new Graph
val node4 = graph2.newNode
// node1.connectTo(node4)   this is illegal

trait Buffer {
  type T
  val element: T
}

abstract class SeqBuffer extends Buffer {
  type U
  type T <: Seq[U]
  def length = element.length
}

abstract class IntSeqBuffer extends SeqBuffer {
  type U = Int
}

def newIntSeqBuf(elem1: Int, elem2: Int): IntSeqBuffer =
new IntSeqBuffer {
  type T = List[U]
  val element = List(elem1, elem2)
}

val buf = newIntSeqBuf(7, 8)
buf.length
buf.element

abstract class Buffer2[+T] {
  val element: T
}

abstract class SeqBuffer2[U, +T <: Seq[U]] extends Buffer2[T] {
  def length = element.length
}

def newIntSeqBuf2(e1: Int, e2: Int): SeqBuffer2[Int, Seq[Int]] =
new SeqBuffer2[Int, List[Int]] {
  val element = List(e1, e2)
}

val buf2 = newIntSeqBuf2(7, 8)
buf2.length
buf2.element

trait Cloneable extends java.lang.Cloneable {
  override def clone(): Cloneable = {
    super.clone().asInstanceOf[Cloneable]
  }
}

trait Resetable {
  def reset: Unit
}

def cloneAndReset(obj: Cloneable with Resetable): Cloneable = {
  val cloned = obj.clone()
  obj.reset
  cloned
}

trait User {
  def username: String
}

trait Tweeter {
  this: User =>
  def tweet(tweetText: String) = println(s"$username: $tweetText")
}

class VerifiedTweeter(val username_ : String) extends Tweeter with User {
  def username = s"real $username_"
}

val realByonce = new VerifiedTweeter("beyonce")
realByonce.tweet("Just spilled my glass of lemonade")

abstract class SemiGroup[A] {
  def add(x: A, y: A): A
}

abstract class Monoid[A] extends SemiGroup[A] {
  def unit: A
}

implicit object StringMonoid extends Monoid[String] {
  def add(x: String, y: String): String = x concat y
  def unit: String = ""
}

implicit object IntMonoid extends Monoid[Int] {
  def add(x: Int, y: Int): Int = x + y
  def unit: Int = 0
}

def sum[A](xs: List[A]) (implicit m: Monoid[A]): A =
if (xs.isEmpty) m.unit
else m.add(xs.head, sum(xs.tail))

sum(List(1, 2, 3))