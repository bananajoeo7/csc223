class BTreeNode
  attr_accessor :keys, :children, :leaf

  def initialize(t, leaf = true)
    @t = t                  # Minimum degree
    @keys = []              # Array of keys
    @children = []          # Array of child pointers
    @leaf = leaf            # Boolean: is leaf or not
  end

  def insert_non_full(key)
    i = @keys.size - 1

    if @leaf
      @keys << nil
      while i >= 0 && key < @keys[i]
        @keys[i + 1] = @keys[i]
        i -= 1
      end
      @keys[i + 1] = key
    else
      while i >= 0 && key < @keys[i]
        i -= 1
      end
      i += 1

      if @children[i].keys.size == 2 * @t - 1
        split_child(i)
        if key > @keys[i]
          i += 1
        end
      end
      @children[i].insert_non_full(key)
    end
  end

  # ✅ Corrected split logic
  def split_child(i)
    y = @children[i]
    z = BTreeNode.new(@t, y.leaf)

    mid_key = y.keys[@t - 1]  # middle key to promote

    # Split keys and children
    z.keys = y.keys[@t..-1]
    y.keys = y.keys[0...@t - 1]

    unless y.leaf
      z.children = y.children[@t..-1]
      y.children = y.children[0...@t]
    end

    @children.insert(i + 1, z)
    @keys.insert(i, mid_key)
  end
end

class BTree
  def initialize(t = 3)
    @t = t
    @root = BTreeNode.new(t)
  end

  def insert(key)
    r = @root
    if r.keys.size == 2 * @t - 1
      s = BTreeNode.new(@t, false)
      s.children << r
      s.split_child(0)
      i = key < s.keys[0] ? 0 : 1
      s.children[i].insert_non_full(key)
      @root = s
    else
      r.insert_non_full(key)
    end
  end

  def print_tree
    print_btree(@root)
  end

  private

  def print_btree(node, prefix = "", is_last = true)
    return if node.nil?

    puts prefix + (is_last ? "└── " : "├── ") + node.keys.inspect
    new_prefix = prefix + (is_last ? "    " : "│   ")

    node.children.each_with_index do |child, index|
      is_last_child = (index == node.children.size - 1)
      print_btree(child, new_prefix, is_last_child)
    end
  end
end

# Example:

btree = BTree.new

[6, 9, 10, 12, 13, 14, 4, 2, 8, 23, 100, 28, 75, 47, 100, 90, 75, 22, 23, 45, 189, 200, 11, 12, 34, 56, 78, 89, 15, 16].each do |val|
  btree.insert(val)
end

btree.print_tree
