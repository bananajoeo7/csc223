# Red-Black Binary Search Tree (BST) Presentation:
## By Trostin & Anfal

### What is a BST:
1. They are ordered, or sorted, binary trees.
2. Nodes can have 2 subtrees.
3. Items left of a node are always smaller and larger on the right.

### BST Code:
``` 
class Node
  attr_reader :value
  attr_accessor :left, :right

  def initialize(value=nil)
    @value = value
    @left = nil
    @right = nil
  end
end

class BinaryTree
  attr_accessor :root_node

  def initialize(root_value=nil)
    @root_node = root_value.nil? ? nil:Node.new(root_value)
  end

  def insert(value, node = @root_node)
    if @root_node.nil?
      @root_node = Node.new(value)
      return @root_node
    end

    if node.nil?
      return Node.new(value)
    end

    if value > node.value
      node.right = insert(value, node.right)
    else
      node.left = insert(value, node.left)
    end
    node
  end
  
  def search(root = @root_node, value)
    return nil if root.nil?
    if root.value == value
      return root
    end
    if root.value < value
      return search(root.right, value)
    end
    search(root.left, value)
  end

  def delete(value, node = @root_node)
    return nil if node.nil?
    return @root_node unless search(@root_node, value)

    if value < node.value
      node.left = delete(value, node.left)
    elsif value > node.value
      node.right = delete(value, node.right)
    else
      return node.right if node.left.nil?
      return node.left if node.right.nil?

      successor = node.right
      successor = successor.left while successor.left

      node.value = successor.value
      node.right = delete(successor.value, node.right)
    end
    node
  end
  
end
```

### What is a Red-Black BST:
1. A node is always assigned a <span style="color:red">Red</span> or a <span style="color:grey">black</span> value.
2. The root is always black and the NIL values at the ends are also assigned black.
3. If a node is red, then its children must be black.
4. All paths from the root node to its NIL descendants must contain the same number of black nodes.

### Rotations:
1. Alter the structure of the Red-Black tree by rearranging subtrees so the whole tree is balanced.
2. The goal is to decrease the heigh and imbalace of the overall tree (red-black trees: maximum height of O(log n))
3. doesn't affect the order of the elements

### Red-Black Tree Code:
``` 
class RBNode
  attr_accessor :value, :left, :right, :color

  RED = :red
  BLACK = :black

  def initialize(value, color = RED)
    @value = value
    @left = nil
    @right = nil
    @color = color
  end

  def c_red?
    @color == RED
  end
end

class RedBlackTree
  attr_accessor :root_node

  def initialize
    @root_node = nil
  end

  def insert(value)
    @root_node = insert_recursive(@root_node, value)
    @root_node.color = RBNode::BLACK
  end

  def insert_recursive(node, value)
    return RBNode.new(value) if node.nil?

    if value < node.value
      node.left = insert_recursive(node.left, value)
    else
      node.right = insert_recursive(node.right, value)
    end

    node = rotate_left(node) if red?(node.right) && !red?(node.left)
    node = rotate_right(node) if red?(node.left) && red?(node.left&.left)
    flip_colors(node) if red?(node.left) && red?(node.right)

    node
  end

  def red?(node)
    node&.red?
  end

  def rotate_left(h)
    x = h.right
    h.right = x.left
    x.left = h
    x.color = h.color
    h.color = RBNode::RED
    x
  end

  def rotate_right(h)
    x = h.left
    h.left = x.right
    x.right = h
    x.color = h.color
    h.color = RBNode::RED
    x
  end

  def flip_colors(h)
    h.color = RBNode::RED
    h.left.color = RBNode::BLACK
    h.right.color = RBNode::BLACK
  end

  def delete(value)
    @root_node = delete_recursive(@root_node, value)
    @root_node.color = RBNode::BLACK if @root_node
  end

  def delete_recursive(node, value)
    return node if node.nil?

    if value < node.value
      node.left = delete_recursive(node.left, value)
    elsif value > node.value
      node.right = delete_recursive(node.right, value)
    else
      # Node with one child or no children
      if node.left.nil? || node.right.nil?
        return node.left || node.right
      end

      # Node with two children
      successor = min(node.right)
      node.value = successor.value
      node.right = delete_recursive(node.right, successor.value)
    end

    node = balance_after_deletion(node)
    node
  end

  def balance_after_deletion(node)
    # Balance cases
    if red?(node.right)
      node = rotate_left(node)
    end
    if red?(node.left) && !red?(node.left.left)
      node = rotate_right(node)
    end
    if red?(node.left) && red?(node.left.left)
      flip_colors(node)
    end
    node
  end

  def min(node)
    while node.left
      node = node.left
    end
    node
  end
```


## Now Trostin Will go on to explain how the code/a red-black tree works using the whiteboard

#### Sources:
- [Red-Black Trees](https://www.youtube.com/watch?v=qvZGUFHWChY&list=PL9xmBV_5YoZNqDI8qfOZgzbqahCUmUEin&index=1)
- [Rotations](https://www.youtube.com/watch?v=95s3ndZRGbk&list=PL9xmBV_5YoZNqDI8qfOZgzbqahCUmUEin&index=2)