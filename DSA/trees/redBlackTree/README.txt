Red-black trees are one of many search-tree schemes that are “balanced” in order
to guarantee that basic dynamic-set operations take O(lg n) time in the worst
case.

A red-black tree is a binary search tree with one extra bit of storage per node:
its color, which can be either RED or BLACK. By constraining the node colors on
any simple path from the root to a leaf, red-black trees ensure that no such
path is more than twice as long as any other, so that the tree is approximately
balanced.

A red-black tree is a binary tree that satisfies the following red-black
properties:
1. Every node is either red or black.
2. The root is black.
3. Every leaf (NIL) is black.
4. If a node is red, then both its children are black.
5. For each node, all simple paths from the node to descendant leaves
   contain the same number of black nodes.
