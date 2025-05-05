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

  def visualize(node = @root_node)
    lines = build_lines(node)
    lines.each { |line| puts line }
    puts "\n\n"
  end
  
  def build_lines(node)
    return [""] if node.nil?
  
    label = node.value.to_s
  
    left_lines = build_lines(node.left)
    right_lines = build_lines(node.right)
  
    left_width  = left_lines.first&.length || 0
    right_width = right_lines.first&.length || 0
  
    # Center the label
    label_line = " " * left_width + label + " " * right_width
  
    # Create branch line
    branch_line = ""
    branch_line += " " * (left_width - 1) + "/" if node.left
    branch_line += " " * (label.length - 2)
    branch_line += "\\" if node.right
    branch_line = branch_line.ljust(left_width + label.length + right_width)
  
    # Pad shorter subtree
    max_height = [left_lines.length, right_lines.length].max
    left_lines += [" " * left_width] * (max_height - left_lines.length)
    right_lines += [" " * right_width] * (max_height - right_lines.length)
  
    # Combine child lines
    child_lines = left_lines.zip(right_lines).map do |l, r|
      l + " " * label.length + r
    end
  
    [label_line, branch_line] + child_lines
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

tree = BinaryTree.new
[6, 9, 4, 2, 8, 23, 100, 28, 75, 47].each {|val| tree.insert(val)}
tree.visualize
tree. delete(23)
tree.visualize