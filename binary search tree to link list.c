// binary search tree to link list which is increasing in oredder
public Node bstToList(Node current, Node lastPrintedPointer){
        if(current.getRight() != null){
        	lastPrintedPointer = bstToList(current.getRight(), lastPrintedPointer);
        }
         current.setRight(lastPrintedPointer);
         lastPrintedPointer = current;
        if(current.getLeft()!=null)
                lastPrintedPointer = bstToList(current.getLeft(), lastPrintedPointer);
        return lastPrintedPointer;
}