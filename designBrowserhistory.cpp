
class Node {
public:
    string url;
    Node* back;
    Node* forward;
    Node(string u) {
        url = u;
        back = NULL;
        forward = NULL;
    }
};

class BrowserHistory{
    Node* currpage;
public:
    BrowserHistory(string homepage) {
      currpage= new Node(homepage);
    }
    
    void visit(string url) {
        Node* newUrl= new Node(url);
        currpage->forward=newUrl;
        newUrl->back=currpage;
        currpage=newUrl;
    }
    
    string back(int steps) {
        int k=0;
        while(steps>k && currpage->back!=NULL){
            currpage=currpage->back;
            k++;
        }
        return currpage->url;
    }
    
    string forward(int steps) {
        int k=0;
        while(steps>k && currpage->forward!=NULL){
            currpage=currpage->forward;
            k++;
        }
        return currpage->url;
    }
};

/**
 * Your Node object will be instantiated and called as such:
 * Node* obj = new Node(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
