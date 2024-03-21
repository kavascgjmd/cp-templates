class Node {
    public:
    Node * nodes[2];
    bool containsBit(int bit){
      return  ( nodes[bit] != NULL);
    }
    Node * getBit(int bit){
        return nodes[bit];
  }
     Node * putBit(int bit, Node * node){
         nodes[bit] = node;
         return node;
     }
};
class Trie{
public: 
  Node * root ;
  Trie(){
      root = new Node ();
  }
  void insert(int x){
       Node * node = root;
       for(int i = 31 ; i>=0 ; i--){
           int bit = ((x >>i) & 1);
           if(node->containsBit(bit)){
              node = node->getBit(bit);
           }
           else {
              Node * nnode = new Node();
              node = node->putBit(bit , nnode);
           }
       }
  }

  int getMax(int x){
      Node * node = root;
      int maxi = 0;
      for(int i = 31; i>=0; i--){
          int bit = ((x >> i)& 1);
          if(node->containsBit(!bit)){
                  maxi = (maxi | (1<<i));
                  node = node->getBit(!bit);
          }
          else {
                 node =  node->getBit(bit);
          }
      }
     return maxi;

  }

};
