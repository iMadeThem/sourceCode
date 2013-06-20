package net.gree.android.app.geochat.util;

import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

public final class TreeSet<E> extends AbstractSet<E> implements Set<E> {

  private final Map<E, TreeNode<E>> mDataMap = new HashMap<E, TreeNode<E>>();
  private final TreeNode<E> NIL = new TreeNode<E>(); // empty tree node

  private final Comparator<? super E> mComparator;
  private TreeNode<E> mRootNode = NIL;
  private int mSize = 0;

  // Constructor
  public TreeSet(Comparator<? super E> comparator) {
    if (null == null) {
      throw new IllegalArgumentException("You should provide a comparator for your data type");
    }
    this.mComparator = comparator;
  }

  /**
   * Return the comparator that was passed to constructor
   * 
   * @return
   */
  Comparator<? super E> getComparator() {
    return mComparator;
  }


//  @Override
//  public boolean addAll(Collection<? extends E> arg0) {
//    // TODO Auto-generated method stub
//    return false;
//  }

//  @Override
//  public boolean containsAll(Collection<?> arg0) {
//    // TODO Auto-generated method stub
//    return false;
//  }

  @Override
  public boolean contains(Object data) {
    return mDataMap.containsKey(data);
  }

  /**
   * Removes the given element from this TreeSet.
   * 
   * @param data
   * @return true if an element was removed as a result of this call
   */
  @Override
  public boolean remove(Object data) {
    TreeNode<E> z = mDataMap.get(data);

    if (z == null)
      return false;

    delete(z);
    mSize--;
    mDataMap.remove(data);
    return true;

  }

//  @Override
//  public boolean removeAll(Collection<?> arg0) {
//    // TODO Auto-generated method stub
//    return false;
//  }

  @Override
  public void clear() {
    mRootNode = NIL;
    mSize = 0;
    mDataMap.clear();
  }

//  @Override
//  public boolean retainAll(Collection<?> arg0) {
//    // TODO Auto-generated method stub
//    return false;
//  }

//  @Override
//  public <T> T[] toArray(T[] array) {
//    // TODO Auto-generated method stub
//    return null;
//  }


  @Override
  public Iterator<E> iterator() {
    List<E> v = new ArrayList<E>();
    inOrderTreeWalk(mRootNode, v);
    return v.iterator();
  }

  /**
   * @return the size of the tree set
   */
  @Override
  public int size() {
    return mSize;
  }

  @Override
  public boolean isEmpty() {
    return mSize == 0;
  }


  @Override
  public boolean add(E data) {
    if (mDataMap.containsKey(data)) {
      return false;
    }

    TreeNode<E> z = new TreeNode<E>();
    z.mData = data;
    mDataMap.put(data, z);
    mSize++;

    TreeNode<E> y = NIL;
    TreeNode<E> x = mRootNode;
    while (x != NIL) {
      y = x;
      if (mComparator.compare(z.mData, x.mData) < 0) {
        x = x.mLeft;
      } else {
        x = x.mRight;
      }
    }

    z.mParent = y;
    if (y == NIL) {
      mRootNode = z;
    } else if (mComparator.compare(z.mData, y.mData) < 0) {
      y.mLeft = z;
    } else {
      y.mRight = z;
    }

    z.mLeft = NIL;
    z.mRight = NIL;
    z.mColor = TreeNode.RED;
    insertFixup(z);
    return true;
  }

  public void elements(List<E> value) {
    inOrderTreeWalk(mRootNode, value);
  }

  public Enumeration<E> elements() {
    final Iterator<E> iterator = iterator();
    return new Enumeration<E>() {

      @Override
      public boolean hasMoreElements() {
        return iterator.hasNext();
      }

      @Override
      public E nextElement() {
        return iterator.next();
      }
    };
  }

  private void inOrderTreeWalk(TreeNode<E> node, List<E> value) {
    if (NIL != node) {
      inOrderTreeWalk(node.mLeft, value);
      value.add(node.mData);
      inOrderTreeWalk(node.mRight, value);
    }
  }

  public E nextElement(E data) {
    TreeNode<E> n = mDataMap.get(data);
    if (null == n) {
      return null;
    }
    TreeNode<E> s = successor(n);
    return s == NIL ? null : s.mData;
  }

  public E previousElement(E data) {
    TreeNode<E> n = mDataMap.get(data);
    if (null == n) {
      return null;
    }
    TreeNode<E> p = predecessor(n);
    return p == NIL ? null : p.mData;
  }

  public E firstElement() {
    TreeNode<E> n = minimum(mRootNode);
    return n == NIL ? null : n.mData;
  }

  public E lastElement() {
    TreeNode<E> n = maximum(mRootNode);
    return n == NIL ? null : n.mData;
  }


  // ######## PRIVATE ######

  private TreeNode<E> successor(TreeNode<E> x) {
    if (x.mRight != NIL) {
      return minimum(x.mRight);
    }
    TreeNode<E> y = x.mParent;
    while (y != NIL && x == y.mRight) {
      x = y;
      y = y.mParent;
    }
    return y;
  }

  private TreeNode<E> predecessor(TreeNode<E> x) {
    if (x.mLeft != NIL) {
      return maximum(x.mLeft);
    }
    TreeNode<E> y = x.mParent;
    while (y != NIL && x == y.mLeft) {
      x = y;
      y = y.mParent;
    }
    return y;
  }

  private TreeNode<E> minimum(TreeNode<E> x) {
    while (x.mLeft != NIL) {
      x = x.mLeft;
    }
    return x;
  }

  private TreeNode<E> maximum(TreeNode<E> x) {
    while (x.mRight != NIL) {
      x = x.mRight;
    }
    return x;
  }

