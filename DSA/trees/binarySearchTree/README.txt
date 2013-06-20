Binary Search Tree
==================
binary-search-tree property:
- Let x be a node in a binary search tree. If y is a node in the left subtree of
  x, then y:key <= x:key.
- If y is a node in the right subtree of x, then y:key >= x:key.

The binary-search-tree property allows us to print out all the keys in a binary
search tree in sorted order by a simple recursive algorithm, called an "inorder
tree walk". This algorithm is so named because it prints the key of the root of
a subtree between printing the values in its left subtree and printing those in
its right subtree.(INORDER: left -> parent -> right)

INORDER-TREE-WALK(x)
  if x != NIL
  INORDER-TREE-WALK(x:left)
  print x:key
  INORDER-TREE-WALK(x:right)

It takes Θ(n) time to walk an n-node binary search tree.

TREE-SEARCH(x, k)
  if x==NIL or k==x.key
    return x
  if k<x.key
    return TREE-SEARCH(x.left, k)
  else
    return TREE-SEARCH(x.right, k)

The nodes encountered during the recursion form a simple path downward from the
root of the tree, and thus the running time of TREE-SEARCH is O(h), where h is
the height of the tree. We can rewrite this procedure in an iterative fashion by
 “unrolling” the recursion into a while loop. On most computers, the iterative
version is more efficient.

ITERATIVE-TREE-SEARCH(x, k)
  while x != NIL and k != x.key
    if k < x.key
      x = x.left
    else x = x.right
  return x

TREE-MINIMUM(x)
  while x.left != NIL
    x = x.left
  return x

TREE-MAXIMUM(x)
  while x.right != NIL
    x = x.right
  return x

TREE-SUCCESSOR(x)
  if x.right != NIL
    return TREE-MINIMUM(x.right)
  y = x.p
  while y != NIL and x == y.right
    x = y
    y = y.p
  return y
Cases:
1. If the right subtree of node x is nonempty, then the successor of x is just
   the leftmost node in x’s right subtree, which we find in line 2 by calling
   TREE-MINIMUM(x.right).
2. If the right subtree of node x is empty and x has a successor y, then y is
   the lowest ancestor of x whose left child is also an ancestor of x.

TREE-PREDECESSOR(x)
  if x.left != NIL
    return TREE-MAXIMUM(x.left)
  y = x.p
  while y != NIL and x == y.left
    x = y
    y = y.p
  return y

The running time of TREE-SUCCESSOR/TREE-PREDECESSOR on a tree of height h is
O(h), since we either follow a simple path up the tree or follow a simple path
down the tree.


TREE-INSERT(T, z)
  y = NIL
  x = T.root
  while x != NIL  // search for z's parent
    y = x
    if z.key < x.key
      x = x.left
    else x = x.right
  z.p = y
  if y == NIL
    T.root = z    //tree T was empty
  elseif z.key < y.key
    y.left = z
  else y.right = z

Deletion:
1. If z has no children, then we simply remove it by modifying its parent to
   replace z with NIL as its child.
2. If z has just one child, then we elevate that child to take z’s position in
   the tree by modifying z’s parent to replace z by z’s child.
3. If z has two children, then we find z’s successor y—which must be in z’s
   right subtree - and have y take z’s position in the tree. The rest of z’s
   original right subtree becomes y’s new right subtree, and z’s left subtree
   becomes y’s new left subtree. This case is the tricky one because, as we
   shall see, it matters whether y is z’s right child.

TRANSPLANT(T, u, v)
  if u.p == NIL  // u is the root of T
    T.root = v
  elseif u == u.p.left
    u.p.left = v
  else u.p.right = v
  if v != NIL
    v.p = u.p
TRANSPLANT replaces the subtree rooted at node u with the subtree rooted at node
v, node u’s parent becomes node v’s parent, and u’s parent ends up having v as
its appropriate child.

TREE-DELETE(T, z)
  if z.left == NIL
    TRANSPLANT(T, z, z.right)
  elseif z.right == NIL
    TRANSPLANT(T, z, z.left)
  else y = TREE-MINIMUM(z.right)
    if y.p != z
      TRANSPLANT(T, y, y.right)
      y.right ＝z.right
      y.right.p = y
    TRANSPLANT(T, z, y)
    y.left = z.left
    y.left.p = y
TREE-DELETE runs in O(h) time on a tree of height h.