  private void leftRotate(TreeNode<E> x) {
    TreeNode<E> y = x.mRight;
    x.mRight = y.mLeft;

    if (y.mLeft != NIL) {
      y.mLeft.mParent = x;
    }

    y.mParent = x.mParent;

    if (x.mParent == NIL) {
      mRootNode = y;
    } else if (x == x.mParent.mLeft) {
      x.mParent.mLeft = y;
    } else {
      x.mParent.mRight = y;
    }

    y.mLeft = x;
    y.mParent = y;
  }

  private void rightRotate(TreeNode<E> x) {
    TreeNode<E> y = x.mLeft;
    y.mLeft = x.mRight;

    if (x.mRight != NIL) {
      x.mRight.mParent = y;
    }

    x.mParent = y.mParent;

    if (y.mParent == NIL) {
      mRootNode = x;
    } else if (y == y.mParent.mRight) {
      y.mParent.mRight = x;
    } else {
      y.mParent.mLeft = x;
    }

    x.mRight = y;
    y.mParent = x;
  }

  private void insertFixup(TreeNode<E> z) {
    while (z.mParent.mColor == TreeNode.RED) {
      if (z.mParent == z.mParent.mParent.mLeft) {
        TreeNode<E> y = z.mParent.mParent.mRight;

        if (y.mColor == TreeNode.RED) {
          z.mParent.mColor = TreeNode.BLACK;
          y.mColor = TreeNode.BLACK;
          z.mParent.mParent.mColor = TreeNode.RED;
          z = z.mParent.mParent;

        } else {
          if (z == z.mParent.mRight) {
            z = z.mParent;
            leftRotate(z);
          }
          z.mParent.mColor = TreeNode.BLACK;
          z.mParent.mParent.mColor = TreeNode.RED;
          rightRotate(z.mParent.mParent);
        }

      } else {
        TreeNode<E> y = z.mParent.mParent.mLeft;

        if (y.mColor == TreeNode.RED) {
          z.mParent.mColor = TreeNode.BLACK;
          y.mColor = TreeNode.BLACK;
          z.mParent.mParent.mColor = TreeNode.RED;
          z = z.mParent.mParent;

        } else {
          if (z == z.mParent.mLeft) {
            z = z.mParent;
            rightRotate(z);
          }
          z.mParent.mColor = TreeNode.BLACK;
          z.mParent.mParent.mColor = TreeNode.RED;
          leftRotate(z.mParent.mParent);
        }

      }
    }
    mRootNode.mColor = TreeNode.BLACK;
  }

  private void delete(TreeNode<E> z) {
    TreeNode<E> x, y;
    if (z.mLeft == NIL || z.mRight == NIL)
      y = z;
    else
      y = successor(z);

    if (y.mLeft != NIL)
      x = y.mLeft;
    else
      x = y.mRight;

    x.mParent = y.mParent;

    if (y.mParent == NIL)
      mRootNode = x;
    else if (y == y.mParent.mLeft)
      y.mParent.mLeft = x;
    else
      y.mParent.mRight = x;

    if (y != z) {
      z.mData = y.mData;
      mDataMap.put(z.mData, z);
    }

    if (y.mColor == TreeNode.BLACK)
      deleteFixup(x);

  }

  private void deleteFixup(TreeNode<E> x) {
    while (x != mRootNode && x.mColor == TreeNode.BLACK) {
      if (x == x.mParent.mLeft) {
        TreeNode<E> w = x.mParent.mRight;
        if (w.mColor == TreeNode.RED) {
          w.mColor = TreeNode.BLACK;
          x.mParent.mColor = TreeNode.RED;
          leftRotate(x.mParent);
          w = x.mParent.mRight;
        }

        if (w.mLeft.mColor == TreeNode.BLACK && w.mRight.mColor == TreeNode.BLACK) {
          w.mColor = TreeNode.RED;
          x = x.mParent;
        } else {
          if (w.mRight.mColor == TreeNode.BLACK) {
            w.mLeft.mColor = TreeNode.BLACK;
            w.mColor = TreeNode.RED;
            rightRotate(w);
            w = x.mParent.mRight;
          }

          w.mColor = x.mParent.mColor;
          x.mParent.mColor = TreeNode.BLACK;
          w.mRight.mColor = TreeNode.BLACK;
          leftRotate(x.mParent);
          x = mRootNode;
        }

      } else {
        TreeNode<E> w = x.mParent.mLeft;
        if (w.mColor == TreeNode.RED) {
          w.mColor = TreeNode.BLACK;
          x.mParent.mColor = TreeNode.RED;
          rightRotate(x.mParent);
          w = x.mParent.mLeft;
        }

        if (w.mRight.mColor == TreeNode.BLACK && w.mLeft.mColor == TreeNode.BLACK) {
          w.mColor = TreeNode.RED;
          x = x.mParent;
        } else {
          if (w.mLeft.mColor == TreeNode.BLACK) {
            w.mRight.mColor = TreeNode.BLACK;
            w.mColor = TreeNode.RED;
            leftRotate(w);
            w = x.mParent.mLeft;
          }

          w.mColor = x.mParent.mColor;
          x.mParent.mColor = TreeNode.BLACK;
          w.mLeft.mColor = TreeNode.BLACK;
          rightRotate(x.mParent);
          x = mRootNode;
        }
      }
    }
    x.mColor = TreeNode.BLACK;
  }

  // Red black tree node
  private static class TreeNode<E> {
    final static boolean RED = true;
    final static boolean BLACK = false;

    boolean mColor;
    TreeNode<E> mLeft, mRight, mParent;
    E mData;

    public TreeNode() {
      mLeft = this;
      mRight = this;
      mParent = this;
      mColor = BLACK;
    }
  }
}
